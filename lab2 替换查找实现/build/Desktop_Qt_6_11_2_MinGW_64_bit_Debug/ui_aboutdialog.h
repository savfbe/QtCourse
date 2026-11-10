/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName("AboutDialog");
        AboutDialog->resize(307, 301);
        buttonBox = new QDialogButtonBox(AboutDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 221, 16));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(AboutDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 281, 41));
        QFont font;
        font.setPointSize(28);
        label->setFont(font);
        label_4 = new QLabel(AboutDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 80, 111, 131));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/img/R-C.jpg);"));
        label_5 = new QLabel(AboutDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 240, 121, 16));
        widget = new QWidget(AboutDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(150, 100, 141, 101));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout->addWidget(label_3);


        retranslateUi(AboutDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AboutDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AboutDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AboutDialog", "\345\235\244\345\235\244\346\226\207\346\234\254\347\274\226\350\276\221\345\231\250", nullptr));
        label_4->setText(QString());
        label_5->setText(QCoreApplication::translate("AboutDialog", "V1.0 build 20261108", nullptr));
        label_2->setText(QCoreApplication::translate("AboutDialog", "\345\274\200\345\217\221\344\272\272\357\274\232\350\277\236\346\263\275\346\245\267", nullptr));
        label_3->setText(QCoreApplication::translate("AboutDialog", "\345\255\246\345\217\267\357\274\2322024414290318", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
