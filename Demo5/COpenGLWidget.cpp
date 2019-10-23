#include "COpenGLWidget.h"
#include <gl/GLU.h>
#define _USE_MATH_DEFINES
#include <math.h>

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
COpenGLWidget::COpenGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
}

COpenGLWidget::~COpenGLWidget()
{
}
void COpenGLWidget::initializeGL() {
	glShadeModel(GL_SMOOTH);
	glClearColor(0, 0, 0, 0);
	glClearDepth(1);
	
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	this->startTimer(1000);
}
void COpenGLWidget::resizeGL(int w, int h) {
	if (h == 0) {
		h = 1;
	}
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (double)w / h, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void COpenGLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	//绘制圆锥
	glPushMatrix();
	glTranslatef(-1.5, 0.5, -7);
	glRotatef(-45, 1, 1, 0);
	//设置恒定着色
	glShadeModel(GL_FLAT);
	int m_Pivot = 0;
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0, 1.8, 0);	
	for (float angle = 0; angle <= 2 * M_PI ; angle += M_PI / 8) {
		if (m_Pivot % 2 == 0) {
			glColor3f(0, 1, 0);
		}
		else {
			glColor3f(0, 0, 1);
		}
		m_Pivot++;
		glVertex3f(0.8*std::sin(angle), 0, 0.8*std::cos(angle));
		//glVertex3f(std::sin(angle), 0, std::cos(angle));
	}
	glEnd();

	m_Pivot = 0;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, 0);
	for (float angle = 0; angle < 2 * M_PI; angle += M_PI / 8) {
		if (m_Pivot % 2 == 0) {
			glColor3f(1, 0, 0);
		}
		else {
			glColor3f(0, 1, 1);
		}
		m_Pivot++;
		glVertex3f(0.8*std::sin(angle), 0, 0.8*std::cos(angle));
	}
	glEnd();

	glPopMatrix();

	glFlush();
}
void COpenGLWidget::timerEvent(QTimerEvent *event) {
	this->update();
}