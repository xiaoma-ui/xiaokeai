#include<iostream>
using namespace std;
int main()
{ 	
	int a[3][3],b[3][3],c[3][3],i,j,k,t;
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	cin>>a[i][j];
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	cin>>b[i][j];
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		t=0;
		for(k=0;k<3;k++)
			t=t+a[i][k]*b[k][j];
		c[i][j]=t;
	}
	for(i=0;i<3;i++)
	{
	for(j=0;j<3;j++)
	cout<<c[i][j]<<" ";
	cout<<endl;
	}
	return 0;
}


