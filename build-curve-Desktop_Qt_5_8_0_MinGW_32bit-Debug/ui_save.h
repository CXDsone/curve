/********************************************************************************
** Form generated from reading UI file 'save.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVE_H
#define UI_SAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Save
{
public:
    QPushButton *PB_cancel;
    QPushButton *PB_save;
    QTableWidget *tableWidget;
    QLabel *label;

    void setupUi(QDialog *Save)
    {
        if (Save->objectName().isEmpty())
            Save->setObjectName(QStringLiteral("Save"));
        Save->resize(640, 480);
        PB_cancel = new QPushButton(Save);
        PB_cancel->setObjectName(QStringLiteral("PB_cancel"));
        PB_cancel->setGeometry(QRect(400, 390, 130, 40));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        PB_cancel->setFont(font);
        PB_save = new QPushButton(Save);
        PB_save->setObjectName(QStringLiteral("PB_save"));
        PB_save->setGeometry(QRect(110, 390, 130, 40));
        PB_save->setFont(font);
        tableWidget = new QTableWidget(Save);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
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
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(60, 70, 511, 320));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(11);
        tableWidget->setFont(font1);
        tableWidget->setAutoScrollMargin(16);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::MultiSelection);
        tableWidget->setTextElideMode(Qt::ElideMiddle);
        tableWidget->horizontalHeader()->setVisible(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        tableWidget->horizontalHeader()->setMinimumSectionSize(25);
        tableWidget->verticalHeader()->setVisible(false);
        label = new QLabel(Save);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 20, 161, 31));
        label->setFont(font);

        retranslateUi(Save);

        QMetaObject::connectSlotsByName(Save);
    } // setupUi

    void retranslateUi(QDialog *Save)
    {
        Save->setWindowTitle(QApplication::translate("Save", "Dialog", Q_NULLPTR));
        PB_cancel->setText(QApplication::translate("Save", "\345\217\226\346\266\210", Q_NULLPTR));
        PB_save->setText(QApplication::translate("Save", "\344\277\235\345\255\230", Q_NULLPTR));
        label->setText(QApplication::translate("Save", "\350\257\267\351\200\211\346\213\251\351\234\200\350\246\201\344\277\235\345\255\230\347\232\204\346\233\262\347\272\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Save: public Ui_Save {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVE_H
