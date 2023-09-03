#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
#include <QColor>

// Enumeration of possible axes of rotation
enum class RotationAxis
{
    X,
    Y,
    Z,
};

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    int vertexCount; // Number of vertices
    RotationAxis currentRotationAxis; // Current axis of rotation
    QColor color; // Cylinder color

private:
    QTimer timer; // Timer needed to update the window
};

#endif // GLWIDGET_H
