/********************************************************************************
** Form generated from reading UI file 'ConfigManageDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGMANAGEDIALOG_H
#define UI_CONFIGMANAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigManageDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetLoadEquipments;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboBoxEquList;
    QPushButton *pushButtonInstallLoadEqu;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonClose;

    void setupUi(QDialog *ConfigManageDialog)
    {
        if (ConfigManageDialog->objectName().isEmpty())
            ConfigManageDialog->setObjectName(QStringLiteral("ConfigManageDialog"));
        ConfigManageDialog->resize(417, 490);
        verticalLayout = new QVBoxLayout(ConfigManageDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetLoadEquipments = new QWidget(ConfigManageDialog);
        widgetLoadEquipments->setObjectName(QStringLiteral("widgetLoadEquipments"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetLoadEquipments->sizePolicy().hasHeightForWidth());
        widgetLoadEquipments->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(widgetLoadEquipments);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        comboBoxEquList = new QComboBox(ConfigManageDialog);
        comboBoxEquList->setObjectName(QStringLiteral("comboBoxEquList"));

        horizontalLayout_3->addWidget(comboBoxEquList);

        pushButtonInstallLoadEqu = new QPushButton(ConfigManageDialog);
        pushButtonInstallLoadEqu->setObjectName(QStringLiteral("pushButtonInstallLoadEqu"));

        horizontalLayout_3->addWidget(pushButtonInstallLoadEqu);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButtonClose = new QPushButton(ConfigManageDialog);
        pushButtonClose->setObjectName(QStringLiteral("pushButtonClose"));

        horizontalLayout_4->addWidget(pushButtonClose);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(ConfigManageDialog);

        QMetaObject::connectSlotsByName(ConfigManageDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigManageDialog)
    {
        ConfigManageDialog->setWindowTitle(QApplication::translate("ConfigManageDialog", "\345\215\253\346\230\237\351\205\215\347\275\256", Q_NULLPTR));
        comboBoxEquList->clear();
        comboBoxEquList->insertItems(0, QStringList()
         << QApplication::translate("ConfigManageDialog", "\350\275\275\350\215\2671", Q_NULLPTR)
         << QApplication::translate("ConfigManageDialog", "\350\275\275\350\215\2672", Q_NULLPTR)
        );
        pushButtonInstallLoadEqu->setText(QApplication::translate("ConfigManageDialog", "\346\214\202\350\275\275", Q_NULLPTR));
        pushButtonClose->setText(QApplication::translate("ConfigManageDialog", "\347\241\256\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ConfigManageDialog: public Ui_ConfigManageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGMANAGEDIALOG_H
