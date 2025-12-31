#include "MyTabWidget.h"

MyTabWidget::MyTabWidget(QWidget *parent)
	: QTabWidget(parent)
{
}

MyTabWidget::~MyTabWidget()
{
}

bool MyTabWidget::event(QEvent* e)
{
	QTabWidget::event(e);

	return true;
}