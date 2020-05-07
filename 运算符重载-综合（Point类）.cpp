#include  <iostream> 
using  namespace  std; 
class Point
{
	public:
		Point(int x,int y);
		int getx()const{return m_x;}
		int gety()const{return m_y;}
		Point& operator++();
		Point operator++(int);
		friend ostream& operator<<(ostream& x,const Point& c);
	private:
		int m_x;
		int m_y;
}; 
Point::Point(int x,int y)
{
	m_x=x;
	m_y=y;
}
Point& Point::operator++()
{
	m_x++;
	m_y++;
	return *this;
}
Point Point::operator++(int)
{
	Point old=*this;
	++(*this);
	return old;
}
ostream& operator<<(ostream& x,const Point& c)
{
	x<<"("<<c.getx()<<","<<c. gety()<<")"<<endl;
	return x;
}
int  main() 
{ 
        Point  a(1,3); 
        cout<<a; 
        cout<<a++; 
        cout<<++a; 
        return  0; 
}
