#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	short stu_id,score;
};
int main()
{
	int n,i;
	cin>>n;
	student* a=new student[n];
	student* b=new student[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i].stu_id;
		cin>>a[i].score;
	}	
	ofstream file1("out.txt",ios::binary);
	file1.write((char*)a,sizeof a);
	file1.close();
	ifstream file2("out.txt",ios::binary);
	for(i=0;i<n;i++)
	file2.read((char*)&b[i],sizeof(b[i]));
	file2.close();
	ofstream file3("out.txt",ios::out | ios::ate);
	file3.write((char*)b,sizeof b);
	delete a;
	delete b;
	file3.close();
}
