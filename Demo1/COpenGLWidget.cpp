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
	//��Ӱƽ����ͨ������ξ�ϸ�Ļ��ɫ�ʣ������ⲿ�����ƽ��
	glShadeModel(GL_SMOOTH);
	//���������Ļ����ɫ
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//������Ȼ��档
	glClearDepth(1.0);
	//������Ȳ��ԡ�
	glEnable(GL_DEPTH_TEST);
	//������Ȳ��Ե����͡�
	glDepthFunc(GL_LEQUAL);
	//������ϸ��͸����������һ�и���OpenGL����ϣ��������õ�͸�����������ʮ����΢��Ӱ�����ܡ���ʹ��͸��ͼ��������һ�㡣
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	this->startTimer(1000);
}
void COpenGLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//����
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
	//Բ��
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

	//������
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

	//������
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
	//���漸��Ϊ͸��ͼ������Ļ����ζ��ԽԶ�Ķ���������ԽС����ô��������һ����ʵ��۵ĳ������˴�͸�Ӱ��ջ��ڴ��ڿ�Ⱥ͸߶ȵ�45���ӽ������㡣0.1��100.0�������ڳ��������ܻ�����ȵ������յ�
	if (h == 0) {
		h = 1;
	}
	//���õ�ǰ���ӿڣ�Viewport����
	glViewport(0, 0, w, h);
	//ѡ��ͶӰ����
	glMatrixMode(GL_PROJECTION);
	//����ͶӰ����
	glLoadIdentity();
	//����͸��ͶӰ����
	gluPerspective(45.0, w / h, 0.1, 100.0);
	//ѡ��ģ�͹۲����
	glMatrixMode(GL_MODELVIEW);
	//����ģ�͹۲����
	glLoadIdentity();
}
void COpenGLWidget::timerEvent(QTimerEvent *event) {
	this->update();
}