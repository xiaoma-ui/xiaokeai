#include <iostream>
#include <iomanip>
using namespace std;
struct complex {
	double r;
	double i;
};
complex add(complex m,complex n) {
	complex k;
	k.r=m.r+n.r;
	k.i=m.i+n.i;
	return k;
}
complex add(complex m,double n) {
	complex k;
	k.r=m.r+n;
	k.i=m.i;
	return k;
}
complex add(double m,complex n) {
	complex k;
	k.r=m+n.r;
	k.i=n.i;
	return k;
}


int main() {
	double num;
	complex a,b,c;
	cin>>a.r>>a.i;
	cin>>b.r>>b.i;
	cin>>num;
	c=add(a,b);
	cout<<c.r<<"+"<<c.i<<"i"<<endl;
	c=add(a,num);
	cout<<c.r<<"+"<<c.i<<"i"<<endl;
	c=add(num,b);
	cout<<c.r<<"+"<<c.i<<"i"<<endl;
}
