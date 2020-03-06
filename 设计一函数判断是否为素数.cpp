#include  <iostream> 
#include  <cmath> 
using  namespace  std; 
    int isPrime(int a) 
	{	int prime=1,i;
		if(a<=1)prime=0;
		for(i=2;i<a;i++)
		if(a%i==0)
		{prime=0;break;}
		return prime;
}
	int main()
    {
	unsigned  short  a; 
    cin>>a; 
    if  (isPrime(a)) 
    	cout<<"Y"<<endl; 
    else 
	    cout<<"N"<<endl; 
}
