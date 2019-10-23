#pragma once

#include <QOpenGLWidget>

class COpenGLWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	COpenGLWidget(QWidget *parent = nullptr);
	~COpenGLWidget();
protected:
	virtual void initializeGL();
	virtual void paintGL();
	virtual void resizeGL(int w, int h);
};
