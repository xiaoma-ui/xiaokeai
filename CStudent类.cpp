#include<iostream> 
#include<string> 
using namespace std; 
class CStudent 
{ 
	public:
		static int count;
		static int getcount();
		CStudent();
		CStudent(string x,int y);
		~CStudent();
		void printname(); 	
	private:
		string name;
		int age;
		
}; 
//���������ʼ��̬��Ա����
int CStudent::count=0;
int CStudent::getcount()
{
	return count;
}
CStudent::CStudent(string x,int y)
{
	count++;
	name=x;
	age=y;
	cout<<name<<" is contructing"<<endl; 
}
CStudent::CStudent()
{
	count++;
	name="noname";
	cout<<name<<" is contructing"<<endl; 
}
CStudent::~CStudent()
{
	count--;
	cout<<name<<" is destructing"<<endl;
}
void CStudent::printname()
{
	cout<<"name:"<<name<<endl; 
}
int main() 
{ 
    cout<<"������ѧ��"<<CStudent::getcount()<<endl; 
	{ 
    	CStudent stuB[5]; 
        stuB[4].printname(); 
        cout<<"������ѧ��"<<CStudent::getcount()<<endl; 
    } 
    cout<<"������ѧ��"<<CStudent::getcount()<<endl; 
    { 
    	CStudent stuA[2]={CStudent("Tom",3),CStudent("Jerry",2)}; 
        for (int i=0;i<2;i++) 
        { 
            stuA[i].printname(); 
        } 
        cout<<"������ѧ��"<<CStudent::getcount()<<endl; 
    } 
    cout<<"������ѧ��"<<CStudent::getcount()<<endl; 
    return 0; 
}



























