/********************************************************************************
** Form generated from reading UI file 'RegionalPlanningWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIONALPLANNINGWIDGET_H
#define UI_REGIONALPLANNINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegionalPlanningWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QWidget *qTestWebWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *rectangleSelectionBtn;
    QPushButton *polygonSelectionBtn;
    QPushButton *circleSelectionBtn;
    QPushButton *clearOverlaysBtn;
    QPushButton *saveCoordinatesBtn;

    void setupUi(QWidget *RegionalPlanningWidget)
    {
        if (RegionalPlanningWidget->objectName().isEmpty())
            RegionalPlanningWidget->setObjectName(QStringLiteral("RegionalPlanningWidget"));
        RegionalPlanningWidget->resize(1235, 748);
        gridLayout_2 = new QGridLayout(RegionalPlanningWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        qTestWebWidget = new QWidget(RegionalPlanningWidget);
        qTestWebWidget->setObjectName(QStringLiteral("qTestWebWidget"));

        gridLayout->addWidget(qTestWebWidget, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        rectangleSelectionBtn = new QPushButton(RegionalPlanningWidget);
        rectangleSelectionBtn->setObjectName(QStringLiteral("rectangleSelectionBtn"));

        horizontalLayout->addWidget(rectangleSelectionBtn);

        polygonSelectionBtn = new QPushButton(RegionalPlanningWidget);
        polygonSelectionBtn->setObjectName(QStringLiteral("polygonSelectionBtn"));

        horizontalLayout->addWidget(polygonSelectionBtn);

        circleSelectionBtn = new QPushButton(RegionalPlanningWidget);
        circleSelectionBtn->setObjectName(QStringLiteral("circleSelectionBtn"));

        horizontalLayout->addWidget(circleSelectionBtn);

        clearOverlaysBtn = new QPushButton(RegionalPlanningWidget);
        clearOverlaysBtn->setObjectName(QStringLiteral("clearOverlaysBtn"));

        horizontalLayout->addWidget(clearOverlaysBtn);

        saveCoordinatesBtn = new QPushButton(RegionalPlanningWidget);
        saveCoordinatesBtn->setObjectName(QStringLiteral("saveCoordinatesBtn"));

        horizontalLayout->addWidget(saveCoordinatesBtn);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(RegionalPlanningWidget);

        QMetaObject::connectSlotsByName(RegionalPlanningWidget);
    } // setupUi

    void retranslateUi(QWidget *RegionalPlanningWidget)
    {
        RegionalPlanningWidget->setWindowTitle(QApplication::translate("RegionalPlanningWidget", "Form", Q_NULLPTR));
        rectangleSelectionBtn->setText(QApplication::translate("RegionalPlanningWidget", "\347\237\251\345\275\242\351\200\211\345\217\226", Q_NULLPTR));
        polygonSelectionBtn->setText(QApplication::translate("RegionalPlanningWidget", "\345\244\232\350\276\271\345\275\242\351\200\211\345\217\226", Q_NULLPTR));
        circleSelectionBtn->setText(QApplication::translate("RegionalPlanningWidget", "\345\234\206\345\275\242\351\200\211\345\217\226", Q_NULLPTR));
        clearOverlaysBtn->setText(QApplication::translate("RegionalPlanningWidget", "\346\270\205\351\231\244\350\246\206\347\233\226\347\211\251", Q_NULLPTR));
        saveCoordinatesBtn->setText(QApplication::translate("RegionalPlanningWidget", "\344\277\235\345\255\230\347\273\217\347\272\254\345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RegionalPlanningWidget: public Ui_RegionalPlanningWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIONALPLANNINGWIDGET_H
