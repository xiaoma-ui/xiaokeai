#include  <iostream> 
using  namespace  std; 
const  float  pi=3.14159; 
class Shape
{
	public:
		int GetID();
		float getArea(){return 0;}
		Shape();
		Shape(int a);
		virtual ~Shape();
	private:
		int m_ID; 
};
int Shape::GetID()
{
	return m_ID;
}
Shape::Shape(int a)
{
	m_ID=a;
	cout<<"Shape constructor called:"<<GetID()<<endl;
}
Shape::~Shape()
{
	cout<<"Shape destructor called:"<<GetID()<<endl;
}
class Circle:private Shape
{
	public:
		float getArea(){return pi*r*r;}
		Circle();
		Circle(int a,int ID);
		virtual ~Circle();
	private:
		int r;
};
Circle::Circle(int a,int ID):Shape(ID)
{
	cout<<"Circle constructor called:"<<GetID()<<endl;
	r=a;
}
Circle::~Circle()
{
	cout<<"Circle destructor called:"<<GetID()<<endl;
}
class Rectangle:public Shape
{
	public:
		float getArea(){return (h*w);}
		Rectangle();
		Rectangle(int a,int b,int ID);
		virtual ~Rectangle();
	private:
		int h,w;
};
Rectangle::Rectangle(int a,int b,int ID):Shape(ID)
{
	h=a;w=b;
	cout<<"Rectangle constructor called:"<<GetID()<<endl;
}
Rectangle::~Rectangle()
{
	cout<<"Rectangle destructor called:"<<GetID()<<endl;
}

int  main() 
{ 
        Shape  s(1);//1表示ID 
        Circle  c(4,2);//4表示半径，2表示ID 
        Rectangle  r(4,5,3);//4和5表示长和宽，3表示ID 
        cout<<"Shape的面积"<<s.getArea()<<endl; 
        cout<<"Circle的面积"<<c.getArea()<<endl; 
        cout<<"Rectangle的面积"<<r.getArea()<<endl; 
}
