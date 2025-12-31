#ifndef LOADEQUIPLISTWIDGET_H
#define LOADEQUIPLISTWIDGET_H

#include <QDialog>
#include <QTableWidgetItem>
#include "StructDefine.h"

namespace Ui {
class LoadequipListWidget;
}

// 载荷列表化对话框
class LoadequipListWidget : public QDialog
{
    Q_OBJECT

public:
    explicit LoadequipListWidget(QWidget *parent = 0);
    ~LoadequipListWidget();

protected slots:
	void slotItemDoubleClicked(QTableWidgetItem *);

private:
	// 返回所有载荷列表
	QList<LoadEquipment> getAllPayloadList();

private:
    Ui::LoadequipListWidget *ui;
};

#endif // LOADEQUIPLISTWIDGET_H
