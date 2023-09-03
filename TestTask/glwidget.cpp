#include "glwidget.h"
#include <GL/glu.h>

GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    this->vertexCount = 5;
    this->currentRotationAxis = RotationAxis::X;
    this->color = QColor(0, 0, 255);

    // Connect timer with window update
    connect( &timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.start();
}

void GLWidget::initializeGL()
{
    // Set initial parameters
    glClearColor(0.3, 0.3, 0.3, 0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
}

void GLWidget::paintGL()
{
    // Clearing buffers
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin (GL_POLYGON);

    // Set the color of the cylinder
    glColor3d (color.redF(), color.greenF(), color.blueF());

    // Reset coordinate system
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();

    // Create a cylinder
    GLdouble cyl_radius = 0.5, cyl_height = 0.5;
    GLUquadricObj* q = gluNewQuadric ();
    gluCylinder (q, cyl_radius, cyl_radius, cyl_height, vertexCount, 320);

    glEnd ();

    glMatrixMode (GL_MODELVIEW);
    gluDeleteQuadric (q);

    // Set the rotation of the cylinder
    if(currentRotationAxis == RotationAxis::X)
        reverseRotate ? glRotatef(-0.5, 1, 0, 0) : glRotatef(0.5, 1, 0, 0);
    else if(currentRotationAxis == RotationAxis::Y)
        reverseRotate ? glRotatef(-0.5, 0, 1, 0) : glRotatef(0.5, 0, 1, 0);
    else if(currentRotationAxis == RotationAxis::Z)
        reverseRotate ? glRotatef(-0.5, 0, 0, 1) : glRotatef(0.5, 0, 0, 1);
}

void GLWidget::resizeGL(int w, int h)
{
    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    GLfloat aspectRatio = (GLfloat)w / (GLfloat)h;
    if (w <= h)
        glOrtho (-1.0, 1.0, -1.0 / aspectRatio, 1.0 / aspectRatio, -10.0, 10.0);
    else
        glOrtho (-1.0 * aspectRatio, 1.0 * aspectRatio, -1.0, 1.0, -10.0, 10.0);

    glMatrixMode(GL_MODELVIEW);
}
