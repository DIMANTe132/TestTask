#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <glwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_vertex_count_valueChanged(int); // Set number of vertices

    void on_rotation_axis_currentTextChanged(const QString&); // Set the rotation of the cylinder

    void on_choose_color_released(); // Set the color of the cylinder

    void on_reverse_rotate_clicked(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
