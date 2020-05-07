#include  <iostream> 
#include  <vector> 
using  namespace  std; 
class  Book 
{ 
//���ڴ˴�����Book��Ķ��� 
	public:
		Book();//��m_ID��ʼ��Ϊ0����ʾ���һ��δ��ֵ����
    	virtual ~Book();//�޾���Ĺ���
    	Book(const Book& other);//ʵ�����г�Ա�����Ŀ���
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
		unsigned int m_ID;//���
        string m_Name;//����
    	string m_Introduction;//���
    	string m_Author;//����
    	string m_Date;//���� 
    	unsigned int m_Page;//ҳ��
}; 
//���ڴ˴�����Book��ĳ�Ա����ʵ�� 
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
//���ڴ˴�����Store��Ķ��� 
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
//���ڴ˴�����Store��ĳ�Ա����ʵ�� 
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
        b1.SetName("C++  ���Գ������(��4��)"); 
        b1.SetAuthor("֣��"); 
        b1.SetIntroduction("����C++����������֪ʶ"); 
        b1.SetDate("201007"); 
        b1.SetPage(529); 
        b2.SetID(2); 
        b2.SetName("��ɢ��ѧ"); 
        b2.SetAuthor("��Т��"); 
        b2.SetIntroduction("���������߼���ν���߼��������ۡ�����ϵͳ��ͼ��"); 
        b2.SetDate("198209"); 
        b2.SetPage(305); 
        b3.SetID(3); 
        b3.SetName("c�������"); 
        b3.SetAuthor("̷��ǿ"); 
        b3.SetIntroduction("����C��������еĻ���֪ʶ��������ʽ���﷨��"); 
        b3.SetDate("201006"); 
        b3.SetPage(355); 

        cout<<"��һ�������"<<endl; 
        s.in(b1); 
        cout<<"�ڶ��������"<<endl; 
        s.in(b2); 
        cout<<"�����������"<<endl; 
        s.in(b3); 
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl; 
        cout  <<"���Ҳ�����ͼ�飺��ɢ��ѧ"  <<  endl; 
        Book  tmpbook=s.findbyName("��ɢ��ѧ"); 
        if(tmpbook.GetID()!=0) 
        { 
                s.out("��ɢ��ѧ"); 
                cout  <<"��ɢ��ѧ  �ѳɹ�����"  <<  endl; 
        } 
        else 
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl; 
        cout  <<"���п���鼮������"<<s.GetCount()  <<  endl; 

        cout  <<"����ͼ��  ID��3"  <<  endl; 
        tmpbook=s.findbyID(3); 
        if(tmpbook.GetID()!=0) 
                cout<<"�ҵ�IDΪ"<<3<<"���飬������"<<tmpbook.GetName()<<endl; 
        else 
                cout<<"û���ҵ�IDΪ"<<3<<"����"<<endl; 

        cout  <<"����ͼ��  name����ɢ��ѧ"  <<  endl; 
        tmpbook=s.findbyName("��ɢ��ѧ"); 
        if(tmpbook.GetID()!=0) 
                cout<<"�ҵ�nameΪ��ɢ��ѧ���飬ID��"<<tmpbook.GetID()<<endl; 
        else 
                cout<<"û���ҵ�nameΪ��ɢ��ѧ����"<<endl; 

        cout<<"������п��ͼ�����Ϣ"<<endl; 
        s.printList(); 
        cout<<"�������н���"<<endl; 
        return  0; 
} 

