#include "form.h"
#include "ui_form.h"
#include <QtCore/qmath.h>
#include<QPainter>
Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->comboBox->setCurrentIndex(2);
    //输入限制
    QRegExp regexp1("[0-9]{1,6}[.][0-9]{1,2}");
    QRegExpValidator *regexpvalidator1=new QRegExpValidator(regexp1,this);
    ui->lineEdit->setValidator(regexpvalidator1);
    ui->lineEdit_3->setValidator(regexpvalidator1);
    QRegExp regexp3("[0-9]{1,2}[.][0-9]{1,2}");
    QRegExpValidator *regexpvalidator3=new QRegExpValidator(regexp3,this);
    ui->lineEdit_2->setValidator(regexpvalidator3);
    ui->lineEdit_4->setValidator(regexpvalidator3);

    //组合转商贷
    connect(ui->comboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index)
    {
        if(index==0)
        {
            emit this->back();
            ui->comboBox->setCurrentIndex(2);
        }
    });
    //组合转公积金
    connect(ui->comboBox,QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index)
    {
        if(index==1)
        {
            emit this->back1();
            ui->comboBox->setCurrentIndex(2);
        }
    });


}

Form::~Form()
{
    delete ui;
}

//开始计算
void Form::lineeditchanged()
{
    double x=ui->lineEdit_4->text().toDouble();
    ui->pushButton->setEnabled(!ui->lineEdit->text().isEmpty()&&!ui->lineEdit_2->text().isEmpty()&&!ui->lineEdit_3->text().isEmpty()&&!ui->lineEdit_4->text().isEmpty()&&x);

}
//清空重填
void Form::qingkong()
{
    ui->lineEdit->clear();ui->lineEdit_2->clear();ui->lineEdit_3->clear();ui->lineEdit_4->clear();
    ui->comboBox_2->setCurrentIndex(0);
}

void Form::jisuan()
{
    double sdaie,slilv,gdaie,glilv,nianshu,yuegong,dzonge,lixi,hzonge,yueshu;
      QString str;
      str=ui->lineEdit->text();sdaie=str.toDouble()*10000;
      str=ui->lineEdit_2->text();slilv=str.toDouble()/1200;
      str=ui->lineEdit_3->text();gdaie=str.toDouble()*10000;
      str=ui->lineEdit_4->text();glilv=str.toDouble()/1200;
      nianshu=25-ui->comboBox_2->currentIndex();
      yueshu=nianshu*12;
      dzonge=sdaie+gdaie;
      if(ui->radioButton->isChecked())
        {yuegong=sdaie*slilv*qPow(1+slilv,yueshu)/(qPow(1+slilv,yueshu)-1)+gdaie*glilv*qPow(1+glilv,yueshu)/(qPow(1+glilv,yueshu)-1);
         hzonge=yuegong*yueshu;
         lixi=hzonge-dzonge;
         form3=new Form3;
         form3->showshuju(0,yuegong,dzonge,lixi,hzonge,yueshu);
         this->hide();
         form3->show();
        }
      else
        {double jianshao;
         yuegong=sdaie/yueshu+sdaie*slilv+gdaie/yueshu+gdaie*glilv;
         jianshao=sdaie*slilv/yueshu+gdaie*glilv/yueshu;
         hzonge=yuegong*yueshu-jianshao*yueshu*(yueshu-1)/2;
         lixi=hzonge-dzonge;
         form2=new Form2;
         form2->showshuju(0,yuegong,jianshao,dzonge,lixi,hzonge,yueshu);
         this->hide();
         form2->show();
         }
}
void Form::paintEvent(QPaintEvent *)
{
    QPainter beijing (this);
    QPixmap mix;
    mix.load(":/Image/QQ20200527165520.jpg");
    //让图片与窗口大小一致
    beijing.drawPixmap(0,0,this->width(),this->height(),mix);
}


