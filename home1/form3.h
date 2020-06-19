#ifndef FORM3_H
#define FORM3_H

#include <QWidget>

namespace Ui {
class Form3;
}

class Form3 : public QWidget
{
    Q_OBJECT

public:
    explicit Form3(QWidget *parent = nullptr);
    ~Form3();
   void showshuju(double a,double b,double c,double d,double e,double f);
   void paintEvent(QPaintEvent *);

private:
    Ui::Form3 *ui;
};

#endif // FORM3_H
