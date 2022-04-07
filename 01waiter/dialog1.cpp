#include "dialog1.h"
#include "ui_dialog1.h"
#include "var.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    switch (flag) {
        case 0:ui->textEdit->setText("已满座，抱歉，请稍候片刻");break;
        case 1:ui->textEdit->setText("请您于第1桌就餐");break;
        case 2:ui->textEdit->setText("请您于第2桌就餐");break;
        case 3:ui->textEdit->setText("请您于第3桌就餐");break;
        case 4:ui->textEdit->setText("请您于第4桌就餐");break;
        case 5:ui->textEdit->setText("请您于第5桌就餐");break;
        case 6:ui->textEdit->setText("请您于第6桌就餐");break;
        case 7:ui->textEdit->setText("请您于第7桌就餐");break;
        case 8:ui->textEdit->setText("请您于第8桌就餐");break;
        default: ui->textEdit->setText("订单出现问题，请重新下单");break;
    }
}

Dialog1::~Dialog1()
{
    delete ui;
}
