/********************************************************************************
** Form generated from reading UI file 'ctpquoteserver.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTPQUOTESERVER_H
#define UI_CTPQUOTESERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTPQuoteServerClass
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *mdEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *brokerIdEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *userIdEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLineEdit *pwdEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *loginButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CTPQuoteServerClass)
    {
        if (CTPQuoteServerClass->objectName().isEmpty())
            CTPQuoteServerClass->setObjectName(QStringLiteral("CTPQuoteServerClass"));
        CTPQuoteServerClass->resize(313, 272);
        CTPQuoteServerClass->setAutoFillBackground(false);
        centralWidget = new QWidget(CTPQuoteServerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 251, 201));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        mdEdit = new QLineEdit(groupBox);
        mdEdit->setObjectName(QStringLiteral("mdEdit"));

        horizontalLayout->addWidget(mdEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        brokerIdEdit = new QLineEdit(groupBox);
        brokerIdEdit->setObjectName(QStringLiteral("brokerIdEdit"));

        horizontalLayout_3->addWidget(brokerIdEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        userIdEdit = new QLineEdit(groupBox);
        userIdEdit->setObjectName(QStringLiteral("userIdEdit"));

        horizontalLayout_4->addWidget(userIdEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_5->addWidget(label_8);

        pwdEdit = new QLineEdit(groupBox);
        pwdEdit->setObjectName(QStringLiteral("pwdEdit"));

        horizontalLayout_5->addWidget(pwdEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        loginButton = new QPushButton(groupBox);
        loginButton->setObjectName(QStringLiteral("loginButton"));

        horizontalLayout_6->addWidget(loginButton);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_6);

        CTPQuoteServerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CTPQuoteServerClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 313, 23));
        CTPQuoteServerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CTPQuoteServerClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CTPQuoteServerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CTPQuoteServerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CTPQuoteServerClass->setStatusBar(statusBar);

        retranslateUi(CTPQuoteServerClass);
        QObject::connect(loginButton, SIGNAL(clicked()), CTPQuoteServerClass, SLOT(MDLogin()));

        QMetaObject::connectSlotsByName(CTPQuoteServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *CTPQuoteServerClass)
    {
        CTPQuoteServerClass->setWindowTitle(QApplication::translate("CTPQuoteServerClass", "CTPQuoteServer", 0));
        groupBox->setTitle(QApplication::translate("CTPQuoteServerClass", "\350\241\214\346\203\205\346\234\215\345\212\241", 0));
        label->setText(QApplication::translate("CTPQuoteServerClass", "\350\241\214\346\203\205\345\234\260\345\235\200:", 0));
        label_4->setText(QApplication::translate("CTPQuoteServerClass", "\344\274\232\345\221\230\347\274\226\345\217\267:", 0));
        label_6->setText(QApplication::translate("CTPQuoteServerClass", "\350\264\246    \345\217\267:", 0));
        label_8->setText(QApplication::translate("CTPQuoteServerClass", "\345\257\206    \347\240\201:", 0));
        loginButton->setText(QApplication::translate("CTPQuoteServerClass", "\345\220\257\345\212\250", 0));
    } // retranslateUi

};

namespace Ui {
    class CTPQuoteServerClass: public Ui_CTPQuoteServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTPQUOTESERVER_H
