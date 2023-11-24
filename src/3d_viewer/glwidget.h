#ifndef GLWIDGET_H
#define GLWIDGET_H
#define GL_SILENCE_DEPRECATION

#include <QMessageBox>
#include <QMouseEvent>
#include <QObject>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QTimer>
#include <QWidget>
#include <QtOpenGL>

#include "mainwindow.h"

extern "C" {
#include "../l.h"
}

class GLWidget : public QOpenGLWidget {
  Q_OBJECT

 public:
  GLWidget(QWidget *parent = nullptr);
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  void initializeGL() override;
  void paintGL() override;
  void resizeGL(int width, int height) override;
  obj information = {0, 0, 0, 0};
  void draw();

  void moveObjX(double val);
  void setXRotation(double angle);
  void setYRotation(double angle);
  void setZRotation(double angle);
  void zoomObj(double scale);
  void moveObjY(double val);
  void moveObjZ(double val);

  void start_information(char *str);
  void writing_settings();
  int reading_settings();
  void fin();
  void colors_RGB(float red, float green, float blue, int flag);
  set info = {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 5, 1};
  float xRot, yRot, zRot;

 private:
  QPoint mPos;
  QTimer tmr;
};

#endif  // GLWIDGET_H
