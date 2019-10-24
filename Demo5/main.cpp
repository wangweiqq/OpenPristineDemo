#include "Demo5.h"
#include <QtWidgets/QApplication>
#include <gl/freeglut.h>
void RenderScenceCB() {
	// 清空颜色缓存
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(-1.5, -1.5, -7);
	//glRotatef(_angle, 1, 1, 1);
	glColor3f(0.3, .7, .6);
	//glutWireSphere(1.0, 12, 12);
	//glutWireTeapot(1.0);
	glutWireTeapot(1.0);
	// 交换前后缓存
	glutSwapBuffers();
}
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// 初始化GLUT
	glutInit(&argc, argv);

	//// 显示模式：双缓冲、RGBA
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	//// 窗口设置
	//glutInitWindowSize(480, 320);      // 窗口尺寸
	//glutInitWindowPosition(100, 100);  // 窗口位置
	//glutCreateWindow("Tutorial 01");   // 窗口标题

	//								   // 开始渲染
	//glutDisplayFunc(RenderScenceCB);

	//// 缓存清空后的颜色值
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//// 通知开始GLUT的内部循环
	//glutMainLoop();

	//return a.exec();
	//QApplication a(argc, argv);
	Demo5 w;
	w.show();
	return a.exec();
}
