/********************************************************************************
** Form generated from reading UI file 'resultsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTSDIALOG_H
#define UI_RESULTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_resultsDialog
{
public:
    QGridLayout *gridLayout;
    QCheckBox *rawBox;
    QPushButton *saveButton;
    QTableWidget *tableWidget;
    QPushButton *cancelButton;

    void setupUi(QWidget *resultsDialog)
    {
        if (resultsDialog->objectName().isEmpty())
            resultsDialog->setObjectName(QStringLiteral("resultsDialog"));
        resultsDialog->resize(403, 278);
        QIcon icon;
        icon.addFile(QStringLiteral("gibbon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        resultsDialog->setWindowIcon(icon);
        gridLayout = new QGridLayout(resultsDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rawBox = new QCheckBox(resultsDialog);
        rawBox->setObjectName(QStringLiteral("rawBox"));
        rawBox->setChecked(true);

        gridLayout->addWidget(rawBox, 1, 0, 1, 1);

        saveButton = new QPushButton(resultsDialog);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        gridLayout->addWidget(saveButton, 2, 0, 1, 1);

        tableWidget = new QTableWidget(resultsDialog);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem8);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout->addWidget(tableWidget, 0, 0, 1, 2);

        cancelButton = new QPushButton(resultsDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        gridLayout->addWidget(cancelButton, 2, 1, 1, 1);


        retranslateUi(resultsDialog);

        QMetaObject::connectSlotsByName(resultsDialog);
    } // setupUi

    void retranslateUi(QWidget *resultsDialog)
    {
        resultsDialog->setWindowTitle(QApplication::translate("resultsDialog", "Results", 0));
        rawBox->setText(QApplication::translate("resultsDialog", "Raw data", 0));
        saveButton->setText(QApplication::translate("resultsDialog", "Save", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("resultsDialog", "Number", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("resultsDialog", "Total duration", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("resultsDialog", "Percentage", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("resultsDialog", "feat1", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("resultsDialog", "feat2", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("resultsDialog", "feat3", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("resultsDialog", "feat4", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("resultsDialog", "feat5", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("resultsDialog", "noFixation", 0));
        cancelButton->setText(QApplication::translate("resultsDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class resultsDialog: public Ui_resultsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTSDIALOG_H
