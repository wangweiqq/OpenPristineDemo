#include "Demo5.h"
#include <QtWidgets/QApplication>
#include <gl/freeglut.h>
void RenderScenceCB() {
	// �����ɫ����
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(-1.5, -1.5, -7);
	//glRotatef(_angle, 1, 1, 1);
	glColor3f(0.3, .7, .6);
	//glutWireSphere(1.0, 12, 12);
	//glutWireTeapot(1.0);
	glutWireTeapot(1.0);
	// ����ǰ�󻺴�
	glutSwapBuffers();
}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// ��ʼ��GLUT
	glutInit(&argc, argv);

	//// ��ʾģʽ��˫���塢RGBA
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	//// ��������
	//glutInitWindowSize(480, 320);      // ���ڳߴ�
	//glutInitWindowPosition(100, 100);  // ����λ��
	//glutCreateWindow("Tutorial 01");   // ���ڱ���

	//								   // ��ʼ��Ⱦ
	//glutDisplayFunc(RenderScenceCB);

	//// ������պ����ɫֵ
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//// ֪ͨ��ʼGLUT���ڲ�ѭ��
	//glutMainLoop();

	//return a.exec();
	//QApplication a(argc, argv);
	Demo5 w;
	w.show();
	return a.exec();
}
