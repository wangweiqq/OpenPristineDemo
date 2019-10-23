#include "COpenGLWidget.h"
#include <gl/GLU.h>
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
	//阴影平滑，通过多边形精细的混合色彩，并对外部光进行平滑
	glShadeModel(GL_SMOOTH);
	//设置清除屏幕的颜色
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//设置深度缓存。
	glClearDepth(1.0);
	//启用深度测试。
	glEnable(GL_DEPTH_TEST);
	//所作深度测试的类型。
	glDepthFunc(GL_LEQUAL);
	//真正精细的透视修正。这一行告诉OpenGL我们希望进行最好的透视修正。这会十分轻微的影响性能。但使得透视图看起来好一点。
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	this->startTimer(1000);
}
void COpenGLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//画线
	glPushMatrix();
	glColor3f(0.0f, 1.0f, 1.0f);
	glTranslatef(-1.5f, 1.0f, -6.0f);
	glScalef(0.75f, 0.75f, 0.75f);
	glRotatef(45.0f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
	glPopMatrix();
	//圆形
	glPushMatrix();
	glTranslatef(1.5f, 1.0f, -6.0f);
	glScalef(0.75f, 0.75f, 0.75f);
	glRotatef(45.0f, 1.0f, 1.0f, 1.0f);
	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);	
	glVertex3f(0.0f, 0.0f, 0.0f);
	for (int i = 0; i <= 370; i += 10) {		
		float p = (float)i*3.14 / 180;
		glVertex3f(sin(p), cos(p), 0.0f);
	}
	glEnd();
	glPopMatrix();

	//三角形
	glPushMatrix();
	glTranslatef(-1.5, -1.0, -6.0);
	glScalef(0.75f, 0.75f, 0.75f);
	glRotatef(45.0f, 1.0f, 1.0f, 1.0f);
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
	glPopMatrix();

	//正方形
	glPushMatrix();
	glTranslatef(1.5, -1.0, -6.0);
	glScalef(0.75f, 0.75f, 0.75f);
	glRotatef(45.0f, 1.0f, 1.0f, 1.0f);
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-1, 1, 0);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);
	glVertex3f(1, 1, 0);
	glEnd();	
	glPushMatrix();

	glFlush();
}
void COpenGLWidget::resizeGL(int w, int h) {
	//上面几行为透视图设置屏幕。意味着越远的东西看起来越小。这么做创建了一个现实外观的场景。此处透视按照基于窗口宽度和高度的45度视角来计算。0.1，100.0是我们在场景中所能绘制深度的起点和终点
	if (h == 0) {
		h = 1;
	}
	//重置当前的视口（Viewport）。
	glViewport(0, 0, w, h);
	//选择投影矩阵。
	glMatrixMode(GL_PROJECTION);
	//重置投影矩阵
	glLoadIdentity();
	//建立透视投影矩阵。
	gluPerspective(45.0, w / h, 0.1, 100.0);
	//选择模型观察矩阵。
	glMatrixMode(GL_MODELVIEW);
	//重置模型观察矩阵。
	glLoadIdentity();
}
void COpenGLWidget::timerEvent(QTimerEvent *event) {
	this->update();
}