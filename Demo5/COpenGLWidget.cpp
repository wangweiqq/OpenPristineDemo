#include "COpenGLWidget.h"
#include <gl/GLU.h>
#include <gl/freeglut.h>
#define _USE_MATH_DEFINES
#include <math.h>

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")
#ifdef _DEBUG
#pragma comment(lib,"freeglutd.lib")
#else
#pragma comment(lib,"freeglut.lib")
#endif
static GLfloat vertices[] = {
	1,1,-1,
	-1,1,-1,
	-1,1,1,
	1,1,1,
	1,-1,1,
	-1,-1,1,
	-1,-1,-1,
	1,-1,-1
};
static GLfloat colors[] = {
	1,0,0,
	0,1,0,
	0,0,1,
	1,1,0,
	1,0,1,
	0,1,1,
	0.4,0.6,0.3,
	0,0.8,0.4
};
static GLbyte indexs[] = {
	0,1,2,3,
	4,5,6,7,
	0,3,4,7,
	2,5,4,3,
	2,1,6,5,
	0,1,6,7
};
COpenGLWidget::COpenGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
}

COpenGLWidget::~COpenGLWidget()
{
}
int _angle = 0;
void COpenGLWidget::initializeGL() {
	glShadeModel(GL_SMOOTH);
	glClearColor(0, 0, 0, 0);
	glClearDepth(1);
	
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	//glEnable(GL_VERTEX_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colors);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	this->startTimer(10);
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
	glRotatef(_angle, 1, 1, 1);
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
	
	//立方体
	glPushMatrix();
	glTranslatef(1.5, 1.0f, -7.0f);
	glScalef(0.75, 0.75, 0.75);
	glRotatef(_angle, 1, 1, 1);
	glShadeModel(GL_SMOOTH);
	/*glBegin(GL_QUADS);
	for (int i = 0; i < 6; ++i) {
		glArrayElement(indexs[i * 4 + 0]);
		glArrayElement(indexs[i * 4 + 1]);
		glArrayElement(indexs[i * 4 + 2]);
		glArrayElement(indexs[i * 4 + 3]);
	}
	glEnd();*/
	glDrawElements(GL_QUADS, sizeof(indexs)/sizeof(indexs[0]), GL_UNSIGNED_BYTE, indexs);
	//glDrawArrays(GL_QUADS, 0, 8);
	glPopMatrix();
	
	//glPushMatrix();
	//glTranslatef(-1.5, -1.5, -7);
	//glRotatef(_angle, 1, 1, 1);
	//glColor3f(0.3, .7, .6);
	////glutWireSphere(1.0, 12, 12);
	////glutWireTeapot(1.0);
	//glutWireTeapot(1.0);
	//glPopMatrix();

	glFlush();
}
void COpenGLWidget::timerEvent(QTimerEvent *event) {
	this->update();
	_angle += 1;
	_angle %= 360;
}