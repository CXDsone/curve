/********************************************************************************
** Form generated from reading UI file 'dialogsetup.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETUP_H
#define UI_DIALOGSETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogSetup
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *RB_N;
    QRadioButton *RB_G;
    QRadioButton *radioButton_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *PB_ok;
    QPushButton *PB_cancel;
    QWidget *layoutWidget_2;
    QFormLayout *formLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_3;
    QWidget *widget;
    QFormLayout *formLayout_2;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_5;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *lineEdit_6;

    void setupUi(QDialog *DialogSetup)
    {
        if (DialogSetup->objectName().isEmpty())
            DialogSetup->setObjectName(QStringLiteral("DialogSetup"));
        DialogSetup->resize(640, 480);
        layoutWidget = new QWidget(DialogSetup);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 70, 201, 141));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        RB_N = new QRadioButton(layoutWidget);
        RB_N->setObjectName(QStringLiteral("RB_N"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RB_N->sizePolicy().hasHeightForWidth());
        RB_N->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        RB_N->setFont(font);

        verticalLayout->addWidget(RB_N);

        RB_G = new QRadioButton(layoutWidget);
        RB_G->setObjectName(QStringLiteral("RB_G"));
        sizePolicy.setHeightForWidth(RB_G->sizePolicy().hasHeightForWidth());
        RB_G->setSizePolicy(sizePolicy);
        RB_G->setFont(font);

        verticalLayout->addWidget(RB_G);

        radioButton_3 = new QRadioButton(layoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        sizePolicy.setHeightForWidth(radioButton_3->sizePolicy().hasHeightForWidth());
        radioButton_3->setSizePolicy(sizePolicy);
        radioButton_3->setFont(font);

        verticalLayout->addWidget(radioButton_3);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(lineEdit_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout->addWidget(label_5);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(14);
        label_6->setFont(font1);
        label_6->setLayoutDirection(Qt::LeftToRight);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        PB_ok = new QPushButton(DialogSetup);
        PB_ok->setObjectName(QStringLiteral("PB_ok"));
        PB_ok->setGeometry(QRect(110, 370, 130, 45));
        PB_cancel = new QPushButton(DialogSetup);
        PB_cancel->setObjectName(QStringLiteral("PB_cancel"));
        PB_cancel->setGeometry(QRect(370, 370, 130, 45));
        layoutWidget_2 = new QWidget(DialogSetup);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(360, 70, 201, 141));
        formLayout = new QFormLayout(layoutWidget_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_2);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setFont(font);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(1, QFormLayout::LabelRole, horizontalSpacer_2);

        lineEdit = new QLineEdit(layoutWidget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font);

        formLayout->setWidget(2, QFormLayout::SpanningRole, label_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(3, QFormLayout::LabelRole, horizontalSpacer_3);

        lineEdit_2 = new QLineEdit(layoutWidget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_2);

        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout->setItem(5, QFormLayout::LabelRole, horizontalSpacer_4);

        lineEdit_3 = new QLineEdit(layoutWidget_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEdit_3);

        widget = new QWidget(DialogSetup);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(80, 240, 201, 92));
        formLayout_2 = new QFormLayout(widget);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_7);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(1, QFormLayout::LabelRole, horizontalSpacer_5);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_5);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_8);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_2->setItem(3, QFormLayout::LabelRole, horizontalSpacer_6);

        lineEdit_6 = new QLineEdit(widget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, lineEdit_6);


        retranslateUi(DialogSetup);

        QMetaObject::connectSlotsByName(DialogSetup);
    } // setupUi

    void retranslateUi(QDialog *DialogSetup)
    {
        DialogSetup->setWindowTitle(QApplication::translate("DialogSetup", "Dialog", Q_NULLPTR));
        RB_N->setText(QApplication::translate("DialogSetup", "N", Q_NULLPTR));
        RB_G->setText(QApplication::translate("DialogSetup", "g", Q_NULLPTR));
        radioButton_3->setText(QApplication::translate("DialogSetup", "\346\211\255\347\237\251", Q_NULLPTR));
        label_4->setText(QApplication::translate("DialogSetup", "\345\212\233\350\207\202\351\225\277\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("DialogSetup", "mm", Q_NULLPTR));
        label_6->setText(QApplication::translate("DialogSetup", "\345\215\225\344\275\215\351\200\211\346\213\251", Q_NULLPTR));
        PB_ok->setText(QApplication::translate("DialogSetup", "\347\241\256\345\256\232", Q_NULLPTR));
        PB_cancel->setText(QApplication::translate("DialogSetup", "\345\217\226\346\266\210", Q_NULLPTR));
        label->setText(QApplication::translate("DialogSetup", "\347\240\264\345\235\217\346\200\247\346\265\213\350\257\225\346\234\200\345\244\247\350\247\222\345\272\246\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogSetup", "\346\216\245\350\247\246\345\211\215\346\255\245\350\267\235\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogSetup", "\346\216\245\350\247\246\345\220\216\346\255\245\350\267\235\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("DialogSetup", "\345\212\233\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("DialogSetup", "\350\247\222\345\272\246\351\207\217\347\250\213\357\274\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogSetup: public Ui_DialogSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETUP_H
