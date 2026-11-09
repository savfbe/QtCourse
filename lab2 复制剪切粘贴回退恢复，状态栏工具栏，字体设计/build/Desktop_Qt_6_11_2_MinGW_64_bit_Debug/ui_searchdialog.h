/********************************************************************************
** Form generated from reading UI file 'searchdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHDIALOG_H
#define UI_SEARCHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *SearchText;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbUp;
    QRadioButton *rbDown;
    QCheckBox *cbCaseSensetive;
    QVBoxLayout *verticalLayout;
    QPushButton *btNext;
    QSpacerItem *verticalSpacer;
    QPushButton *btCancle;

    void setupUi(QDialog *SearchDialog)
    {
        if (SearchDialog->objectName().isEmpty())
            SearchDialog->setObjectName("SearchDialog");
        SearchDialog->resize(296, 102);
        horizontalLayout_3 = new QHBoxLayout(SearchDialog);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(SearchDialog);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        SearchText = new QLineEdit(SearchDialog);
        SearchText->setObjectName("SearchText");

        horizontalLayout->addWidget(SearchText);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        groupBox = new QGroupBox(SearchDialog);
        groupBox->setObjectName("groupBox");
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        rbUp = new QRadioButton(groupBox);
        rbUp->setObjectName("rbUp");

        horizontalLayout_2->addWidget(rbUp);

        rbDown = new QRadioButton(groupBox);
        rbDown->setObjectName("rbDown");

        horizontalLayout_2->addWidget(rbDown);


        verticalLayout_2->addWidget(groupBox);

        cbCaseSensetive = new QCheckBox(SearchDialog);
        cbCaseSensetive->setObjectName("cbCaseSensetive");

        verticalLayout_2->addWidget(cbCaseSensetive);


        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        btNext = new QPushButton(SearchDialog);
        btNext->setObjectName("btNext");

        verticalLayout->addWidget(btNext);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btCancle = new QPushButton(SearchDialog);
        btCancle->setObjectName("btCancle");

        verticalLayout->addWidget(btCancle);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(SearchDialog);

        QMetaObject::connectSlotsByName(SearchDialog);
    } // setupUi

    void retranslateUi(QDialog *SearchDialog)
    {
        SearchDialog->setWindowTitle(QCoreApplication::translate("SearchDialog", "\346\237\245\346\211\276", nullptr));
        label->setText(QCoreApplication::translate("SearchDialog", "\346\237\245\346\211\276\347\233\256\346\240\207\357\274\232", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SearchDialog", "\346\226\271\345\220\221", nullptr));
        rbUp->setText(QCoreApplication::translate("SearchDialog", "\345\220\221\344\270\212(&U)", nullptr));
        rbDown->setText(QCoreApplication::translate("SearchDialog", "\345\220\221\344\270\213(&D)", nullptr));
        cbCaseSensetive->setText(QCoreApplication::translate("SearchDialog", "\345\214\272\345\210\206\345\244\247\345\260\217\345\206\231", nullptr));
        btNext->setText(QCoreApplication::translate("SearchDialog", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252", nullptr));
        btCancle->setText(QCoreApplication::translate("SearchDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchDialog: public Ui_SearchDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHDIALOG_H
