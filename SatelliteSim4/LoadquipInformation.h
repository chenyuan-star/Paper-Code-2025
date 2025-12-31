#ifndef LOADQUIPINFORMATION_H
#define LOADQUIPINFORMATION_H

#include <QDialog>
#include "StructDefine.h"

namespace Ui {
class LoadquipInformation;
}

// ‘ÿ∫…œÍœ∏–≈œ¢
class LoadquipInformation : public QDialog
{
    Q_OBJECT

public:
    explicit LoadquipInformation(LoadEquipment loadEqui, QWidget *parent = 0);
    ~LoadquipInformation();

private:
    Ui::LoadquipInformation *ui;
	LoadEquipment _loadEqui;
};

#endif // LOADQUIPINFORMATION_H
