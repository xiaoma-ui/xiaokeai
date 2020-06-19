#include "form2.h"
#include "ui_form2.h"
#include<QPainter>
Form2::Form2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form2)
{
    ui->setupUi(this);
}

Form2::~Form2()
{
    delete ui;
}
void Form2::showshuju(double a, double b, double c, double d, double e, double f,double g)
{
    long long int x;
         x=(long long int)(a+0.49);
         if(a==0) {ui->label_2->hide();ui->label_4->hide();ui->label_5->hide();}
         else ui->label_4->setText(QString::number(x));
         x=(long long int)(b+0.49);ui->label_7->setText(QString::number(x));
         x=(long long int)(c+0.49);ui->label_8->setText(QString::number(x));
         x=(long long int)(d+0.49);ui->label_12->setText(QString::number(x));
         if(e<100000000.0)    {x=(int)(e+0.49);ui->label_15->setText(QString::number(x));}
         else  {x=(long long int) (e/100000000.0+0.49);ui->label_15->setText(QString::number(x));ui->label_16->setText(tr("亿元"));}
         if(f<100000000.0)    {x=(int)(f+0.49);ui->label_18->setText(QString::number(x));}
         else  {x=(long long int) (f/100000000.0+0.49);ui->label_18->setText(QString::number(x));ui->label_19->setText(tr("亿元"));}
         x=(int)(g+0.49);ui->label_21->setText(QString::number(x));
}

//设置窗口背景图片
void Form2::paintEvent(QPaintEvent *)
{
    QPainter beijing (this);
    QPixmap mix;
    mix.load(":/Image/mmexport1590570717333.jpg");
    //让图片与窗口大小一致
    beijing.drawPixmap(0,0,this->width(),this->height(),mix);
}



