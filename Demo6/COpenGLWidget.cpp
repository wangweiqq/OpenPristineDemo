#include "COpenGLWidget.h"
#include <gl/GLU.h>
#define _USE_MATH_DEFINES
#include <math.h>

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#ifdef _DEBUG
//#pragma comment(lib,"freeglutd.lib")
#else
//#pragma comment(lib,"freeglut.lib")
#endif

COpenGLWidget::COpenGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
}

COpenGLWidget::~COpenGLWidget()
{
}
int _angle = 0;
GLuint m_pyramid;
void COpenGLWidget::initializeGL() {
	m_pyramid = glGenLists(1);
	if (m_pyramid != 0) {
		glNewList(m_pyramid, GL_COMPILE);
		glBegin(GL_TRIANGLES);
		//Ç°²àÃæ
		//¶¥
		glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		//×ó
		glColor3f(0,1,0);
		glVertex3f(-1, -1, 1);
		//ÓÒ
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, 1);

		//ÓÒ²àÃæ
		//¶¥
		glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		//×ó
		glColor3f(0, 1, 0);
		glVertex3f(1, -1, 1);
		//ÓÒ
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);

		//ºó²àÃæ
		//¶¥
		glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		//×ó
		glColor3f(0,1,0);
		glVertex3f(1, -1, -1);
		//ÓÒ
		glColor3f(0, 0, 1);
		glVertex3f(-1, -1, -1);

		//×ó²àÃæ
		//¶¥
		glColor3f(1, 0, 0);
		glVertex3f(0, 1, 0);
		//×ó
		glColor3f(0, 1, 0);
		glVertex3f(-1, -1, -1);
		//ÓÒ
		glColor3f(0, 0, 1);
		glVertex3f(-1, -1, 1);

		glEnd();
		glBegin(GL_QUADS);
		glColor3f(1, 0, 0);
		glVertex3f(-1, -1, 1);
		glColor3f(0, 1, 0);
		glVertex3f(1, -1, 1);
		glColor3f(0, 0, 1);
		glVertex3f(1, -1, -1);
		glColor3f(1, 0, 1);
		glVertex3f(-1, -1, -1);
		glEnd();
		glEndList();
	}

	glShadeModel(GL_SMOOTH);
	//glShadeModel(GL_FLAT);
	glClearColor(0, 0, 0, 0);

	glClearDepth(1.0f);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	this->startTimer(10);
}
void COpenGLWidget::resizeGL(int w, int h) 
{
	if (h == 0) {
		h = 1;
	}
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.f, (double)w / h, 0.1, 100);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void COpenGLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) {
			glLoadIdentity();
			glTranslatef(-3 + 2 * x, -2 + 2 * y, -10);
			glScalef(0.8, 0.8, 0.8);
			glRotatef(_angle, 1, 1, 0);
			glCallList(m_pyramid);
		}
	}
	glFlush();
}
void COpenGLWidget::timerEvent(QTimerEvent *event) {
	this->update();
	_angle += 1;
	_angle %= 360;
}