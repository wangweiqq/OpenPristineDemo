#pragma once

#include <QOpenGLWidget>

class COpenGLWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	COpenGLWidget(QWidget *parent);
	~COpenGLWidget();
protected:
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();
	virtual void timerEvent(QTimerEvent *event);
};
