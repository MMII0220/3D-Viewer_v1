/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <glwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    GLWidget *GLwidget;
    QPushButton *pushButtonpath;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *path_line;
    QLabel *number_vert;
    QLabel *number_rebra;
    QLabel *label_13;
    QComboBox *type_of_projection;
    QPushButton *background_color_button;
    QLabel *label_14;
    QComboBox *type_of_rebra;
    QPushButton *color_of_rebra_button;
    QLabel *label_15;
    QDoubleSpinBox *thickness_of_rebra;
    QComboBox *type_of_vert;
    QPushButton *color_of_vert_button;
    QLabel *label_17;
    QLabel *label_18;
    QSpinBox *size_of_vert;
    QPushButton *btn_screen_bmp;
    QPushButton *btn_screen_gif;
    QDoubleSpinBox *x_value;
    QDoubleSpinBox *y_value;
    QDoubleSpinBox *z_value;
    QDoubleSpinBox *x_value_r;
    QDoubleSpinBox *y_value_r;
    QDoubleSpinBox *z_value_r;
    QDoubleSpinBox *scale_value;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QLabel *label_x;
    QLabel *label_z;
    QLabel *label_y;
    QLabel *label_x_r;
    QLabel *label_z_r;
    QLabel *label_y_r;
    QLabel *scale_label;
    QPushButton *btn_screen_jpg;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(773, 694);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        GLwidget = new GLWidget(centralwidget);
        GLwidget->setObjectName(QString::fromUtf8("GLwidget"));
        GLwidget->setGeometry(QRect(20, 10, 451, 461));
        pushButtonpath = new QPushButton(centralwidget);
        pushButtonpath->setObjectName(QString::fromUtf8("pushButtonpath"));
        pushButtonpath->setGeometry(QRect(480, 10, 281, 71));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 100, 67, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(590, 280, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(580, 440, 67, 17));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 480, 141, 66));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout->addWidget(label_11);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout->addWidget(label_12);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(190, 480, 241, 66));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        path_line = new QLabel(layoutWidget1);
        path_line->setObjectName(QString::fromUtf8("path_line"));
        path_line->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));

        verticalLayout_2->addWidget(path_line);

        number_vert = new QLabel(layoutWidget1);
        number_vert->setObjectName(QString::fromUtf8("number_vert"));
        number_vert->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));

        verticalLayout_2->addWidget(number_vert);

        number_rebra = new QLabel(layoutWidget1);
        number_rebra->setObjectName(QString::fromUtf8("number_rebra"));
        number_rebra->setStyleSheet(QString::fromUtf8("background-color: rgb(222, 221, 218);"));

        verticalLayout_2->addWidget(number_rebra);

        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(480, 520, 131, 17));
        type_of_projection = new QComboBox(centralwidget);
        type_of_projection->addItem(QString());
        type_of_projection->addItem(QString());
        type_of_projection->setObjectName(QString::fromUtf8("type_of_projection"));
        type_of_projection->setGeometry(QRect(610, 520, 111, 25));
        type_of_projection->setEditable(false);
        background_color_button = new QPushButton(centralwidget);
        background_color_button->setObjectName(QString::fromUtf8("background_color_button"));
        background_color_button->setGeometry(QRect(320, 650, 141, 25));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(20, 560, 111, 17));
        type_of_rebra = new QComboBox(centralwidget);
        type_of_rebra->addItem(QString());
        type_of_rebra->addItem(QString());
        type_of_rebra->setObjectName(QString::fromUtf8("type_of_rebra"));
        type_of_rebra->setGeometry(QRect(150, 560, 111, 25));
        color_of_rebra_button = new QPushButton(centralwidget);
        color_of_rebra_button->setObjectName(QString::fromUtf8("color_of_rebra_button"));
        color_of_rebra_button->setGeometry(QRect(20, 650, 121, 25));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(20, 600, 121, 17));
        thickness_of_rebra = new QDoubleSpinBox(centralwidget);
        thickness_of_rebra->setObjectName(QString::fromUtf8("thickness_of_rebra"));
        thickness_of_rebra->setGeometry(QRect(160, 600, 65, 26));
        type_of_vert = new QComboBox(centralwidget);
        type_of_vert->addItem(QString());
        type_of_vert->addItem(QString());
        type_of_vert->addItem(QString());
        type_of_vert->setObjectName(QString::fromUtf8("type_of_vert"));
        type_of_vert->setGeometry(QRect(430, 560, 111, 25));
        color_of_vert_button = new QPushButton(centralwidget);
        color_of_vert_button->setObjectName(QString::fromUtf8("color_of_vert_button"));
        color_of_vert_button->setGeometry(QRect(170, 650, 121, 25));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(290, 560, 111, 17));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(290, 610, 141, 17));
        size_of_vert = new QSpinBox(centralwidget);
        size_of_vert->setObjectName(QString::fromUtf8("size_of_vert"));
        size_of_vert->setGeometry(QRect(430, 600, 44, 26));
        btn_screen_bmp = new QPushButton(centralwidget);
        btn_screen_bmp->setObjectName(QString::fromUtf8("btn_screen_bmp"));
        btn_screen_bmp->setGeometry(QRect(610, 600, 101, 41));
        btn_screen_gif = new QPushButton(centralwidget);
        btn_screen_gif->setObjectName(QString::fromUtf8("btn_screen_gif"));
        btn_screen_gif->setGeometry(QRect(610, 560, 101, 41));
        x_value = new QDoubleSpinBox(centralwidget);
        x_value->setObjectName(QString::fromUtf8("x_value"));
        x_value->setGeometry(QRect(520, 140, 61, 26));
        x_value->setMinimum(-1.000000000000000);
        x_value->setMaximum(1.000000000000000);
        x_value->setSingleStep(0.020000000000000);
        y_value = new QDoubleSpinBox(centralwidget);
        y_value->setObjectName(QString::fromUtf8("y_value"));
        y_value->setGeometry(QRect(520, 180, 61, 26));
        y_value->setMinimum(-1.000000000000000);
        y_value->setMaximum(1.000000000000000);
        y_value->setSingleStep(0.020000000000000);
        z_value = new QDoubleSpinBox(centralwidget);
        z_value->setObjectName(QString::fromUtf8("z_value"));
        z_value->setGeometry(QRect(520, 220, 61, 26));
        z_value->setMinimum(-1.000000000000000);
        z_value->setMaximum(1.000000000000000);
        z_value->setSingleStep(0.020000000000000);
        x_value_r = new QDoubleSpinBox(centralwidget);
        x_value_r->setObjectName(QString::fromUtf8("x_value_r"));
        x_value_r->setGeometry(QRect(520, 310, 61, 26));
        x_value_r->setMinimum(-100.000000000000000);
        x_value_r->setMaximum(100.000000000000000);
        x_value_r->setSingleStep(1.000000000000000);
        y_value_r = new QDoubleSpinBox(centralwidget);
        y_value_r->setObjectName(QString::fromUtf8("y_value_r"));
        y_value_r->setGeometry(QRect(520, 350, 61, 26));
        y_value_r->setMinimum(-100.000000000000000);
        y_value_r->setMaximum(100.000000000000000);
        y_value_r->setSingleStep(1.000000000000000);
        z_value_r = new QDoubleSpinBox(centralwidget);
        z_value_r->setObjectName(QString::fromUtf8("z_value_r"));
        z_value_r->setGeometry(QRect(520, 390, 61, 26));
        z_value_r->setMinimum(-100.000000000000000);
        z_value_r->setMaximum(100.000000000000000);
        z_value_r->setSingleStep(1.000000000000000);
        scale_value = new QDoubleSpinBox(centralwidget);
        scale_value->setObjectName(QString::fromUtf8("scale_value"));
        scale_value->setGeometry(QRect(520, 470, 61, 26));
        scale_value->setMinimum(-100.000000000000000);
        scale_value->setMaximum(100.000000000000000);
        scale_value->setSingleStep(1.000000000000000);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(504, 143, 16, 17));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(501, 181, 16, 17));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(501, 221, 16, 17));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(501, 311, 16, 17));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(501, 351, 16, 17));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(501, 391, 16, 17));
        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(800, 100, 30, 111));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_x = new QLabel(layoutWidget2);
        label_x->setObjectName(QString::fromUtf8("label_x"));

        gridLayout->addWidget(label_x, 1, 1, 1, 1);

        label_z = new QLabel(layoutWidget2);
        label_z->setObjectName(QString::fromUtf8("label_z"));

        gridLayout->addWidget(label_z, 2, 1, 1, 1);

        label_y = new QLabel(layoutWidget2);
        label_y->setObjectName(QString::fromUtf8("label_y"));

        gridLayout->addWidget(label_y, 3, 1, 1, 1);

        label_x_r = new QLabel(layoutWidget2);
        label_x_r->setObjectName(QString::fromUtf8("label_x_r"));

        gridLayout->addWidget(label_x_r, 0, 0, 1, 1);

        label_z_r = new QLabel(layoutWidget2);
        label_z_r->setObjectName(QString::fromUtf8("label_z_r"));

        gridLayout->addWidget(label_z_r, 0, 1, 1, 1);

        label_y_r = new QLabel(layoutWidget2);
        label_y_r->setObjectName(QString::fromUtf8("label_y_r"));

        gridLayout->addWidget(label_y_r, 1, 0, 1, 1);

        scale_label = new QLabel(layoutWidget2);
        scale_label->setObjectName(QString::fromUtf8("scale_label"));

        gridLayout->addWidget(scale_label, 2, 0, 1, 1);

        btn_screen_jpg = new QPushButton(centralwidget);
        btn_screen_jpg->setObjectName(QString::fromUtf8("btn_screen_jpg"));
        btn_screen_jpg->setGeometry(QRect(610, 640, 101, 41));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonpath->setText(QCoreApplication::translate("MainWindow", "Open file", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Translate", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "File name", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Number of veretex", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Number of rebra ", nullptr));
        path_line->setText(QString());
        number_vert->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        number_rebra->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Type of projection", nullptr));
        type_of_projection->setItemText(0, QCoreApplication::translate("MainWindow", "central", nullptr));
        type_of_projection->setItemText(1, QCoreApplication::translate("MainWindow", "parallel", nullptr));

        background_color_button->setText(QCoreApplication::translate("MainWindow", "Background color", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Type of rebra", nullptr));
        type_of_rebra->setItemText(0, QCoreApplication::translate("MainWindow", "solid", nullptr));
        type_of_rebra->setItemText(1, QCoreApplication::translate("MainWindow", "dotted", nullptr));

        color_of_rebra_button->setText(QCoreApplication::translate("MainWindow", "Color of rebra", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Thickness of rebra", nullptr));
        type_of_vert->setItemText(0, QCoreApplication::translate("MainWindow", "none", nullptr));
        type_of_vert->setItemText(1, QCoreApplication::translate("MainWindow", "square", nullptr));
        type_of_vert->setItemText(2, QCoreApplication::translate("MainWindow", "circle", nullptr));

        color_of_vert_button->setText(QCoreApplication::translate("MainWindow", "Color of vertices", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Type of vertices", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Size of vertices", nullptr));
        btn_screen_bmp->setText(QCoreApplication::translate("MainWindow", "BMP", nullptr));
        btn_screen_gif->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "z", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "z", nullptr));
        label_x->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_y->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_x_r->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_z_r->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_y_r->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        scale_label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn_screen_jpg->setText(QCoreApplication::translate("MainWindow", "JPEG", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
