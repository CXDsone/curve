/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <qchartview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *setup;
    QWidget *centralWidget;
    QtCharts::QChartView *graphicsView;
    QPushButton *PB_check;
    QPushButton *PB_save;
    QPushButton *PB_clean;
    QPushButton *PB_load;
    QLabel *label;
    QTableWidget *TW_csv;
    QRadioButton *RB_Destructive;
    QRadioButton *RB_noDestructive;
    QPushButton *PB_allClean;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *LE_angel;
    QTableWidget *TW_load;
    QPushButton *PB_clockwise;
    QPushButton *PB_antiCLockwise;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLineEdit *LE_value;
    QRadioButton *RB_N;
    QRadioButton *RB_G;
    QPushButton *PB_saveImage;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1027, 700);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(11);
        action->setFont(font);
        setup = new QAction(MainWindow);
        setup->setObjectName(QStringLiteral("setup"));
        setup->setCheckable(false);
        setup->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QtCharts::QChartView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 60, 641, 481));
        PB_check = new QPushButton(centralWidget);
        PB_check->setObjectName(QStringLiteral("PB_check"));
        PB_check->setGeometry(QRect(670, 190, 130, 45));
        PB_check->setFont(font);
        PB_save = new QPushButton(centralWidget);
        PB_save->setObjectName(QStringLiteral("PB_save"));
        PB_save->setGeometry(QRect(670, 250, 130, 45));
        PB_save->setFont(font);
        PB_clean = new QPushButton(centralWidget);
        PB_clean->setObjectName(QStringLiteral("PB_clean"));
        PB_clean->setGeometry(QRect(670, 430, 130, 45));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PB_clean->sizePolicy().hasHeightForWidth());
        PB_clean->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(10);
        PB_clean->setFont(font1);
        PB_load = new QPushButton(centralWidget);
        PB_load->setObjectName(QStringLiteral("PB_load"));
        PB_load->setGeometry(QRect(670, 370, 130, 45));
        sizePolicy.setHeightForWidth(PB_load->sizePolicy().hasHeightForWidth());
        PB_load->setSizePolicy(sizePolicy);
        PB_load->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 10, 121, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("Agency FB"));
        font2.setPointSize(22);
        label->setFont(font2);
        TW_csv = new QTableWidget(centralWidget);
        TW_csv->setObjectName(QStringLiteral("TW_csv"));
        TW_csv->setGeometry(QRect(810, 60, 201, 601));
        TW_csv->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TW_csv->horizontalHeader()->setVisible(false);
        TW_csv->verticalHeader()->setVisible(false);
        RB_Destructive = new QRadioButton(centralWidget);
        RB_Destructive->setObjectName(QStringLiteral("RB_Destructive"));
        RB_Destructive->setGeometry(QRect(670, 50, 130, 40));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(12);
        RB_Destructive->setFont(font3);
        RB_Destructive->setMouseTracking(true);
        RB_noDestructive = new QRadioButton(centralWidget);
        RB_noDestructive->setObjectName(QStringLiteral("RB_noDestructive"));
        RB_noDestructive->setGeometry(QRect(670, 90, 130, 40));
        RB_noDestructive->setFont(font3);
        PB_allClean = new QPushButton(centralWidget);
        PB_allClean->setObjectName(QStringLiteral("PB_allClean"));
        PB_allClean->setGeometry(QRect(670, 490, 130, 45));
        sizePolicy.setHeightForWidth(PB_allClean->sizePolicy().hasHeightForWidth());
        PB_allClean->setSizePolicy(sizePolicy);
        PB_allClean->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(670, 140, 131, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font3);

        horizontalLayout->addWidget(label_2);

        LE_angel = new QLineEdit(layoutWidget);
        LE_angel->setObjectName(QStringLiteral("LE_angel"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(LE_angel->sizePolicy().hasHeightForWidth());
        LE_angel->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(LE_angel);

        TW_load = new QTableWidget(centralWidget);
        TW_load->setObjectName(QStringLiteral("TW_load"));
        TW_load->setGeometry(QRect(1040, 340, 131, 81));
        TW_load->setEditTriggers(QAbstractItemView::NoEditTriggers);
        TW_load->setSelectionMode(QAbstractItemView::NoSelection);
        TW_load->horizontalHeader()->setVisible(false);
        TW_load->verticalHeader()->setVisible(false);
        PB_clockwise = new QPushButton(centralWidget);
        PB_clockwise->setObjectName(QStringLiteral("PB_clockwise"));
        PB_clockwise->setGeometry(QRect(230, 610, 130, 45));
        PB_clockwise->setFont(font);
        PB_antiCLockwise = new QPushButton(centralWidget);
        PB_antiCLockwise->setObjectName(QStringLiteral("PB_antiCLockwise"));
        PB_antiCLockwise->setGeometry(QRect(230, 550, 130, 45));
        PB_antiCLockwise->setFont(font);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(420, 550, 130, 45));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 610, 130, 45));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(600, 550, 130, 45));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 550, 130, 45));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 610, 130, 45));
        LE_value = new QLineEdit(centralWidget);
        LE_value->setObjectName(QStringLiteral("LE_value"));
        LE_value->setGeometry(QRect(600, 610, 91, 45));
        LE_value->setFont(font3);
        LE_value->setCursor(QCursor(Qt::BlankCursor));
        LE_value->setMouseTracking(false);
        RB_N = new QRadioButton(centralWidget);
        RB_N->setObjectName(QStringLiteral("RB_N"));
        RB_N->setGeometry(QRect(700, 613, 31, 16));
        RB_N->setFont(font1);
        RB_G = new QRadioButton(centralWidget);
        RB_G->setObjectName(QStringLiteral("RB_G"));
        RB_G->setGeometry(QRect(700, 637, 31, 16));
        RB_G->setFont(font1);
        PB_saveImage = new QPushButton(centralWidget);
        PB_saveImage->setObjectName(QStringLiteral("PB_saveImage"));
        PB_saveImage->setGeometry(QRect(670, 310, 130, 45));
        sizePolicy.setHeightForWidth(PB_saveImage->sizePolicy().hasHeightForWidth());
        PB_saveImage->setSizePolicy(sizePolicy);
        PB_saveImage->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        layoutWidget->raise();
        graphicsView->raise();
        PB_check->raise();
        PB_save->raise();
        PB_clean->raise();
        PB_load->raise();
        label->raise();
        TW_csv->raise();
        RB_Destructive->raise();
        RB_noDestructive->raise();
        PB_allClean->raise();
        TW_load->raise();
        PB_clockwise->raise();
        PB_antiCLockwise->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        pushButton_5->raise();
        LE_value->raise();
        RB_N->raise();
        RB_G->raise();
        PB_saveImage->raise();
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addSeparator();
        toolBar->addAction(setup);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action->setToolTip(QApplication::translate("MainWindow", "\346\240\207\345\256\232", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        setup->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
        PB_check->setText(QApplication::translate("MainWindow", "\346\243\200\346\265\213", Q_NULLPTR));
        PB_save->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", Q_NULLPTR));
        PB_clean->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\n"
"\357\274\210\345\217\252\347\225\231\346\240\207\345\207\206\346\233\262\347\272\277\357\274\211", Q_NULLPTR));
        PB_load->setText(QApplication::translate("MainWindow", "\345\212\240\350\275\275\346\240\207\345\207\206\346\233\262\347\272\277", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\345\212\233\347\237\251\346\243\200\346\265\213", Q_NULLPTR));
        RB_Destructive->setText(QApplication::translate("MainWindow", "\347\240\264\345\235\217\346\200\247\346\265\213\350\257\225", Q_NULLPTR));
        RB_noDestructive->setText(QApplication::translate("MainWindow", "\351\235\236\347\240\264\345\235\217\346\200\247\346\265\213\350\257\225", Q_NULLPTR));
        PB_allClean->setText(QApplication::translate("MainWindow", "\345\205\250\346\270\205", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        LE_angel->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        PB_clockwise->setText(QApplication::translate("MainWindow", "\351\200\206\346\227\266\351\222\2101\345\272\246", Q_NULLPTR));
        PB_antiCLockwise->setText(QApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\2101\345\272\246", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\2105\345\272\246", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\351\200\206\346\227\266\351\222\2105\345\272\246", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\345\216\213\345\212\233\345\200\274", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\351\241\272\346\227\266\351\222\2100.2\345\272\246", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\351\200\206\346\227\266\351\222\2100.2\345\272\246", Q_NULLPTR));
        RB_N->setText(QApplication::translate("MainWindow", "N", Q_NULLPTR));
        RB_G->setText(QApplication::translate("MainWindow", "g", Q_NULLPTR));
        PB_saveImage->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\233\276\347\211\207", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
