#include<iostream>
using namespace std;
int main()
{	char a[9];int i,j,k,m,n=0;
	for(i=1;i<=8;i++)
	cin>>a[i];
	for(i=1;i<=8;i++)
	a[i]=a[i]-'0';
	for(i=1;i<=8;i++)
	if(a[i]=='*')
	m=i;
	for(i=1;i<=8;i++)
	{for(j=1,k=0;j<=8;j++)
	{if(i!=a[j])k++;
	else continue;
	}if(k==8)n=i;
	}
	a[m]=n;
	int x,y;
	for(x=1;x<=7;x++)
	for(y=x+1;y<=8;y++)
	if((a[y]-a[x]==y-x)||(a[x]-a[y]==y-x)) k=0;
	if(k==0)cout<<"No Answer"<<endl;
	else cout<<n<<endl;
	return 0; 	
}
