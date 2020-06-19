#include "form3.h"
#include "ui_form3.h"
#include<QPainter>
Form3::Form3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form3)
{
    ui->setupUi(this);
}

Form3::~Form3()
{
    delete ui;
}
void Form3::showshuju(double a, double b, double c, double d, double e, double f)
{
     long long int x;
     x=(long long int)(a+0.49);
     if(a==0) {ui->label_19->hide();ui->label_14->hide();ui->label_8->hide();}
     else ui->label_14->setText(QString::number(x));
     x=(long long int)(b+0.49);ui->label_15->setText(QString::number(x));
     x=(long long int)(c+0.49);ui->label_16->setText(QString::number(x));
     if(d<100000000.0)    {x=(int)(d+0.49);ui->label_17->setText(QString::number(x));}
     else  {x=(long long int) (d/100000000.0+0.49);ui->label_17->setText(QString::number(x));ui->label_11->setText(tr("亿元"));}
     if(e<100000000.0)    {x=(int)(e+0.49);ui->label_18->setText(QString::number(x));}
     else  {x=(long long int) (e/100000000.0+0.49);ui->label_18->setText(QString::number(x));ui->label_13->setText(tr("亿元"));}
     x=(int)(f+0.49);ui->label_7->setText(QString::number(x));
}
//设置窗口背景图片
void Form3::paintEvent(QPaintEvent *)
{
    QPainter beijing (this);
    QPixmap mix;
    mix.load(":/Image/mmexport1590570717333.jpg");
    //让图片与窗口大小一致
    beijing.drawPixmap(0,0,this->width(),this->height(),mix);
}
