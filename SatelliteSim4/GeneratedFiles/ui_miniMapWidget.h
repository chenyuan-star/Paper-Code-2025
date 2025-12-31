/********************************************************************************
** Form generated from reading UI file 'miniMapWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINIMAPWIDGET_H
#define UI_MINIMAPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_miniMapWidget
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *miniMapWidget)
    {
        if (miniMapWidget->objectName().isEmpty())
            miniMapWidget->setObjectName(QStringLiteral("miniMapWidget"));
        miniMapWidget->resize(360, 180);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(miniMapWidget->sizePolicy().hasHeightForWidth());
        miniMapWidget->setSizePolicy(sizePolicy);
        miniMapWidget->setMinimumSize(QSize(360, 180));
        miniMapWidget->setMaximumSize(QSize(360, 180));
        verticalLayout = new QVBoxLayout(miniMapWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(miniMapWidget);

        QMetaObject::connectSlotsByName(miniMapWidget);
    } // setupUi

    void retranslateUi(QWidget *miniMapWidget)
    {
        miniMapWidget->setWindowTitle(QApplication::translate("miniMapWidget", "miniMapWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class miniMapWidget: public Ui_miniMapWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINIMAPWIDGET_H
