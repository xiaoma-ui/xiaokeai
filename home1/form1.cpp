#include "form1.h"
#include "ui_form1.h"
#include <QPushButton>
#include <QtCore/qmath.h>
#include<QPainter>
Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
    ui->comboBox_2->setCurrentIndex(1);
    //输入限制
    QRegExp regexp4("[0-9]{1,10}[.][0-9]{1,2}");
    QRegExpValidator *regexpvalidator4=new QRegExpValidator(regexp4,this);
    ui->lineEdit->setValidator(regexpvalidator4);
    QRegExp regexp3("[0-9]{1,2}[.][0-9]{1,2}");
    QRegExpValidator *regexpvalidator3=new QRegExpValidator(regexp3,this);
    ui->lineEdit_2->setValidator(regexpvalidator3);

    //贷款总额转到面积单价
    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index)
    {
        if(index==0)
        {   emit this->back2();
            ui->comboBox_2->setCurrentIndex(1);
        }
    });
    //从贷款总额转到组合型贷款
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index)
    {
        if(index==2)
        {
            emit this->back3();
            ui->comboBox->setCurrentIndex(1);
        }
    });
}

Form1::~Form1()
{
    delete ui;
}

//开始计算
void Form1::lineeditchanged()
{   double x=ui->lineEdit_2->text().toDouble();
    ui->pushButton->setEnabled(!ui->lineEdit->text().isEmpty()&&!ui->lineEdit_2->text().isEmpty()&&x);
}
//清空重填
void Form1::qingkong()
{
    ui->lineEdit->clear();ui->lineEdit_2->clear();
    ui->comboBox_2->setCurrentIndex(0);ui->comboBox_3->setCurrentIndex(0);
}

void Form1::jisuan()
{ double dzonge,nianshu,lilv,yuegong,dzonge1,lixi,hzonge,yueshu;
  QString str;
  str=ui->lineEdit->text();dzonge=str.toDouble()*10000;
  str=ui->lineEdit_2->text();lilv=str.toDouble()/1200;
  nianshu=25-ui->comboBox_3->currentIndex();
  yueshu=nianshu*12;
  dzonge1=dzonge;
  if(ui->radioButton->isChecked())
    {yuegong=dzonge*lilv*qPow(1+lilv,yueshu)/(qPow(1+lilv,yueshu)-1);
     hzonge=yuegong*yueshu;
     lixi=hzonge-dzonge;
     form3=new Form3;
     form3->showshuju(0,yuegong,dzonge,lixi,hzonge,yueshu);
     this->hide();
     form3->show();
    }
  else
    {double jianshao;
     yuegong=dzonge/yueshu+dzonge*lilv;
     jianshao=dzonge*lilv/yueshu;
     hzonge=yuegong*yueshu-jianshao*yueshu*(yueshu-1)/2;
     lixi=hzonge-dzonge;
     form2=new Form2;
     form2->showshuju(0,yuegong,jianshao,dzonge,lixi,hzonge,yueshu);
     this->hide();
     form2->show();
     }
  }
//设置窗口背景图片
void Form1::paintEvent(QPaintEvent *)
{
    QPainter beijing (this);
    QPixmap mix;
    mix.load(":/Image/QQ20200527165520.jpg");
    //让图片与窗口大小一致
    beijing.drawPixmap(0,0,this->width(),this->height(),mix);
}



