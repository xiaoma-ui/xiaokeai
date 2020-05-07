#include  <iostream> 
using  namespace  std; 
class Complex
{
	public:
		Complex(double r=0.0,double i=0.0)
			{real=r;imag=i;}
		friend Complex operator+(Complex c1,Complex c2);
		friend Complex operator-(Complex c1,Complex c2);
		friend Complex operator+(double x,Complex c3);
		friend Complex operator-(double x,Complex c3);
		friend Complex operator+(Complex c3,double x);
		friend Complex operator-(Complex c3,double x);
		void print();
 	private:
		double real;
		double imag;
};
Complex operator+(Complex c1,Complex c2)
{
	return Complex(c1.real+c2.real,c1.imag+c2.imag);
}
Complex operator-(Complex c1,Complex c2)
{
	return Complex(c1.real-c2.real,c1.imag-c2.imag);
}
Complex operator+(double x,Complex c3)
{
	return Complex(x+c3.real,c3.imag);
}
Complex operator-(double x,Complex c3)
{
	return Complex(x-c3.real,-c3.imag);
}
Complex operator+(Complex c3,double x)
{
	return Complex(c3.real+x,c3.imag);
}
Complex operator-(Complex c3,double x)
{
	return Complex(c3.real-x,c3.imag);
}
void Complex::print()
{
	cout<<"("<<real<<")"<<"+"<<"("<<imag<<"i)"<<endl;
}
int  main() 
{ 
        Complex  a(3,4),b(1,-1),c; 
        c=a+b; 
        cout<<"a+b="; 
        c.print(); 
        cout<<endl; 
        c=a-b; 
        cout<<"a-b="; 
        c.print(); 
        cout<<endl; 
        c=a+100; 
        cout<<"a+100="; 
        c.print(); 
        cout<<endl; 
        c=a-2.5; 
        cout<<"a-2.5="; 
        c.print(); 
        cout<<endl; 
        c=100+a; 
        cout<<"100+a="; 
        c.print(); 
        cout<<endl; 
        c=2.5-a; 
        cout<<"2.5-a="; 
        c.print(); 
        cout<<endl; 
        return  0; 
} 
