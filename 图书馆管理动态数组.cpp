#include  <iostream> 
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
		Book *m_pBook;//ָ������new������̬������Book����
    	unsigned int m_Count;//��ʾ�����ͼ�������
}; 
//���ڴ˴�����Store��ĳ�Ա����ʵ�� 
Store::Store()
{
	m_Count=0;
	m_pBook=NULL;
	cout<<"Store default constructor called!"<<endl;
}
Store::Store(int n)
{
	m_Count=n;
	float *m_pBook=new float[n]; 
	cout<<"Store constructor with (int n) called!"<<endl;
}
Store::~Store()
{
	m_Count=0;
	if(m_pBook)
	{
		delete []m_pBook;
		cout<<"Store destructor called!"<<endl;
	}
}
Store::Store(const Store& other)
{
	unsigned int i;
	m_Count=other.m_Count; 
  	for(i=0;i<m_Count;i++)
  	{
	  	m_pBook[i].SetID (other.m_pBook[i].GetID());
   		m_pBook[i].SetName(other.m_pBook[i].GetName());
   		m_pBook[i].SetAuthor(other.m_pBook[i].GetAuthor());
   		m_pBook[i].SetIntroduction(other.m_pBook[i].GetIntroduction());
   		m_pBook[i].SetDate(other.m_pBook[i].GetDate());
   		m_pBook[i].SetPage(other.m_pBook[i].GetPage());
	}
	cout<<"Store copy constructor called!"<<endl;
}
void Store::in(Book &b)
{  
	unsigned int i;
	Book *s1=new Book[m_Count+1];
   	m_Count;  
   	s1[m_Count].SetID(b.GetID());
   	s1[m_Count].SetName(b.GetName());
   	s1[m_Count].SetAuthor(b.GetAuthor());
   	s1[m_Count].SetIntroduction(b.GetIntroduction());
   	s1[m_Count].SetDate(b.GetDate());
   	s1[m_Count].SetPage(b.GetPage());
  	for(i=0;i<m_Count;i++)
  	{
	  	s1[i].SetID(m_pBook[i].GetID());
   		s1[i].SetName(m_pBook[i].GetName());
   		s1[i].SetAuthor(m_pBook[i].GetAuthor());
   		s1[i].SetIntroduction(m_pBook[i].GetIntroduction());
   		s1[i].SetDate(m_pBook[i].GetDate());
   		s1[i].SetPage(m_pBook[i].GetPage());
	}  
   	m_Count++;
  	delete []m_pBook;
  	m_pBook=s1;  
}
void Store::out(string name)
{ 
 	unsigned int i,j=m_Count,k;
	Book *s2=new Book[m_Count-1];
  	for(i=0;i<m_Count;i++)
  	if(name==m_pBook[i].GetName()) j=i; 
  	for(i=0,k=0;i<m_Count-1;i++,k++) 
  	{
  		if(k==j)
  		{
  			i--;
  			continue;
		}
	  	s2[i].SetID(m_pBook[k].GetID());
   		s2[i].SetName(m_pBook[k].GetName());
   		s2[i].SetAuthor(m_pBook[k].GetAuthor());
   		s2[i].SetIntroduction(m_pBook[k].GetIntroduction());
   		s2[i].SetDate(m_pBook[k].GetDate());
   		s2[i].SetPage(m_pBook[k].GetPage());
	}
  	m_Count--;
  	delete[] m_pBook;
  	m_pBook=s2; 
} 
Book Store::findbyID(int ID)
{ unsigned int i;
  for(i=0;i<m_Count;i++)
  if(m_pBook[i].GetID()==ID) {return m_pBook[i];break;}
  if(i==m_Count) return Book();
}  
Book Store::findbyName(string name) 
{ unsigned int i;
  for(i=0;i<m_Count;i++)
  if(name==m_pBook[i].GetName()) {return m_pBook[i];break;}
  if(i==m_Count) return Book();
}
void Store::printList()
{ unsigned int i;
  cout<<"There are totally "<<m_Count<<" Books:"<<endl;
  for(i=0;i<m_Count;i++)
  {cout<<"ID="<<m_pBook[i].GetID()<<";" ;
   cout<<"  Name:"<<m_pBook[i].GetName()<<";";  
   cout<<"  Author:"<<m_pBook[i].GetAuthor()<<";";   
   cout<<"  Date:"<<m_pBook[i].GetDate()<<";"<<endl;}
} 
unsigned int Store::GetCount()
{
	return m_Count;
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

