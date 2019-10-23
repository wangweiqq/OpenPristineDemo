#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Demo1.h"

class Demo1 : public QMainWindow
{
	Q_OBJECT

public:
	Demo1(QWidget *parent = Q_NULLPTR);

private:
	Ui::Demo1Class ui;
};
