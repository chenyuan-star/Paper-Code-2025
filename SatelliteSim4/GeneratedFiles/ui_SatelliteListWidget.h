/********************************************************************************
** Form generated from reading UI file 'SatelliteListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SATELLITELISTWIDGET_H
#define UI_SATELLITELISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SatelliteListWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *SatelliteListWidget)
    {
        if (SatelliteListWidget->objectName().isEmpty())
            SatelliteListWidget->setObjectName(QStringLiteral("SatelliteListWidget"));
        SatelliteListWidget->resize(1457, 557);
        horizontalLayout = new QHBoxLayout(SatelliteListWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        tableWidget = new QTableWidget(SatelliteListWidget);
        if (tableWidget->columnCount() < 11)
            tableWidget->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        if (tableWidget->rowCount() < 20)
            tableWidget->setRowCount(20);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem30);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setCornerButtonEnabled(true);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(SatelliteListWidget);

        QMetaObject::connectSlotsByName(SatelliteListWidget);
    } // setupUi

    void retranslateUi(QWidget *SatelliteListWidget)
    {
        SatelliteListWidget->setWindowTitle(QApplication::translate("SatelliteListWidget", "Form", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SatelliteListWidget", "id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SatelliteListWidget", "\345\215\253\346\230\237\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SatelliteListWidget", "\345\255\230\345\202\250\345\256\271\351\207\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SatelliteListWidget", "\345\215\253\346\230\237\345\233\275\351\231\205\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("SatelliteListWidget", "\345\215\253\346\230\237\347\212\266\346\200\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("SatelliteListWidget", "\345\215\225\350\241\214\350\275\250\351\201\223\345\217\202\346\225\2601", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("SatelliteListWidget", "\345\215\225\350\241\214\350\275\250\351\201\223\345\217\202\346\225\2602", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("SatelliteListWidget", "\345\217\221\345\260\204\345\234\272\345\234\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("SatelliteListWidget", "\345\217\221\345\260\204\345\272\217\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("SatelliteListWidget", "\345\217\221\345\260\204\346\227\245\346\234\237", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("SatelliteListWidget", "\346\211\200\345\261\236\346\230\237\345\272\247id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("SatelliteListWidget", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("SatelliteListWidget", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("SatelliteListWidget", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("SatelliteListWidget", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem15->setText(QApplication::translate("SatelliteListWidget", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem16->setText(QApplication::translate("SatelliteListWidget", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem17->setText(QApplication::translate("SatelliteListWidget", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem18->setText(QApplication::translate("SatelliteListWidget", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem19->setText(QApplication::translate("SatelliteListWidget", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem20->setText(QApplication::translate("SatelliteListWidget", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem21->setText(QApplication::translate("SatelliteListWidget", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem22->setText(QApplication::translate("SatelliteListWidget", "12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem23->setText(QApplication::translate("SatelliteListWidget", "13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem24->setText(QApplication::translate("SatelliteListWidget", "14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem25->setText(QApplication::translate("SatelliteListWidget", "15", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem26->setText(QApplication::translate("SatelliteListWidget", "16", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem27->setText(QApplication::translate("SatelliteListWidget", "17", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem28->setText(QApplication::translate("SatelliteListWidget", "18", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem29->setText(QApplication::translate("SatelliteListWidget", "19", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem30->setText(QApplication::translate("SatelliteListWidget", "20", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SatelliteListWidget: public Ui_SatelliteListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SATELLITELISTWIDGET_H
