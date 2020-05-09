#include  <iostream>
#include  <iomanip>
using  namespace  std;
//���ڴ˴�����Account��Ķ���
class Account {
	public:
		void init(const char *a,const char *b,const char *c,int d,double e);
		void printmoney();
		void deposit(double f);
		void withdraw(double g);
		int p(double h);
	private:
		const char *zhanghao,*name,*sex;
		int age;
		double cunkuan;
};
void Account::init(const char *a,const char *b,const char *c,int d,double e) {
	zhanghao=a;
	name=b;
	sex=c;
	age=d;
	if(p(e))cout<<"������Ľ��Ϸ�"<<endl;
	else cunkuan=e;
}
void Account::printmoney() {
	cout<<name<<"�Ĵ��Ϊ"<<setiosflags(ios::fixed)<<setprecision(2)<<cunkuan<<endl;
}
void Account::deposit(double f) {
	if(p(f))cout<<"������Ľ��Ϸ�"<<endl;
	else cunkuan+=f;
}
void Account::withdraw(double g) {
	if(p(g))cout<<"������Ľ��Ϸ�"<<endl;
	else if(g>cunkuan)cout<<"���Ĵ�����"<<endl;
	else cunkuan-=g;
}
int Account::p(double h) {
	double i=100*h;
	if(i-int(i)!=0)return 1;
	else return 0;
}
int main() {
	Account  tom;
	tom.init("32020320011001876X",  "Tom  Black",  "��",  19,  2000.89);
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89
	tom.deposit(89.471);//�����������Ľ��Ϸ�
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89
	tom.deposit(10000);
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ12000.89
	tom.withdraw(10001);
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
	tom.withdraw(10000.123);//�����������Ľ��Ϸ�
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
	tom.withdraw(10000.9);//��������Ĵ�����
	tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89
	Account  jerry;
	jerry.init("320203200910116569",  "Jerry  Black",  "Ů",  11,  100.956);//�����������Ľ��Ϸ�
	jerry.printmoney();//�����Jerry  Black�Ĵ��Ϊ0.00
}

