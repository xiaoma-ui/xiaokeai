#include <iostream>
#include <iomanip>
#include<stdlib.h>
using namespace std;
typedef int elementType;
typedef struct node
{
    elementType data;
    node* next;
} LList, *PList;

class linkedList
{
public:
    linkedList();
    virtual ~linkedList();
    void insert( int value );
    bool initiate();
    bool isEmpty();
    bool remove( int pos, int& value );
    void print();
    int Length();
private:
    LList *head;
    int len;
};
linkedList::linkedList() 
{
	len=0;
	head=(LList*)malloc(sizeof(LList));
	head->next=NULL;
}
linkedList::~linkedList()
{ 
	if(initiate()) 
  	{
	  	LList* p=head->next;
   		LList* q;
   		free(head);
   		while(p)
   		{	
		   	q=p;
			p=p->next;
			free(q);
		}
	}
}
void linkedList::insert(int value)
{ 	
	if(initiate()) 
  	{
	  	LList* p=(LList*)malloc(sizeof(LList));
   		p->data=value;
   		LList* m=head->next;
		LList* n=head;
   		while(m)
   		{
		   n=m;
		   m=m->next;
		}
   		p->next=n->next;
		n->next=p;   
  	}
}  
bool linkedList::initiate() 
{ 
	LList *head=new LList;
  	if(head==NULL) return false;
  	else return true;
}
bool linkedList::isEmpty()
{ 
	if(head->next!=NULL) return false;
  	else return true;
} 
bool linkedList::remove(int pos,int& value) 
{ 
	len=Length(); 
  	if(pos<=0)
  	{
	  	cout<<"pos <= 0, failed"<<endl;
	  	return false;
	}
	else if(len==0)
  	{
	 	cout<<"len == 0, failed"<<endl;
	  	return false;
	}
  	else if(pos>len)
  	{
	  cout<<"pos > len, failed"<<endl;
	  return false;
	}	
   	LList* p=head->next;
   	LList *q=head;
	int l=1;
   	while(l!=pos)
	{
		l++;
		q=p;
		p=p->next;
	}
   	value=p->data;
	q->next=p->next;
	free(p);
   	return true; 	
	}
int	linkedList::Length() 
{ 
	int l=0;
  	LList* p=head->next;
  	while(p)
  	{
	  	l++;
		p=p->next;
	}
  	if(!l) return -1;
  	else return l;
}
void linkedList::print()
{
    if( isEmpty() )
    {
        cout << "Empty" << endl;
        return;
    }
    LList* tmp = head->next;
    while(tmp)
    {
        cout <<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout << endl;
}
int main(int argc, char* argv[])
{
    linkedList L1;
    int n;
    int val;
    //��ʼ������
    if(!L1.initiate())
        return 0;

    cin>>n;//�������������ݸ���
    for(int i=0; i<n; i++) //����n����������������
    {
        cin>>val;
        L1.insert(val);
    }
    cout << "Origin Length��" << L1.Length() << endl;//���������
    cout << "data��" ;
    L1.print();//��ӡ����

    cin>>n;//������Ҫɾ�������ݵ�λ��
    if (L1.remove(n,val))
    {
        //ɾ��λ��n�����ݣ�����ɾ��������ֵ����val��
        cout<<"Delete the data at position("<<n<<"):"<<val<<endl;
        cout<< "New Length��" << L1.Length()<< endl;//���������
        cout<< "data��" ;
        L1.print();//��ӡ����
    }

    return 0;
}

