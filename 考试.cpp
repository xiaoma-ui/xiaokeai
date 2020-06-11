#include <iostream>
using namespace std;
class watch
{
public:
    watch()
    {
        m_hour = 0;
        m_min = 0;
        m_sec = 0;
        cout << "watch default constructor called" << endl;        
    }
    watch(int h, int m, int s)
    {
        m_hour = h;
        m_min = m;
        m_sec = s;
        cout << "watch constructor called" << endl;
    }

    //ע�Ᵽ����Ա���Թ��м̳з�ʽ���̳�ʱ��������������Ȼ�Ǳ�����Ա�����������������ڷ��ʣ����ǲ�����������ʡ�
protected:
    int m_hour; //Сʱ
    int m_min;  //����
    int m_sec;  //����
};

//������watchDerived�����
class watchDerived : public watch
{
    //�벹��������watchDerived�����
    public:
		watchDerived();
    	watchDerived(int h, int m, int s);
    	void setzero();
		watchDerived& operator++ ();
		watchDerived operator++ (int);
    	friend ostream &operator<<(ostream &, const watchDerived &);
    	friend istream &operator>>(istream &,  watchDerived &);
};
watchDerived::watchDerived():watch()
{
	cout<<"watchDerived default constructor called"<<endl;
}
watchDerived::watchDerived(int h,int m,int s):watch(h,m,s)
{  	
	cout<<"watchDerived constructor called"<<endl;
}
void watchDerived::setzero()
{
	m_hour=m_min=m_sec=0;
}
watchDerived& watchDerived::operator++ ()
{
	m_sec++;
	if(m_sec>=60)
	{
		m_sec-=60;
		m_min++;
		if(m_min>=60)
		{
			m_min-=60;
			m_hour=(m_hour+1)%12;
		}
	}
	return *this;
}
watchDerived watchDerived::operator++ (int)
{
	watchDerived old=*this;
	++(*this);
	return old;
}
//������������watchDerived��<<����������غ���
ostream &operator<<(ostream &out, const watchDerived &s)
{
	out<<s.m_hour<<":"<<s.m_min<<":"<<s.m_sec;
	return out;
}
istream &operator>>(istream & in,  watchDerived &s)
{
    in>> s.m_hour >> s.m_min >> s.m_sec;
    return in;
}
int main()
{
    watchDerived s1, s2(11, 59, 59);

    s1 = s2++;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    s1.setzero();
    s2.setzero();

    s1 = ++s2;
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    cin>>s1;
    cout << "s1: " << ++s1 << endl;

    return 0;
}
	
