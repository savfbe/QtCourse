#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QMessageBox>
SearchDialog::SearchDialog(QWidget *parent,QPlainTextEdit * TextEdit)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    pTextEdit =TextEdit;
    ui -> rbDown ->setCheckable(true);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_btNext_clicked()
{
    QString target = ui->SearchText->text();

    if (target == "" || pTextEdit == nullptr)
        return;

    QString text = pTextEdit->toPlainText();
    QTextCursor c = pTextEdit->textCursor();
    int index = -1;

    if (ui->rbDown->isChecked()) {
        index = text.indexOf(target, c.position(),
                             ui->cbCaseSensetive->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);
        if (index >= 0) {
            c.setPosition(index);
            c.setPosition(index + target.length(), QTextCursor::KeepAnchor);

            pTextEdit->setTextCursor(c);
        }
    } else if (ui->rbUp->isChecked()) {
        index = text.lastIndexOf(target, c.position() - text.length() - 1,
                                 ui->cbCaseSensetive->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);
        if (index >= 0) {
            c.setPosition(index + target.length());
            c.setPosition(index, QTextCursor::KeepAnchor);

            pTextEdit->setTextCursor(c);
        }
    }

    if (index < 0) {
        QMessageBox msg(this);
        msg.setWindowTitle("jishiben");
        msg.setText(QString("找不到 ") + target);
        msg.setWindowFlag(Qt::Drawer);
        msg.setIcon(QMessageBox::Information);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();
    }

}


void SearchDialog::on_btCancle_clicked()
{
    accept();
}

