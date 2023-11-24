#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColor>
#include <QColorDialog>
#include <QDir>
#include <QImage>
#include <QMainWindow>
#include <QPainter>
#include <QSettings>
#include <QTimer>
#include <QVector>

extern "C" {
#include "../l.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  float red = 0, green = 0, blue = 0;
  int number_of_vert = 0;
  int number_of_rebra = 0;
  obj information = {0, 0, 0, 0};

 private:
  Ui::MainWindow *ui;
  QList<QImage> jiff;
  int counter_im;
  int screenshotcounter;
  QString pathProject = QDir::homePath() + "/3dViewer1/";
  QTimer *timer;
  int startTime, tmpTime;
  const int GifFps = 10, GifLength = 5;
  int counter = 1;

 private slots:
  void on_pushButtonpath_clicked();
  void on_type_of_projection_activated(int index);
  void on_background_color_button_clicked();
  void on_color_of_vert_button_clicked();
  void on_color_of_rebra_button_clicked();
  void on_thickness_of_rebra_valueChanged(double arg1);
  void on_type_of_rebra_activated(int index);
  void on_size_of_vert_valueChanged(int arg1);
  void on_type_of_vert_activated(int index);
  void on_x_value_valueChanged(double arg1);
  void on_y_value_valueChanged(double arg1);
  void on_z_value_valueChanged(double arg1);
  void on_x_value_r_valueChanged(double arg1);
  void on_y_value_r_valueChanged(double arg1);
  void on_z_value_r_valueChanged(double arg1);
  void on_scale_value_valueChanged(double arg1);
  // void makeScreenshot();
  void oneGif();
  void createGif();
  // void connectSetUp();
  void on_btn_screen_bmp_clicked();
  void on_btn_screen_jpg_clicked();
  void on_btn_screen_gif_clicked();
};
#endif  // MAINWINDOW_H
