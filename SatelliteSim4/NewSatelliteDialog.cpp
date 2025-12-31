#include "NewSatelliteDialog.h"
#include <QFileDialog>

/**
* @brief 构造函数
* @return
*/
NewSatelliteDialog::NewSatelliteDialog(QString name, QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.lineEditName->setText(name);

	connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(slotOK()));
	connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(slotCancel()));
	connect(ui.pushButtonOpenPayload, SIGNAL(clicked()), this, SLOT(slotOpenPayload()));

	double mu = 398600.4415;

	double period = 1.0 / 2 * osg::PI * std::sqrt(std::pow(getSemimajorAxis(), 3.0) / mu);
	ui.doubleSpinBoxMeanAnomaly->setRange(-period, period); // Update with onAChanged slot
}

/**
* @brief 析构函数
* @return
*/
NewSatelliteDialog::~NewSatelliteDialog()
{

}

/**
* @brief 确定
* @return
*/
void NewSatelliteDialog::slotOK()
{
	this->accept();
}

/**
* @brief 取消
* @return
*/
void NewSatelliteDialog::slotCancel()
{
	this->reject();
}

/**
* @brief 选择载荷
* @return
*/
void NewSatelliteDialog::slotOpenPayload()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		QStringLiteral("选择载荷模型文件"),
		"./",
		QStringLiteral("三维模型文件(*fbx *obj);;"));
	
	if (fileName.isNull() || fileName.isEmpty())
	{
		return;
	}

	ui.lineEditPayloadFile->setText(fileName);
}