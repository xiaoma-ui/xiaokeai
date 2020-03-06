#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
int main()
{
	char a[10],b[10];
	int i,j,k,min=25,m,n;
	cin>>a;cin>>b;
	m=strlen(a);
	n=strlen(b);
	for(i=0;i<m;i++)
		if('A'<=a[i]&&a[i]<='Z')
		a[i]=a[i]+32;
	for(i=0;i<n;i++)
		if('A'<=b[i]&&b[i]<='Z')
		b[i]=b[i]+32;
	
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
		k=abs(a[i]-b[j]); 
		if(k<min)min=k;
	}
	cout<<min<<endl;
	return 0;
}
