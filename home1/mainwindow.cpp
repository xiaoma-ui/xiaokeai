#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/qmath.h>
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //输入限制
    QRegExp regexp1("[0-9]{1,6}[.][0-9]{1,2}");
    QRegExpValidator *regexpvalidator1=new QRegExpValidator(regexp1,this);
    ui->lineEdit->setValidator(regexpvalidator1);
    QRegExp regexp2("[0-9]{1,4}[.][0-9]{1,2}");
    QRegExpValidator *regexpvalidator2=new QRegExpValidator(regexp2,this);
    ui->lineEdit_2->setValidator(regexpvalidator2);
    QRegExp regexp3("[0-9]{1,2}[.][0-9]{1,2}");
    QRegExpValidator *regexpvalidator3=new QRegExpValidator(regexp3,this);
    ui->lineEdit_3->setValidator(regexpvalidator3);

    form = new Form;
    form1 = new Form1;

    //从开始界面转到组合型
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index)
    {
        if(index==2)
        {
            this->hide();
            form->show();
            ui->comboBox->setCurrentIndex(0);
        }
    });



    //从开始界面转成根据贷款总额计算
    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged),[=](int index)
    {
        if(index==1)
        {
            this->hide();
            form1->show();
            ui->comboBox_2->setCurrentIndex(0);

        }
    });

    //从组合贷界面转到开始商贷界面
    connect(form,&Form::back,[=]()
    {
        form->hide();
        this->show();
    });
    //从组合贷界面转到开始公积金贷界面
    connect(form,&Form::back1,[=]()
    {
        form->hide();
        this->show();
        ui->comboBox->setCurrentIndex(1);
    });
    //从根据贷款总额计算转到根据面积单价计算
    connect(form1,&Form1::back2,[=]()
    {
        form1->hide();
        this->show();

    });
    //从贷款总额到组合贷
    connect(form1,&Form1::back3,[=]()
    {
        form1->hide();
        form->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
//开始计算
void MainWindow::lineeditchanged()
{   double x=ui->lineEdit_3->text().toDouble();
    ui->okButton->setEnabled(!ui->lineEdit->text().isEmpty()
                             &&!ui->lineEdit_2->text().isEmpty()&&!ui->lineEdit_3->text().isEmpty()&&x);

}
//清空重填
void MainWindow::qingkong()
{
    ui->lineEdit->clear();ui->lineEdit_2->clear();ui->lineEdit_3->clear();
    ui->comboBox_2->setCurrentIndex(0);ui->comboBox_3->setCurrentIndex(0);
    ui->comboBox_4->setCurrentIndex(0);
}
//计算
void MainWindow::jisuan()
{ double danjia,mianji,chengshu,nianshu,lilv,shoufu,yuegong,dzonge,lixi,hzonge,yueshu;
  QString str;
  str=ui->lineEdit->text();danjia=str.toDouble();
  str=ui->lineEdit_2->text();mianji=str.toDouble();
  str=ui->lineEdit_3->text();lilv=str.toDouble()/1200;
  chengshu=(8-0.5*ui->comboBox_3->currentIndex())/10;
  nianshu=25-ui->comboBox_4->currentIndex();
  yueshu=nianshu*12;
  shoufu=danjia*mianji*(1-chengshu);
  dzonge=danjia*mianji*chengshu;
  if(ui->radioButton_2->isChecked())
    {yuegong=dzonge*lilv*qPow(1+lilv,yueshu)/(qPow(1+lilv,yueshu)-1);
     hzonge=yuegong*yueshu;
     lixi=hzonge-dzonge;
     form3=new Form3;
     form3->showshuju(shoufu,yuegong,dzonge,lixi,hzonge,yueshu);
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
     form2->showshuju(shoufu,yuegong,jianshao,dzonge,lixi,hzonge,yueshu);
     this->hide();
     form2->show();
     }
}

//设置窗口背景图片
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter beijing (this);
    QPixmap mix;
    mix.load(":/Image/QQ20200527165520.jpg");
    //让图片与窗口大小一致
    beijing.drawPixmap(0,0,this->width(),this->height(),mix);
}















