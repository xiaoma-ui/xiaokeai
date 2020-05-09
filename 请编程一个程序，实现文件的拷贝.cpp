#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	double a[1000];double b;
	int i=0,j,k=0;
	ifstream file1("a.txt",ios::in);
	ofstream file2("b.txt",ios::out);
	if(file1)
	{ 
    while(!file1.fail())
	{
		file1>>a[i];
		i++;	
	}
	k=i-1;
	}
  	file1.close(); 
  	for(i=0;i<k-1;i++)
 	for(j=0;j<k-1-i;j++)
	if(a[j]>a[j+1])
	{
		b=a[j];
		a[j]=a[j+1];
		a[j+1]=b;
	}
  	for(i=0;i<k;i++)
 	{
	 	file2<<a[i]<<" ";
	}
	file2.close(); 
}
