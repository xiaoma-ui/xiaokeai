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
        Shape  s(1);//1��ʾID 
        Circle  c(4,2);//4��ʾ�뾶��2��ʾID 
        Rectangle  r(4,5,3);//4��5��ʾ���Ϳ�3��ʾID 
        cout<<"Shape�����"<<s.getArea()<<endl; 
        cout<<"Circle�����"<<c.getArea()<<endl; 
        cout<<"Rectangle�����"<<r.getArea()<<endl; 
}
