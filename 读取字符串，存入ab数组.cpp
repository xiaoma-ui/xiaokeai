#include <iostream> 
using namespace std; 
int main()
{
int i=0;
char a[10]={'\0'},b[10]={'\0'},c;
for(i=0;
i<10&&a[i]!='\n';
i++)
{c=cin.get();if(c=='\n')break;else a[i]=c;
if (a[i]<='Z'&&a[i]>='A')a[i]=a[i]+32;}
for(i=0;i<10&&b[i]!='\n';i++)
{c=cin.get();if(c=='\n')break;else b[i]=c;
if (b[i]<='Z'&&b[i]>='A') b[i]=b[i]+32;}
cout<<a<<endl;
cout<<b<<endl;
} 
