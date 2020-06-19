#ifndef FORM1_H
#define FORM1_H
#include"form2.h"
#include"form3.h"
#include <QWidget>
#include <QComboBox>
#include"form.h"

namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    ~Form1();
    Form* form=NULL;
    Form2 *form2=NULL;
    Form3 *form3=NULL;
    void paintEvent(QPaintEvent *);

signals:
    void back2();
    void back3();
private slots:
    void lineeditchanged();
    void qingkong();
    void jisuan();
private:
    Ui::Form1 *ui;
};

#endif // FORM1_H
