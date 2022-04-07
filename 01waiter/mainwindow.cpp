#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "var.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>


//点餐的菜品数量
int food[6]={0,0,0,0,0,0};
//各菜价格
int price[6]={59,39,29,49,29,29};
//名字
const char *name[6]={"小龙虾","寿司","小面包","菠萝披萨","灌汤包","意大利面"};
//座位控制
int flag=-1;//-1为未完成，0为满座，1-8为座位号


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file("../data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<("文件打不开");
    }
    int nums[8][8]={{0}};
//    读取后台数据
//    分别为八个桌子的是否有顾客，六个菜品分别的数量，是否已上菜

    QTextStream in(&file);
    QString line = in.readLine();
    int j=0;
    while (!line.isNull())
    {
        for(int i=0;i<8;i++)
        {
            char ch;
            QChar Qch=line.at(i*2);
            ch = Qch.toLatin1();
            nums[j][i]=ch-'0';
        }
        line = in.readLine();
        j++;
    }
    int res=0;
    for(int i=0;i<8;i++)
    {
        if(!nums[i][0])
        {
            res++;
        }
    }

//  处理标签，显示剩余桌子数，提醒点餐

    QString str;
    QString tips="目前尚有";
    str.setNum(res,10);
    tips.append(str);
    tips.append("桌空闲");
    ui->label_16->setText(tips);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int value1=0;

void MainWindow::on_pushButton_clicked()
{
    food[0]=ui->spinBox->value();
    food[1]=ui->spinBox_1->value();
    food[2]=ui->spinBox_2->value();
    food[3]=ui->spinBox_3->value();
    food[4]=ui->spinBox_4->value();
    food[5]=ui->spinBox_5->value();
//    记录点餐端点的各餐数量。
//    弹出确定页
    dialog=new Dialog(this);
    dialog->setModal(false);
    dialog->show();
}

void MainWindow::on_pushButton_9_clicked()
{
    qApp->exit(773);
}
