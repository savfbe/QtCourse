#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QPlainTextEdit>

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr,QPlainTextEdit * TextEdit=nullptr);
    ~SearchDialog();

private slots:
    void on_btNext_clicked();

    void on_btCancle_clicked();

private:
    Ui::SearchDialog *ui;

    QPlainTextEdit *pTextEdit;
};

#endif // SEARCHDIALOG_H
