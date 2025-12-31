#pragma once

#include <QTabWidget>

class MyTabWidget : public QTabWidget
{
	Q_OBJECT

public:
	MyTabWidget(QWidget *parent = 0);
	~MyTabWidget();

protected:
	bool event(QEvent *) Q_DECL_OVERRIDE;
};
