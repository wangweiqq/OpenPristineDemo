#pragma once

#include <QtWidgets/QDialog>
#include "ui_Demo5.h"

class Demo5 : public QDialog
{
	Q_OBJECT

public:
	Demo5(QWidget *parent = Q_NULLPTR);

private:
	Ui::Demo5Class ui;
};
