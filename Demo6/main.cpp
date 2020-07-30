#include "Demo6.h"
#include <QtWidgets/QApplication>
#include <QSurfaceFormat>
int main(int argc, char *argv[])
{
	/*QSurfaceFormat format;
	format.setDepthBufferSize(24);
	format.setStencilBufferSize(8);
	format.setVersion(4, 3);
	format.setProfile(QSurfaceFormat::CoreProfile);
	QSurfaceFormat::setDefaultFormat(format);*/
	QApplication a(argc, argv);
	Demo6 w;
	w.show();
	return a.exec();
}
