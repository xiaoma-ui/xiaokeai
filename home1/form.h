#ifndef FORM_H
#define FORM_H
#include"form2.h"
#include"form3.h"
#include <QWidget>


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    Form2 *form2=NULL;
    Form3 *form3=NULL;
    void paintEvent(QPaintEvent *);

signals:
    void back();
    void back1();
private slots:
    void lineeditchanged();
    void qingkong();
    void jisuan();
private:
    Ui::Form *ui;
};

#endif // FORM_H
