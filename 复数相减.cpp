#include<iostream>
#include<iomanip>
using namespace std;
struct complex
{
	double real; 
	double imaginary;
};
int main()
{	
	complex c1,c2,c3;
	complex subtract(complex c1,complex c2);
	cin>>c1.real>>c1.imaginary;
	cin>>c2.real>>c2.imaginary;
	c3=subtract(c1,c2);
	cout<<setiosflags(ios::fixed)
    <<setprecision(2)<<c3.real<<" "<<c3.imaginary<<endl;
	return 0;
} 
	complex subtract(complex c1,complex c2)
{
	complex c;
	c.real=c1.real-c2.real;
	c.imaginary=c1.imaginary-c2.imaginary;
	return c;
}
