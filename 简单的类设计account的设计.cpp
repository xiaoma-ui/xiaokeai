#include  <iostream>
#include  <iomanip>
using  namespace  std;
//请在此处补充Account类的定义
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
	if(p(e))cout<<"您输入的金额不合法"<<endl;
	else cunkuan=e;
}
void Account::printmoney() {
	cout<<name<<"的存款为"<<setiosflags(ios::fixed)<<setprecision(2)<<cunkuan<<endl;
}
void Account::deposit(double f) {
	if(p(f))cout<<"您输入的金额不合法"<<endl;
	else cunkuan+=f;
}
void Account::withdraw(double g) {
	if(p(g))cout<<"您输入的金额不合法"<<endl;
	else if(g>cunkuan)cout<<"您的存款金额不足"<<endl;
	else cunkuan-=g;
}
int Account::p(double h) {
	double i=100*h;
	if(i-int(i)!=0)return 1;
	else return 0;
}
int main() {
	Account  tom;
	tom.init("32020320011001876X",  "Tom  Black",  "男",  19,  2000.89);
	tom.printmoney();//输出：Tom  Black的存款为2000.89
	tom.deposit(89.471);//输出：您输入的金额不合法
	tom.printmoney();//输出：Tom  Black的存款为2000.89
	tom.deposit(10000);
	tom.printmoney();//输出：Tom  Black的存款为12000.89
	tom.withdraw(10001);
	tom.printmoney();//输出：Tom  Black的存款为1999.89
	tom.withdraw(10000.123);//输出：您输入的金额不合法
	tom.printmoney();//输出：Tom  Black的存款为1999.89
	tom.withdraw(10000.9);//输出：您的存款金额不足
	tom.printmoney();//输出：Tom  Black的存款为1999.89
	Account  jerry;
	jerry.init("320203200910116569",  "Jerry  Black",  "女",  11,  100.956);//输出：您输入的金额不合法
	jerry.printmoney();//输出：Jerry  Black的存款为0.00
}

