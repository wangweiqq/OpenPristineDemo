#pragma once

#include <QtWidgets/QDialog>
#include "ui_Demo6.h"

class Demo6 : public QDialog
{
	Q_OBJECT

public:
	Demo6(QWidget *parent = Q_NULLPTR);

private:
	Ui::Demo6Class ui;
};
