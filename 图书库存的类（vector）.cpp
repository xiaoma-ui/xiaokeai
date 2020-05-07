#include  <iostream> 
#include  <vector> 
using  namespace  std; 
class  Book 
{ 
//请在此处补充Book类的定义 
	public:
		Book();//将m_ID初始化为0，表示这个一个未赋值对象
    	virtual ~Book();//无具体的工作
    	Book(const Book& other);//实现所有成员变量的拷贝
    	void SetID(int id);
    	int GetID();
    	void SetName(string name);
    	string GetName();
    	void SetIntroduction(string introduction);
    	string GetIntroduction();
    	void SetAuthor(string author);
    	string GetAuthor();
    	void SetDate(string date);
    	string GetDate();
    	void SetPage(int page);
    	unsigned int GetPage();
	private:
		unsigned int m_ID;//编号
        string m_Name;//书名
    	string m_Introduction;//简介
    	string m_Author;//作者
    	string m_Date;//日期 
    	unsigned int m_Page;//页数
}; 
//请在此处补充Book类的成员函数实现 
Book::Book()
{
	m_ID=0;
}
Book::~Book()
{
	
}
Book::Book(const Book& other)
{
	m_ID=other.m_ID;
	m_Name=other.m_Name;
	m_Introduction=other.m_Introduction;
	m_Author=other.m_Author;
	m_Date=other.m_Date;
	m_Page=other.m_Page; 
}
void Book::SetID(int id)
{
	m_ID=id;
}
int Book::GetID()
{
	return m_ID;
}
void Book::SetName(string name)
{
	m_Name=name;
}
string Book::GetName()
{
	return m_Name;
}
void Book::SetIntroduction(string introduction)
{
	m_Introduction=introduction; 
}
string Book::GetIntroduction()
{
	return m_Introduction;
}    	
void Book::SetAuthor(string author)
{
	m_Author=author;
}
string Book::GetAuthor()
{
	return m_Author;
}    	
void Book::SetDate(string date)
{
	m_Date=date;
}	
string Book::GetDate()
{
	return m_Date;
}    	
void Book::SetPage(int page)
{
	m_Page=page;
}	
unsigned int Book::GetPage()
{
	return m_Page;
}	
class  Store 
{ 
//请在此处补充Store类的定义 
public:
		Store();
		Store(int n);
		virtual ~Store();
		Store(const Store& other);
		void in(Book &b);
		void out(string name);
		Book findbyID(int ID);
		Book findbyName(string name);
		void printList();
		unsigned int GetCount();
	private:
		vector<Book>m_Books;
}; 
//请在此处补充Store类的成员函数实现 
Store::Store()
{
	cout<<"Store default constructor called!"<<endl;
}
Store::Store(int n)
{
	m_Books.resize(n); 
	cout<<"Store constructor with (int n) called!"<<endl;
}
Store::~Store() 
{ 
	cout<<"Store destructor called!"<<endl;
}
Store::Store(const Store& other)
{
	m_Books.assign(other.m_Books.begin(),other.m_Books.end());
  	cout<<"Store copy constructor called!"<<endl;	
}
void Store::in(Book &b)
{ 
	m_Books.resize(m_Books.size()+1,b);
}
void Store::out(string name)
{ 	
	vector<Book>::iterator p=m_Books.begin(); 
  	while(p!=m_Books.end()) 
  	{
	  	if((*p).GetName()==name)
		p=m_Books.erase(p); 
   		p++;
	} 
}
Book Store::findbyID(int ID)
{ 
	vector<Book>::iterator p=m_Books.begin(); 
  	for(p=m_Books.begin();p!=m_Books.end();p++) 
  	if((*p).GetID()==ID)
  	{
	  return *p;
	  break;
	}
  	if(p==m_Books.end()) 
	  	return Book();	
} 
Book Store::findbyName(string name)
{ 	
	vector<Book>::iterator p=m_Books.begin(); 
  	for(p=m_Books.begin();p!=m_Books.end();p++) 
  	if((*p).GetName()==name)
  	{
	  	return *p;
		break;
	}
  	if(p==m_Books.end()) 
	  	return Book();	
}
void Store::printList()
{ 
	cout<<"There are totally "<<m_Books.size()<<" Books:"<<endl; 
  	vector<Book>::iterator p = m_Books.begin(); 
  	while(p!=m_Books.end()) 
  	{
	  	cout<<"ID="<<(*p).GetID()<<";" ;
   		cout<<"  Name:"<<(*p).GetName()<<";";  
   		cout<<"  Author:"<<(*p).GetAuthor()<<";";   
   		cout<<"  Date:"<<(*p).GetDate()<<";"<<endl;
   		p++;
	}	
} 
unsigned int Store::GetCount() 
{ 
	return m_Books.size();
}
int  main() 
{ 
        Store  s; 
        Book  b1,b2,b3; 
        b1.SetID(1); 
        b1.SetName("C++  语言程序设计(第4版)"); 
        b1.SetAuthor("郑莉"); 
        b1.SetIntroduction("介绍C++及面向对象的知识"); 
        b1.SetDate("201007"); 
        b1.SetPage(529); 
        b2.SetID(2); 
        b2.SetName("离散数学"); 
        b2.SetAuthor("左孝凌"); 
        b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论"); 
        b2.SetDate("198209"); 
        b2.SetPage(305); 
        b3.SetID(3); 
        b3.SetName("c程序设计"); 
        b3.SetAuthor("谭浩强"); 
        b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等"); 
        b3.SetDate("201006"); 
        b3.SetPage(355); 

        cout<<"第一本书入库"<<endl; 
        s.in(b1); 
        cout<<"第二本书入库"<<endl; 
        s.in(b2); 
        cout<<"第三本书入库"<<endl; 
        s.in(b3); 
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl; 
        cout  <<"查找并出库图书：离散数学"  <<  endl; 
        Book  tmpbook=s.findbyName("离散数学"); 
        if(tmpbook.GetID()!=0) 
        { 
                s.out("离散数学"); 
                cout  <<"离散数学  已成功出库"  <<  endl; 
        } 
        else 
                cout<<"没有找到name为离散数学的书"<<endl; 
        cout  <<"现有库存书籍数量："<<s.GetCount()  <<  endl; 

        cout  <<"查找图书  ID：3"  <<  endl; 
        tmpbook=s.findbyID(3); 
        if(tmpbook.GetID()!=0) 
                cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl; 
        else 
                cout<<"没有找到ID为"<<3<<"的书"<<endl; 

        cout  <<"查找图书  name：离散数学"  <<  endl; 
        tmpbook=s.findbyName("离散数学"); 
        if(tmpbook.GetID()!=0) 
                cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl; 
        else 
                cout<<"没有找到name为离散数学的书"<<endl; 

        cout<<"输出所有库存图书的信息"<<endl; 
        s.printList(); 
        cout<<"程序运行结束"<<endl; 
        return  0; 
} 

