#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    digitBTNs = {{Qt::Key_0,ui->btnNum0},
               {Qt::Key_1,ui->btnNum1},
               {Qt::Key_2,ui->btnNum2},
               {Qt::Key_3,ui->btnNum3},
               {Qt::Key_4,ui->btnNum4},
               {Qt::Key_5,ui->btnNum5},
               {Qt::Key_6,ui->btnNum6},
               {Qt::Key_7,ui->btnNum7},
               {Qt::Key_8,ui->btnNum8},
               {Qt::Key_9,ui->btnNum9},
               };

    foreach(auto btn,digitBTNs)
        connect(btn,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

//    connect(ui->btnNum0,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum1,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum2,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum3,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum4,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum5,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum6,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum7,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum8,SIGNAL(clicked()),this,SLOT(btnNumClicked()));
//    connect(ui->btnNum9,SIGNAL(clicked()),this,SLOT(btnNumClicked()));

    connect(ui->btnPlus, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMinus, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnMultiple, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));
    connect(ui->btnDivide, SIGNAL(clicked()), this, SLOT(btnBinaryOperatorClicked()));

    connect(ui->btnPercentage, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnInverse, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSquare, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));
    connect(ui->btnSqrt, SIGNAL(clicked()), this, SLOT(btnUnaryOperatorClicked()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::calculation(bool *ok)
{
    double result = 0;
    if (operands.size() == 2 && opcodes.size() > 0) {
        //取操作数
        double operand1 = operands.front().toDouble();
        operands.pop_front();
        double operand2 = operands.front().toDouble();
        operands.pop_front();

        //取操作符
        QString op = opcodes.front();
        opcodes.pop_front();

        if (op == "+") {
            result = operand1 + operand2;
        } else if (op == "-") {
            result = operand1 - operand2;
        } else if (op == "×") {
            result = operand1 * operand2;
        } else if (op == "/") {
            if (qFuzzyIsNull(operand2)) {            // 浮点数比较，避免 0.0000001 之类误差误判
                if (ok) *ok = false;                 // 通知调用方本次求值失败
                operands.clear();  opcodes.clear();
                return QStringLiteral("除数不能为 0");
            }
            result = operand1 / operand2;

            result = operand1 / operand2;
        }

        operands.push_back(QString::number(result));

        ui->statusbar->showMessage(QString("calculation is in progress：operands is %1, opcode is %2").arg(operands.size()).arg(opcodes.size()));
    } else
        ui->statusbar->showMessage(QString("operands is %1, opcode is %2").arg(operands.size()).arg(opcodes.size()));


    return QString::number(result) ;
}


void MainWindow::btnNumClicked()
{
    QString digit = qobject_cast<QPushButton *>(sender())->text();

    if (digit == "0" && operand == "0")
    digit = "";

    if (operand == "0" && digit != "0")
        operand = "";

    operand += digit;

    ui->display->setText(operand);
}



void MainWindow::on_btnPeriod_clicked()
{
    if (!operand.contains("."))
        operand += qobject_cast<QPushButton *>(sender())->text();
    ui->display->setText(operand);
}


void MainWindow::on_btnDel_clicked()
{
    operand=operand.left(operand.length()-1);
    ui->display->setText(operand);
}


void MainWindow::on_binClear_clicked()
{
    operand.clear();
    ui->display->setText(operand);
}

void MainWindow::btnBinaryOperatorClicked()
{
    ui->statusbar->showMessage("last operand"+operand);
    QString opcode = qobject_cast<QPushButton *>(sender())->text();

    if (operand != "") {
        operands.push_back(operand);
        operand = "";

        opcodes.push_back(opcode);


    QString result=calculation();

    ui->display->setText(result);
    }
}

void MainWindow:: btnUnaryOperatorClicked()
{
    if (operand != "") {
        double result = operand.toDouble();
        operand = "";

        QString op = qobject_cast<QPushButton*>(sender())->text();
        if(op == "%")
            result /=100.0;
        else if(op == "1/x")
            result = 1/result;
        else if(op == "x^2")
            result *=result;
        else if(op == "2√x")
            result = sqrt(result);
        ui->display->setText(QString::number( result));
    }
}

void MainWindow::on_btnEqual_clicked()
{
    if (operand != "") {
        operands.push_back(operand);
        operand = "";
    }
    QString result=calculation();

    ui->display->setText(result);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    foreach(auto btnKey , digitBTNs.keys())
    {
        if(event->key() == btnKey)
            digitBTNs[btnKey]->animateClick();
    }

    switch (event->key()) {
    case Qt::Key_Equal:
    case Qt::Key_Return:
    case Qt::Key_Enter:
        ui->btnEqual->animateClick();
        break;
    case Qt::Key_Plus:
        ui->btnPlus->animateClick();
        break;
    case Qt::Key_Minus:
        ui->btnMinus->animateClick();
        break;
    case Qt::Key_Asterisk:
        ui->btnMultiple->animateClick();
        break;
    case Qt::Key_Slash:
        ui->btnDivide->animateClick();
        break;
    case Qt::Key_Percent:
        ui->btnPercentage->animateClick();
        break;
    case Qt::Key_Backspace:
    case Qt::Key_Delete:
        ui->btnDel->animateClick();
        break;
    case Qt::Key_Period:
        ui->btnPeriod->animateClick();
        break;
    default:
        break;
    }
}




void MainWindow::on_btnClearAll_clicked()
{
    operands.clear();
    ui->display->setText("0");
}

void MainWindow::on_btnSign_clicked()
{

    if (operand.isEmpty())
        operand = ui->display->text();


    if (operand.isEmpty() || operand == "0")
        return;

    if (operand.startsWith("-"))
        operand.remove(0, 1);
    else
        operand.prepend("-");

    ui->display->setText(operand);
}

