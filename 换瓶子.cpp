#include<iostream>
using namespace std;
int shui(int a,int b,int c);
int main()
{
	int m,p;
	cin>>m;
	p=shui(m,m,m);
	cout<<p<<endl;	 
	return 0;
} 
	int shui(int a,int b,int c)
{	int d,e;
	if(b<2&&c<3) return a;
	d=b/2+c/3;
	a=a+d;
	b=d+b%2;c=d+c%3;
	e=shui(a,b,c);
	return e;
}
