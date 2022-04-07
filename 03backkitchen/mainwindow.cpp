#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "var.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "dialog.h"

//点餐的菜品数量
int food[6]={0,0,0,0,0,0};
//各菜价格
int price[6]={59,39,29,49,29,29};
//名字
const char *name[6]={"小龙虾","寿司","小面包","菠萝披萨","灌汤包","意大利面"};
//座位控制
int flag=-1;//-1为未完成，0为满座，1-8为座位号

int nums[8][8]={{0}};
//nums数组存后台数据信息
//分别为八个桌子的是否有顾客，六个菜品分别的数量，是否已上菜

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
//   文件读数据
    ui->setupUi(this);
    QFile file("../data.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<("文件打不开");
    }

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
    QString str;
//    以下i从0到8，分别是八个桌子的情况显示
//    以i=0为例：

    int i=0;
//    分为无客人，待上菜，和已上齐菜三种情况。


    if(nums[i][0]==0)
        ui->textEdit->setText("该座位暂无顾客");
    else if(nums[i][7]==1)
    {
        ui->textEdit->setText("已上齐菜\n");
        ui->label_10->setText("0");
    }
    else
    {
        QString now="待上：\n";
        int res=0;
        for(int j=1;j<7;j++)
        {
            if(nums[i][j])
            {
                now.append(name[j-1]);
                QString str;
                str.setNum(nums[i][j],10);
                now.append(str);
                now.append("份\n");
                res+=nums[i][j]*price[j-1];
            }
        }
        ui->textEdit->setText(now);
        now.setNum(res,10);
        now.append("元");
//        ui->label_10->setText(now);
    }
    i++;
    if(nums[i][0]==0)
        ui->textEdit_2->setText("该座位暂无顾客");
    else if(nums[i][7]==1)
    {

        ui->textEdit_2->setText("已上齐菜");
        ui->label_13->setText("0");
    }
    else
    {
        QString now="待上：\n";
        int res=0;
        for(int j=1;j<7;j++)
        {
            if(nums[i][j])
            {
                now.append(name[j-1]);
                QString str;
                str.setNum(nums[i][j],10);
                now.append(str);
                now.append("份\n");
                res+=nums[i][j]*price[j-1];
            }
        }
        ui->textEdit_2->setText(now);
        now.setNum(res,10);
        now.append("元");
//        ui->label_13->setText(now);
    }

    i++;
    if(nums[i][0]==0)
        ui->textEdit_3->setText("该座位暂无顾客");
    else if(nums[i][7]==1)
    {

        ui->textEdit_3->setText("已上齐菜");
        ui->label_15->setText("0");
    }
    else
    {
        QString now="待上：\n";
        int res=0;
        for(int j=1;j<7;j++)
        {
            if(nums[i][j])
            {
                now.append(name[j-1]);
                QString str;
                str.setNum(nums[i][j],10);
                now.append(str);
                now.append("份\n");
                res+=nums[i][j]*price[j-1];
            }
        }
        ui->textEdit_3->setText(now);
        now.setNum(res,10);
        now.append("元");
//        ui->label_15->setText(now);
    }

    i++;
    if(nums[i][0]==0)
        ui->textEdit_4->setText("该座位暂无顾客");
    else if(nums[i][7]==1)
    {

        ui->textEdit_4->setText("已上齐菜");

        ui->label_16->setText("0");
    }
    else
    {
        QString now="待上\n";
        int res=0;
        for(int j=1;j<7;j++)
        {
            if(nums[i][j])
            {
                now.append(name[j-1]);
                QString str;
                str.setNum(nums[i][j],10);
                now.append(str);
                now.append("份\n");
                res+=nums[i][j]*price[j-1];
            }
        }
        ui->textEdit_4->setText(now);
        now.setNum(res,10);
        now.append("元");
//        ui->label_16->setText(now);
    }

    i++;
    if(nums[i][0]==0)
        ui->textEdit_5->setText("该座位暂无顾客");
    else if(nums[i][7]==1)
    {
        ui->textEdit_5->setText("已上齐菜");
        ui->label_18->setText("0");
    }
    else
    {
        QString now="待上：\n";
        int res=0;
        for(int j=1;j<7;j++)
        {
            if(nums[i][j])
            {
                now.append(name[j-1]);
                QString str;
                str.setNum(nums[i][j],10);
                now.append(str);
                now.append("份\n");
                res+=nums[i][j]*price[j-1];
            }
        }
        ui->textEdit_5->setText(now);
        now.setNum(res,10);
        now.append("元");
//        ui->label_18->setText(now);
    }

    i++;
    if(nums[i][0]==0)
        ui->textEdit_6->setText("该座位暂无顾客");
    else if(nums[i][7]==1)
    {

        ui->textEdit_6->setText("已上齐菜");
        ui->label_20->setText("0");
    }
    else
    {
        QString now="待上：\n";
        int res=0;
        for(int j=1;j<7;j++)
        {
            if(nums[i][j])
            {
                now.append(name[j-1]);
                QString str;
                str.setNum(nums[i][j],10);
                now.append(str);
                now.append("份\n");
                res+=nums[i][j]*price[j-1];
            }
        }
        ui->textEdit_6->setText(now);
        now.setNum(res,10);
        now.append("元");
//        ui->label_20->setText(now);
    }

    i++;
    if(nums[i][0]==0)
        ui->textEdit_7->setText("该座位暂无顾客");
    else if(nums[i][7]==1)
    {
        ui->textEdit_7->setText("已上齐菜");
        ui->label_22->setText("0");
    }
    else
    {
        QString now="待上：\n";
        int res=0;
        for(int j=1;j<7;j++)
        {
            if(nums[i][j])
            {
                now.append(name[j-1]);
                QString str;
                str.setNum(nums[i][j],10);
                now.append(str);
                now.append("份\n");
                res+=nums[i][j]*price[j-1];
            }
        }
        ui->textEdit_7->setText(now);
        now.setNum(res,10);
        now.append("元");
//        ui->label_22->setText(now);
    }

    i++;
    if(nums[i][0]==0)
        ui->textEdit_8->setText("该座位暂无顾客");
    else if(nums[i][7]==1)
    {
        ui->textEdit_8->setText("已上齐菜");
        ui->label_24->setText("0");
    }
    else
    {
        QString now="待上：\n";
        int res=0;
        for(int j=1;j<7;j++)
        {
            if(nums[i][j])
            {
                now.append(name[j-1]);
                QString str;
                str.setNum(nums[i][j],10);
                now.append(str);
                now.append("份\n");
                res+=nums[i][j]*price[j-1];
            }
        }
        ui->textEdit_8->setText(now);
        now.setNum(res,10);
        now.append("元");
//        ui->label_24->setText(now);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//刷新按钮
void MainWindow::on_pushButton_9_clicked()
{
    qApp->exit(773);
}


//以下分别为八个按键的触发函数，代表上菜事件，并刷新界面。

void MainWindow::on_pushButton_clicked()
{
    if(nums[0][0]!=0&&nums[0][7]==0)
    {
        nums[0][7]=1;

//  写文件更新后台数据信息

        QFile f("../data.txt");
           if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
           {
               qDebug()<<("文件打不开");
           }
           QTextStream txtOutput(&f);
           QString now;
           QString str;
           for (int i=0;i<8;i++) {
               if(i)
                   now.append('\n');
               for(int j=0;j<8;j++)
               {
                  str.setNum(nums[i][j],10);
                  if(j)
                      now.append(' ');
                  now.append(str);
               }
           }
           txtOutput << now;
           f.close();
           dialog=new Dialog(this);
           dialog->setModal(false);
           dialog->show();
           qApp->exit(773);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(nums[1][0]!=0&&nums[1][7]==0)
    {
        nums[1][7]=1;
        QFile f("../data.txt");
           if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
           {
               qDebug()<<("文件打不开");
           }
           QTextStream txtOutput(&f);
           QString now;
           QString str;
           for (int i=0;i<8;i++) {
               if(i)
                   now.append('\n');
               for(int j=0;j<8;j++)
               {
                  str.setNum(nums[i][j],10);
                  if(j)
                      now.append(' ');
                  now.append(str);
               }
           }
           txtOutput << now;
           f.close();
           dialog=new Dialog(this);
           dialog->setModal(false);
           dialog->show();
           qApp->exit(773);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(nums[2][0]!=0&&nums[2][7]==0)
    {
        nums[2][7]=1;
        QFile f("../data.txt");
           if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
           {
               qDebug()<<("文件打不开");
           }
           QTextStream txtOutput(&f);
           QString now;
           QString str;
           for (int i=0;i<8;i++) {
               if(i)
                   now.append('\n');
               for(int j=0;j<8;j++)
               {
                  str.setNum(nums[i][j],10);
                  if(j)
                      now.append(' ');
                  now.append(str);
               }
           }
           txtOutput << now;
           f.close();
           dialog=new Dialog(this);
           dialog->setModal(false);
           dialog->show();
           qApp->exit(773);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(nums[3][0]!=0&&nums[3][7]==0)
    {
        nums[3][7]=1;
        QFile f("../data.txt");
           if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
           {
               qDebug()<<("文件打不开");
           }
           QTextStream txtOutput(&f);
           QString now;
           QString str;
           for (int i=0;i<8;i++) {
               if(i)
                   now.append('\n');
               for(int j=0;j<8;j++)
               {
                  str.setNum(nums[i][j],10);
                  if(j)
                      now.append(' ');
                  now.append(str);
               }
           }
           txtOutput << now;
           f.close();
           dialog=new Dialog(this);
           dialog->setModal(false);
           dialog->show();
           qApp->exit(773);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(nums[4][0]!=0&&nums[4][7]==0)
    {
        nums[4][7]=1;
        QFile f("../data.txt");
           if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
           {
               qDebug()<<("文件打不开");
           }
           QTextStream txtOutput(&f);
           QString now;
           QString str;
           for (int i=0;i<8;i++) {
               if(i)
                   now.append('\n');
               for(int j=0;j<8;j++)
               {
                  str.setNum(nums[i][j],10);
                  if(j)
                      now.append(' ');
                  now.append(str);
               }
           }
           txtOutput << now;
           f.close();
           dialog=new Dialog(this);
           dialog->setModal(false);
           dialog->show();
           qApp->exit(773);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(nums[5][0]!=0&&nums[5][7]==0)
    {
        nums[5][7]=1;
        QFile f("../data.txt");
           if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
           {
               qDebug()<<("文件打不开");
           }
           QTextStream txtOutput(&f);
           QString now;
           QString str;
           for (int i=0;i<8;i++) {
               if(i)
                   now.append('\n');
               for(int j=0;j<8;j++)
               {
                  str.setNum(nums[i][j],10);
                  if(j)
                      now.append(' ');
                  now.append(str);
               }
           }
           txtOutput << now;
           f.close();
           dialog=new Dialog(this);
           dialog->setModal(false);
           dialog->show();
           qApp->exit(773);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if(nums[6][0]!=0&&nums[6][7]==0)
    {
        nums[6][7]=1;
        QFile f("../data.txt");
           if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
           {
               qDebug()<<("文件打不开");
           }
           QTextStream txtOutput(&f);
           QString now;
           QString str;
           for (int i=0;i<8;i++) {
               if(i)
                   now.append('\n');
               for(int j=0;j<8;j++)
               {
                  str.setNum(nums[i][j],10);
                  if(j)
                      now.append(' ');
                  now.append(str);
               }
           }
           txtOutput << now;
           f.close();
           dialog=new Dialog(this);
           dialog->setModal(false);
           dialog->show();
           qApp->exit(773);
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    if(nums[7][0]!=0&&nums[7][7]==0)
    {
        nums[7][7]=1;
        QFile f("../data.txt");
           if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
           {
               qDebug()<<("文件打不开");
           }
           QTextStream txtOutput(&f);
           QString now;
           QString str;
           for (int i=0;i<8;i++) {
               if(i)
                   now.append('\n');
               for(int j=0;j<8;j++)
               {
                  str.setNum(nums[i][j],10);
                  if(j)
                      now.append(' ');
                  now.append(str);
               }
           }
           txtOutput << now;
           f.close();
           dialog=new Dialog(this);
           dialog->setModal(false);
           dialog->show();
           qApp->exit(773);
    }
}
