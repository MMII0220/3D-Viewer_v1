#include "glwidget.h"

#include <QDebug>
#include <QMessageBox>
#include <QtOpenGL>
#include <QtWidgets>

#include "mainwindow.h"

extern "C" {
#include "../l.h"
}

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget{parent} {
  setGeometry(400, 200, 800, 600);
}

void GLWidget::initializeGL() { glEnable(GL_DEPTH_TEST); }

void GLWidget::paintGL() {
  glClearColor(info.red, info.green, info.blue, 0);
  //    glLineStipple(1, 0x1C47);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  if (info.projection_type) {
    glOrtho(-2, 2, -2, 2, -100, 100);
  } else {
    glFrustum(-1, 1, -1, 1, -100, 100);
  }
  glRotatef(xRot, 1, 0, 0);
  glRotatef(yRot, 0, 1, 0);
  glScalef(1, 1, 1);
  draw();
}

void GLWidget::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void GLWidget::draw() {
  glLineWidth(info.thickness);
  if (info.line_type) {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x3333);
  }
  if (info.vert_type) {
    glPointSize(info.vert_size);
    if (info.vert_type == 2) {
      glEnable(GL_POINT_SMOOTH);
    }
  }
  glVertexPointer(3, GL_DOUBLE, 0, information.veretex);
  glEnableClientState(GL_VERTEX_ARRAY);
  if (info.vert_type) {
    glColor3d(info.redv, info.greenv, info.bluev);
    glDrawArrays(GL_POINTS, 0, information.count_veretex);
  }
  glColor3d(info.redl, info.greenl, info.bluel);

  glDrawElements(GL_LINES, information.count_index, GL_UNSIGNED_INT,
                 information.index);

  glDisableClientState(GL_VERTEX_ARRAY);
  glDisable(GL_POINT_SMOOTH);
  glDisable(GL_LINE_STIPPLE);
}

void GLWidget::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

void GLWidget::mouseMoveEvent(QMouseEvent *mo) {
  xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
  yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
  update();
}

void GLWidget::start_information(char *str) {
  start(&information, str);
  update();
}

void GLWidget::fin() {
  end(&information);
  information = {0, 0, 0, 0};
}

void GLWidget::writing_settings() { writing_to_file(&info); }

int GLWidget::reading_settings() {
  int a = 1;
  if (read_file(&info)) {
    a = 0;
    update();
  }
  return a;
}

void GLWidget::colors_RGB(float red, float green, float blue, int flag) {
  if (flag == 0) {
    this->info.red = red;
    this->info.green = green;
    this->info.blue = blue;
    writing_to_file(&info);
  } else if (flag == 1) {
    this->info.redl = red;
    this->info.greenl = green;
    this->info.bluel = blue;
    writing_to_file(&info);
  } else {
    this->info.redv = red;
    this->info.greenv = green;
    this->info.bluev = blue;
    writing_to_file(&info);
  }
  update();
}

void GLWidget::moveObjX(double val) {
  move_x(&information, val);
  update();
}

void GLWidget::moveObjY(double val) {
  move_y(&information, val);
  update();
}

void GLWidget::moveObjZ(double val) {
  move_z(&information, val);
  update();
}

void GLWidget::setXRotation(double angle) {
  rotate_x(&information, angle / 57.29578);
  update();
}

void GLWidget::setYRotation(double angle) {
  rotate_y(&information, angle / 57.29578);
  update();
}

void GLWidget::setZRotation(double angle) {
  rotate_z(&information, angle / 57.29578);
  update();
}

void GLWidget::zoomObj(double scale) {
  float zoomnum = 1.0 + scale * 0.01f;
  if (zoomnum < 0.1f) {
    zoomnum = 0.1f;
  }
  rescale_obj(&information, zoomnum);
  update();
}
