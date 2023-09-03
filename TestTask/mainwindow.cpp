#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->vertex_count->setValue(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Set number of vertices
void MainWindow::on_vertex_count_valueChanged(int vertexCount)
{
    ui->GLwidget->vertexCount = vertexCount;
}

// Set the rotation of the cylinder
void MainWindow::on_rotation_axis_currentTextChanged(const QString &axis)
{
    if(axis == "X" || axis == "x")
        ui->GLwidget->currentRotationAxis = RotationAxis::X;
    else if(axis == "Y" || axis == "y")
        ui->GLwidget->currentRotationAxis = RotationAxis::Y;
    else if(axis == "Z" || axis == "z")
        ui->GLwidget->currentRotationAxis = RotationAxis::Z;
}

// Set the color of the cylinder
void MainWindow::on_choose_color_released()
{
    QColor color = QColorDialog::getColor(Qt::white, this);
    if (color.isValid())
        ui->GLwidget->color = color;
}

// Set direction of rotation
void MainWindow::on_reverse_rotate_clicked(bool checked)
{
    ui->GLwidget->reverseRotate = checked;
}

