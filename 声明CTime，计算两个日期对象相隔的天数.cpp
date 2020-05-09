#include<iostream>
#include<cmath>
using namespace std;
class CTime
{
	public:
		CTime(int year1,int month1,int day1,int hour1=0,int minute1=0,int second1=0);
		CTime(const CTime& t);
		~CTime();
		int dayDiff(CTime t);
		int dateDiff(int year2,int month2,int day2);
		int leapyear(int k);
		int isvalid();
		int time(int a,int b,int c);
		int date(int d,int e,int f);
		void showTime();
	private:
		int year,month,day,hour,minute,second;
};
CTime::CTime(int year1,int month1,int day1,int hour1,int minute1,int second1)
{
	if(time(hour1,minute1,second1)&&(date(year1,month1,day1)))
	{
		cout<<"date and time error!"<<endl;
		year=month=day=hour=minute=second=0;
	}
	
	else if(time(hour1,minute1,second1)) 
	{
		cout<<"time error!"<<endl;
		year=month=day=hour=minute=second=0;
	}
	else if(date(year1,month1,day1))
	{
	 	cout<<"date error!"<<endl;
	 	year=month=day=hour=minute=second=0;
	}
	else
	{
		year=year1;
		month=month1;
		day=day1;
		hour=hour1;
		minute=minute1;
		second=second1;		
	}
	cout<<"构造函数被调用"<<endl; 
}
CTime::CTime(const CTime& t)
{
	year=t.year;
	month=t.month;
	day=t.day;
	hour=t.hour;
	minute=t.minute;
	second=t.second;
	cout<<"拷贝构造函数被调用"<<endl; 
} 
CTime::~CTime()
{
	cout<<"析构函数被调用"<<endl; 
}
int CTime::dayDiff(CTime t)
{
	int cha1,cha2,cha3;
    cha1=dateDiff(t.year,t.month,t.day);
    cha2=dateDiff(year,month,day);
    cha3=abs(cha1-cha2);
    return cha3;
}
int CTime::dateDiff(int year2,int month2,int day2)
{
	int cha;int February;
	if(leapyear(year2)) February=29;
    else   February=28;
    year2-=1;
    cha=year2*365+year2/4-year2/100+year2/400+day2;
	switch(month2-1)
	{
		case 11:cha+=30;
		case 10:cha+=31;
		case 9:cha+=30;
		case 8:cha+=31;
		case 7:cha+=31;
		case 6:cha+=30;
		case 5:cha+=31;
		case 4:cha+=30;
		case 3:cha+=31;
		case 2:cha+=February;
		case 1:cha+=31;
		case 0:break;
	}
	return cha;
}
int CTime::leapyear(int k)
{
	if(((year%4==0)&&(year%100!=0))||(year%400==0))
		return 1;
	else 
		return 0;
}
int CTime::isvalid()
{   
	if(time(hour,minute,second)||(date(year,month,day)))
		return 0;
    else 
		return 1;
}
int CTime::time(int a,int b,int c) 
{
	if((a>=0&&a<=23)&&(b>=0&&b<=59)&&(c>=0&&c<=59))
		return 0;
	else 
		return 1;
}
int CTime::date(int d,int e,int f)
{   
	int g;
    if(leapyear(d))  g=29;
    else   g=28;
    if((d<0)||(e<=0)||(e>=13)||(f<=0)||(f>=32)) 
		return 1;
    switch(e)
	{
    	case 1: case 3: case 5: case 7: case 8: case 10: case 12:    
		{
			if(f>=1&&f<=31) return 0;
			else return 1;
			break;
		}
    	case 4: case 6: case 9: case 11:
		{
			if(f>0&&f<=30) return 0;
			else return 1;
			break;
		}
		case 2:
		{ 
			if(f>0&&f<=g) return 0;
			else return 1;
		}	break;
   }       
}
void CTime::showTime()
{
	cout<<year<<"/"<<month<<"/"<<day<<" "<<hour<<":"<<minute<<":"<<second<<endl;
}                    
int main() 
{
        int year,month,day,hour,minute,second; 
        cin>>year>>month>>day>>hour>>minute>>second; 
        CTime t1(year,month,day,hour,minute,second); 
        t1.showTime(); 
        CTime t2(2000,1,1);  //利用默认形参将时间初始化为00:00:00 
        if  (t1.isvalid())          //如果日期和时间合法，则计算天数 
        { 
                int days=0; 
                days=t1.dayDiff(t2); 
                cout<<"这两天之间相隔了"<<days<<"天"<<endl; 
                days=t2.dayDiff(t1); 
                cout<<"这两天之间相隔了"<<days<<"天"<<endl; 
        } 
} 
