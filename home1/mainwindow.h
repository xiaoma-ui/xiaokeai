#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QComboBox>
#include <QMainWindow>
#include "form.h"
#include "form1.h"
#include <form2.h>
#include <form3.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Form  *form =NULL;
    Form1 *form1=NULL;
    Form2 *form2=NULL;
    Form3 *form3=NULL;
    void paintEvent(QPaintEvent *);
private slots:
    void lineeditchanged();
    void qingkong();
    void jisuan();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
