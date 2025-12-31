/********************************************************************************
** Form generated from reading UI file 'LoadEquipmentWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADEQUIPMENTWIDGET_H
#define UI_LOADEQUIPMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadEquipmentWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_title;
    QLabel *label_num;
    QLabel *label;
    QLabel *LabelLoadEquName;
    QPushButton *pushButtonUninstallLoadEqu;
    QPushButton *pushButtonDetailInfomation;
    QSpacerItem *horizontalSpacer;
    QListWidget *listWidgetLoadEqu;

    void setupUi(QWidget *LoadEquipmentWidget)
    {
        if (LoadEquipmentWidget->objectName().isEmpty())
            LoadEquipmentWidget->setObjectName(QStringLiteral("LoadEquipmentWidget"));
        LoadEquipmentWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(LoadEquipmentWidget);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_title = new QLabel(LoadEquipmentWidget);
        label_title->setObjectName(QStringLiteral("label_title"));

        horizontalLayout->addWidget(label_title);

        label_num = new QLabel(LoadEquipmentWidget);
        label_num->setObjectName(QStringLiteral("label_num"));

        horizontalLayout->addWidget(label_num);

        label = new QLabel(LoadEquipmentWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        LabelLoadEquName = new QLabel(LoadEquipmentWidget);
        LabelLoadEquName->setObjectName(QStringLiteral("LabelLoadEquName"));

        horizontalLayout->addWidget(LabelLoadEquName);

        pushButtonUninstallLoadEqu = new QPushButton(LoadEquipmentWidget);
        pushButtonUninstallLoadEqu->setObjectName(QStringLiteral("pushButtonUninstallLoadEqu"));

        horizontalLayout->addWidget(pushButtonUninstallLoadEqu);

        pushButtonDetailInfomation = new QPushButton(LoadEquipmentWidget);
        pushButtonDetailInfomation->setObjectName(QStringLiteral("pushButtonDetailInfomation"));

        horizontalLayout->addWidget(pushButtonDetailInfomation);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        listWidgetLoadEqu = new QListWidget(LoadEquipmentWidget);
        listWidgetLoadEqu->setObjectName(QStringLiteral("listWidgetLoadEqu"));

        verticalLayout->addWidget(listWidgetLoadEqu);


        retranslateUi(LoadEquipmentWidget);

        QMetaObject::connectSlotsByName(LoadEquipmentWidget);
    } // setupUi

    void retranslateUi(QWidget *LoadEquipmentWidget)
    {
        LoadEquipmentWidget->setWindowTitle(QApplication::translate("LoadEquipmentWidget", "LoadEquipmentWidget", Q_NULLPTR));
        label_title->setText(QApplication::translate("LoadEquipmentWidget", "\350\275\275\350\215\267", Q_NULLPTR));
        label_num->setText(QApplication::translate("LoadEquipmentWidget", "1", Q_NULLPTR));
        label->setText(QApplication::translate("LoadEquipmentWidget", ":", Q_NULLPTR));
        LabelLoadEquName->setText(QApplication::translate("LoadEquipmentWidget", "*", Q_NULLPTR));
        pushButtonUninstallLoadEqu->setText(QApplication::translate("LoadEquipmentWidget", "\345\215\270\350\275\275", Q_NULLPTR));
        pushButtonDetailInfomation->setText(QApplication::translate("LoadEquipmentWidget", "\350\257\246\347\273\206\344\277\241\346\201\257", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadEquipmentWidget: public Ui_LoadEquipmentWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADEQUIPMENTWIDGET_H
