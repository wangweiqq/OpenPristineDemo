#pragma once

#include <QtWidgets/QDialog>
#include "ui_Demo4.h"

class Demo4 : public QDialog
{
	Q_OBJECT

public:
	Demo4(QWidget *parent = Q_NULLPTR);

private:
	Ui::Demo4Class ui;
};
