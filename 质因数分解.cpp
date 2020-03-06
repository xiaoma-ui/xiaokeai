#include<iostream>
#include  <cmath> 
using namespace std;
int  isPrime(long  num) 
{ 	int prime=1,i;
	if(num<=1)prime=0;
	for(i=2;i<num;i++)
	if(num%i==0)
	{prime=0;break;}
	return prime;
} 
void  factorization(long  n,long a[],int &m) 
{	int b;
	for(b=2;b<=n;b++)
	while(n%b==0)
	{a[m++]=b;n=n/b;}
	return;
}
int  main() 
{ 
        long  n; 
        long  factor[100]; 
        int  numofFactor  =  0; 
        cin  >>  n; 
        factorization(n,  factor,  numofFactor); 
        for  (int  i  =  0;  i  <  numofFactor;  i++) 
        { 
            cout  <<  factor[i]  <<  "  "; 
        } 
        cout  <<  endl; 
        return  0; 
}
