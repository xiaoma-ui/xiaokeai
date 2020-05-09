#include  <iostream> 
using  namespace  std; 
//请在这里补充CPoint，CRectangle类的定义 
class CPoint
{ 	public:
		CPoint(int xx=0,int yy=0);
		CPoint(const CPoint &p); 
		int GetX(){return x;}
		int GetY(){return y;}
	private:
		int x,y; 
};
class CRectangle
{
	public:
		CRectangle();
		CRectangle(CPoint p1,CPoint p2);
		CRectangle(int x1,int y1,int x2,int y2);
		CRectangle(const CRectangle& p);
		int GetArea();
	private:
		CPoint p3,p4;
};
CPoint::CPoint(int xx,int yy)
{	x=xx;
	y=yy;	
	cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
}
CPoint::CPoint(const CPoint &p)
{	x=p.x;
	y=p.y;
	cout<<"CPoint copy contstructor is called."<<endl;
}
CRectangle::CRectangle()
{ cout<<"CRectangle default contstructor is called."<<endl;}
CRectangle::CRectangle(CPoint p1,CPoint p2):p3(p1),p4(p2)
{
 	cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
} 
CRectangle::CRectangle(int x1,int y1,int x2,int y2):p3(x1,y1),p4(x2,y2)
{
	cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
}
CRectangle::CRectangle(const CRectangle& p):p3(p.p3),p4(p.p4)
{
	cout<<"CRectangle copy contstructor is called."<<endl;
}
int CRectangle::GetArea() 
{
	int area=0,a,b;
	a=p3.GetX()-p4.GetX();b=p3.GetY()-p4.GetY();
	area=a*b;
	if(area<0) 
		return(0-area);
	else 
		return area;
}
int  main() 
{ 
	int  a=1,  b=1,  c=6,  d=11; 
	cout<<"#  Define  p1  ######"<<endl; 
    CPoint  p1; 
    cout<<"#  Define  p2  ######"<<endl; 
    CPoint  p2(10,20); 
    cout<<"#  Define  rect1  ######"<<endl; 
        CRectangle  rect1; 
        cout<<"#  Define  rect2  ######"<<endl; 
        CRectangle  rect2(p1,  p2); 
        cout<<"#  Define  rect3  ######"<<endl; 
        CRectangle  rect3(a,  b,  c,  d); 
        cout<<"#  Define  rect4  ######"<<endl; 
        CRectangle  rect4(rect2); 
        cout<<"#  Calculate  area  ######"<<endl; 
        cout  <<  "rect1面积为"  <<  rect1.GetArea()  <<  endl; 
        cout  <<  "rect2面积为"  <<  rect2.GetArea()  <<  endl; 
        cout  <<  "rect3面积为"  <<  rect3.GetArea()  <<  endl; 
        cout  <<  "rect4面积为"  <<  rect4.GetArea()  <<  endl; 
        system("pause"); 
        return  0; 
} 

