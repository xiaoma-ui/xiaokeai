#ifndef FORM2_H
#define FORM2_H

#include <QWidget>

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();
    void paintEvent(QPaintEvent *);

void showshuju(double a,double b,double c,double d,double e,double f,double g);
private:
    Ui::Form2 *ui;
};

#endif // FORM2_H
