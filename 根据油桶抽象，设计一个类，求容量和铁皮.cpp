#include<iostream>
#include<iomanip>
#include<cmath>
using  namespace  std;
const  double  PI=3.1415926;
class cylinder {
	public:
		void init(double initX,double initY);
		double getvolumn();
		double getarea();
	private:
		double r,h;
};
inline void cylinder::init(double initX,double initY) {
	r=initY;
	h=initX;
}
double cylinder::getvolumn() {
	return PI*r*r*h;
}
double cylinder::getarea() {
	return 2*PI*r*h+2*PI*r*r;
}
int  main() {
	double d,h;
	cin>>d>>h;
	cylinder can; 
	can.init(h,d/2);
	cout<<fixed<<setprecision(6);
	cout<<"油桶的容积是"<<can.getvolumn()<<"  "<<endl;
	cout<<"铁皮的面积是"<<can.getarea()<<endl;
}
