#include "mainwindow.h"

#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

#include "../gif/gif.h"
// #include "glwidget.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  //    ui->x_value->setText(QString::number(ui->x_slider->value()));
  if (ui->GLwidget->reading_settings()) {
    ui->GLwidget->info = {0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 5, 1};
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButtonpath_clicked() {
  ui->GLwidget->fin();
  //    setlocale(LC_ALL, "C");
  QString filter = "file(*.obj)";
  QString path = QFileDialog::getOpenFileName(this, "Open a file",
                                              QDir::homePath(), filter);
  if (path == "") {
    QMessageBox::information(this, "title", "Вы не выбрали файл");
  }
  ui->path_line->setText(path);
  QByteArray bytes = path.toLocal8Bit();
  char *cstr = bytes.data();

  ui->GLwidget->start_information(cstr);

  number_of_vert = ui->GLwidget->information.count_veretex;
  number_of_rebra = ui->GLwidget->information.count_index / 2;

  QString new_label;
  new_label = QString::number(number_of_vert, 'g', 15);
  ui->number_vert->setText(new_label);
  QString new_label1;
  new_label1 = QString::number(number_of_rebra, 'g', 15);
  ui->number_rebra->setText(new_label1);
}

void MainWindow::on_type_of_projection_activated(int index) {
  if (index == 0) {
    ui->GLwidget->info.projection_type = 0;
  } else {
    ui->GLwidget->info.projection_type = 1;
  }
  ui->GLwidget->writing_settings();
  ui->GLwidget->update();
}

void MainWindow::on_background_color_button_clicked() {
  QColor color = QColorDialog::getColor(Qt::black, this, "Choose a color");
  red = color.redF();
  green = color.greenF();
  blue = color.blueF();
  if (color.isValid()) {
    ui->GLwidget->colors_RGB(red, green, blue, 0);
  }
}

void MainWindow::on_color_of_vert_button_clicked() {
  QColor color = QColorDialog::getColor(Qt::red, this, "Choose a color");
  red = color.redF();
  green = color.greenF();
  blue = color.blueF();
  if (color.isValid()) {
    ui->GLwidget->colors_RGB(red, green, blue, 2);
  }
}

void MainWindow::on_color_of_rebra_button_clicked() {
  QColor color = QColorDialog::getColor(Qt::white, this, "Choose a color");
  red = color.redF();
  green = color.greenF();
  blue = color.blueF();
  if (color.isValid()) {
    ui->GLwidget->colors_RGB(red, green, blue, 1);
  }
}

void MainWindow::on_thickness_of_rebra_valueChanged(double arg1) {
  ui->GLwidget->info.thickness = arg1;
  ui->GLwidget->writing_settings();
  ui->GLwidget->update();
}

void MainWindow::on_type_of_rebra_activated(int index) {
  if (index == 0) {
    ui->GLwidget->info.line_type = 0;
  } else {
    ui->GLwidget->info.line_type = 1;
  }
  ui->GLwidget->writing_settings();
  ui->GLwidget->update();
}

void MainWindow::on_size_of_vert_valueChanged(int arg1) {
  ui->GLwidget->info.vert_size = arg1;
  ui->GLwidget->writing_settings();
  ui->GLwidget->update();
}

void MainWindow::on_type_of_vert_activated(int index) {
  if (index == 0) {
    ui->GLwidget->info.vert_type = 0;
  } else if (index == 1) {
    ui->GLwidget->info.vert_type = 1;
  } else {
    ui->GLwidget->info.vert_type = 2;
  }
  ui->GLwidget->writing_settings();
  ui->GLwidget->update();
}

void MainWindow::on_x_value_valueChanged(double arg1) {
  QString s_move_x = ui->label_x->text();
  double value_move_x = s_move_x.toDouble();

  arg1 = arg1 - value_move_x;
  ui->GLwidget->moveObjX(arg1);

  QString s = ui->x_value->text();
  ui->label_x->setText(s);
}

void MainWindow::on_y_value_valueChanged(double arg1) {
  QString s_move_x = ui->label_y->text();
  double value_move_x = s_move_x.toDouble();

  arg1 = arg1 - value_move_x;
  ui->GLwidget->moveObjY(arg1);

  QString s = ui->y_value->text();
  ui->label_y->setText(s);
}

void MainWindow::on_z_value_valueChanged(double arg1) {
  QString s_move_x = ui->label_z->text();
  double value_move_x = s_move_x.toDouble();

  arg1 = arg1 - value_move_x;
  ui->GLwidget->moveObjZ(arg1);

  QString s = ui->z_value->text();
  ui->label_z->setText(s);
}

void MainWindow::on_x_value_r_valueChanged(double arg1) {
  QString s_move_x = ui->label_x_r->text();
  double value_move_x = s_move_x.toDouble();

  arg1 = arg1 - value_move_x;
  ui->GLwidget->setXRotation(arg1);

  QString s = ui->x_value_r->text();
  ui->label_x_r->setText(s);
}

void MainWindow::on_y_value_r_valueChanged(double arg1) {
  QString s_move_x = ui->label_y_r->text();
  double value_move_x = s_move_x.toDouble();

  arg1 = arg1 - value_move_x;
  ui->GLwidget->setYRotation(arg1);

  QString s = ui->y_value_r->text();
  ui->label_y_r->setText(s);
}

void MainWindow::on_z_value_r_valueChanged(double arg1) {
  QString s_move_x = ui->label_z_r->text();
  double value_move_x = s_move_x.toDouble();

  arg1 = arg1 - value_move_x;
  ui->GLwidget->setZRotation(arg1);

  QString s = ui->z_value_r->text();
  ui->label_z_r->setText(s);
}

void MainWindow::on_scale_value_valueChanged(double arg1) {
  QString s_move_x = ui->scale_label->text();
  double value_move_x = s_move_x.toDouble();

  arg1 = arg1 - value_move_x;
  ui->GLwidget->zoomObj(arg1);

  QString s = ui->scale_value->text();
  ui->scale_label->setText(s);
}

// -----------------------------------------------//

// void MainWindow::makeScreenshot() {
//   QPushButton *btn = (QPushButton *)sender();
//   QString butVal = btn->text();

//   QDir *pathDir = new QDir();
//   pathDir->mkdir(pathProject);
//   pathDir->mkdir(pathProject + "/screenshots");
//   // qDebug() << pathProject;
//   QDateTime dateTime = dateTime.currentDateTime();
//   QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");

//   if (QString::compare(butVal, "bmp", Qt::CaseInsensitive) == 0) {
//     ui->btn_screen_bmp->setEnabled(false);
//     ui->GLwidget->grab().save(pathProject + "screenshots/" + currentDateTime
//     +
//                               ".bmp");
//     ui->btn_screen_bmp->setEnabled(true);
//   } else if (QString::compare(butVal, "jpeg", Qt::CaseInsensitive) == 0) {
//     ui->btn_screen_jpg->setEnabled(false);
//     ui->GLwidget->grab().save(pathProject + "screenshots/" + currentDateTime
//     +
//                               ".jpg");
//     ui->btn_screen_jpg->setEnabled(true);
//   } else if (QString::compare(butVal, "gif", Qt::CaseInsensitive) == 0) {
//     ui->btn_screen_gif->setEnabled(false);
//     pathDir->mkdir(pathProject + "/screenshots/gif_obj/");
//     startTime = 0, tmpTime = 1000 / GifFps;
//     timer = new QTimer(this);
//     connect(timer, SIGNAL(timeout()), this, SLOT(oneGif()));
//     timer->start(1000 / GifFps);
//   }
// }

// void MainWindow::connectSetUp() {
//  connect(ui->btn_screen_bmp, SIGNAL(pressed()), (this),
//     SLOT(makeScreenshot()));
//  connect(ui->btn_screen_jpg, SIGNAL(pressed()), (this),
//           SLOT(makeScreenshot()));
//   connect(ui->btn_screen_gif, SIGNAL(pressed()), (this),
//      SLOT(makeScreenshot()));
//}

void MainWindow::on_btn_screen_bmp_clicked() {
  QDir *pathDir = new QDir();
  pathDir->mkdir(pathProject);
  pathDir->mkdir(pathProject + "/screenshots");
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
  ui->btn_screen_bmp->setEnabled(false);
  ui->GLwidget->grab().save(pathProject + "screenshots/" + currentDateTime +
                            ".bmp");
  ui->btn_screen_bmp->setEnabled(true);
}

void MainWindow::on_btn_screen_jpg_clicked() {
  QDir *pathDir = new QDir();
  pathDir->mkdir(pathProject);
  pathDir->mkdir(pathProject + "/screenshots");
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
  ui->btn_screen_jpg->setEnabled(false);
  ui->GLwidget->grab().save(pathProject + "screenshots/" + currentDateTime +
                            ".jpg");
  ui->btn_screen_bmp->setEnabled(true);
}

void MainWindow::on_btn_screen_gif_clicked() {
  QDir *pathDir = new QDir();
  pathDir->mkdir(pathProject);
  pathDir->mkdir(pathProject + "/screenshots");
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
  ui->btn_screen_gif->setEnabled(false);
  pathDir->mkdir(pathProject + "/screenshots/gif_obj/");
  startTime = 0, tmpTime = 1000 / GifFps;
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(oneGif()));
  timer->start(1000 / GifFps);
}

void MainWindow::oneGif() {
  if (startTime == tmpTime) {
    ui->GLwidget->grab()
        .scaled(640, 480, Qt::IgnoreAspectRatio)
        .save(pathProject + "/screenshots/gif_obj/" + QString::number(counter) +
              ".bmp");
    counter++;
    tmpTime += 1000 / GifFps;
  }
  if (startTime == 1000 * GifLength) {
    createGif();
    timer->stop();
    counter = 1;
  }
  startTime += 1000 / GifFps;
}

void MainWindow::createGif() {
  QDir pathFile;
  QDateTime dateTime = dateTime.currentDateTime();
  QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");
  QString gif_name = pathProject + "/screenshots/" + currentDateTime + ".gif";
  QByteArray ga = gif_name.toLocal8Bit();
  GifWriter writer = {};
  int err = 0;
  if (GifBegin(&writer, ga.data(), 640, 480, 10, 8, false)) {
    for (int i = 1; i <= 50; i++) {
      if (err == 1) {
        break;
      }
      QImage img(pathProject + "/screenshots/gif_obj/" + QString::number(i) +
                 ".bmp");
      if (!img.isNull()) {
        if (GifWriteFrame(&writer,
                          img.convertToFormat(QImage::Format_Indexed8)
                              .convertToFormat(QImage::Format_RGBA8888)
                              .constBits(),
                          640, 480, 10, 8, false)) {
        } else {
          QMessageBox::critical(0, "Error", "Gif file can not be created! 1");
          err = 1;
        }
      } else {
        QMessageBox::critical(0, "Error", "Gif file can not be created! 2");
        err = 1;
      }
    }
    if (err == 0) {
      GifEnd(&writer);
    }
  } else {
    err = 1;
    QMessageBox::critical(0, "Error", "Gif file can not be created! 3");
  }

  if (err == 1) {
    if (QFile::exists(gif_name)) {
      QFile::remove(gif_name);
    }
  }

  pathFile.setPath(pathProject + "/screenshots/gif_obj/");
  pathFile.removeRecursively();
  ui->btn_screen_gif->setEnabled(true);
}
