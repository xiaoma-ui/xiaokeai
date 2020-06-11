#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Array
{
//请完成类的设计
public:
	vector<T>Arr;
	Array(int n){}
	void input(int n)
	{
		for(int i=0;i<n;i++)
		{
			T a;
			cin>>a;
			Arr.push_back(a);
		}
	}
	T&operator[](int n) {return Arr[n];}
};
class Fract
{
//请完成类的设计
public:
	int n,m;
	Fract(int a=0,int b=0)
	{
		int min,i,x=1;
		if(a*b<0) x=-1;
		if(a<0) a=-a;
		if(b<0) b=-b;
		if(a<b)min=a;
		else min=b;
		for(i=min;i>1;i--)
		if((a%i==0)&&(b%i==0))
		{
			a=a/i;b=b/i;
		}
		n=a*x;m=b;
	}
	void show()
	{
		if(n==0||m==1)
			cout<<n<<endl;
		else
		{
			cout<<n<<"/"<<m<<endl;
		}
	}
	Fract&operator +=(Fract& p)
	{
		Fract c(p.n*m+p.m*n,p.m*m);	
		return*	this=c;
	}
	friend istream &operator>>(istream &i,Fract &f)
	{
		int f1,f2;
		i>>f1>>f2;
		Fract d(f1,f2);
		f.n=d.n;f.m=d.m;
		return i;
	}
};				
int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;
    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for (unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}

