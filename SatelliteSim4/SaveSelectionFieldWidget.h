#ifndef SAVESELECTIONFIELDWIDGET_H
#define SAVESELECTIONFIELDWIDGET_H

#include <QDialog>
#include <QVector>
#include <QPair>

namespace Ui {
class SaveSelectionFieldWidget;
}

// ±£´æ·¶Î§
class SaveSelectionFieldWidget : public QDialog
{
    Q_OBJECT

public:
    explicit SaveSelectionFieldWidget(QVector<QPair<float,float>> list,QWidget *parent = 0);
    ~SaveSelectionFieldWidget();

	QImage getCoordinate(QString url, QList<QPointF> coords);

protected:
	void showEvent(QShowEvent *) override;

private slots:
    void on_pushButton_cancel_clicked();
	void slotSubmit();
	void slotCancel();

private:
    Ui::SaveSelectionFieldWidget *ui;
	QVector<QPair<float, float>>	_coordMap;
};

#endif // SAVESELECTIONFIELDWIDGET_H
