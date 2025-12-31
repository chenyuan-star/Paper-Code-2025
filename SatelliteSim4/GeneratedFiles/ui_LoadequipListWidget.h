/********************************************************************************
** Form generated from reading UI file 'LoadequipListWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADEQUIPLISTWIDGET_H
#define UI_LOADEQUIPLISTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadequipListWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;

    void setupUi(QWidget *LoadequipListWidget)
    {
        if (LoadequipListWidget->objectName().isEmpty())
            LoadequipListWidget->setObjectName(QStringLiteral("LoadequipListWidget"));
        LoadequipListWidget->resize(540, 357);
        verticalLayout = new QVBoxLayout(LoadequipListWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget = new QTableWidget(LoadequipListWidget);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        if (tableWidget->rowCount() < 11)
            tableWidget->setRowCount(11);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem14);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setTextElideMode(Qt::ElideNone);

        verticalLayout->addWidget(tableWidget);


        retranslateUi(LoadequipListWidget);

        QMetaObject::connectSlotsByName(LoadequipListWidget);
    } // setupUi

    void retranslateUi(QWidget *LoadequipListWidget)
    {
        LoadequipListWidget->setWindowTitle(QApplication::translate("LoadequipListWidget", "\350\275\275\350\215\267\345\210\227\350\241\250\345\214\226", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LoadequipListWidget", "\350\275\275\350\215\267\347\274\226\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LoadequipListWidget", "\350\275\275\350\215\267\345\220\215\347\247\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("LoadequipListWidget", "\350\275\275\350\215\267\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("LoadequipListWidget", "\345\275\223\345\211\215\347\212\266\346\200\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("LoadequipListWidget", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("LoadequipListWidget", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("LoadequipListWidget", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("LoadequipListWidget", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("LoadequipListWidget", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("LoadequipListWidget", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem10->setText(QApplication::translate("LoadequipListWidget", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem11->setText(QApplication::translate("LoadequipListWidget", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem12->setText(QApplication::translate("LoadequipListWidget", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem13->setText(QApplication::translate("LoadequipListWidget", "10", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoadequipListWidget: public Ui_LoadequipListWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADEQUIPLISTWIDGET_H
