#include "dialog.h"
#include "ui_dialog.h"
#include "var.h"
#include "dialog1.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

int nums[8][8];
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QString warning="您所下单的菜品有:\n";
    int res=0;
    for (int i=0;i<6;i++) {
        if(food[i])
        {
            QString str;
            str.setNum(food[i],10);
            warning.append(name[i]);
            warning.append(str);
            warning.append("份\n");
            res+=food[i]*price[i];
        }
    }
    QString str;
    str.setNum(res,10);
    warning.append("总价为：");
    warning.append(str);
    warning.append("元，请结算");
    ui->textEdit->setText(warning);
}

Dialog::~Dialog()
{
    delete ui;
}


//写文件，存储点餐数据。
void Dialog::on_buttonBox_accepted()
{
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
         flag=-1;
         for(int i=0;i<8;i++)
         {
             if(!nums[i][0])
             {
                 flag=i+1;
                 break;
             }
         }
         if(flag==-1)
             flag=0;
         else
         {
             nums[flag-1][0]=1;
             for(int i=1;i<7;i++)
             {
                 nums[flag-1][i]=food[i-1];
             }
             nums[flag-1][7]=0;
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
         }
    Dialog1 *dialog=new Dialog1(this);
    dialog->setModal(false);
    dialog->show();
}
