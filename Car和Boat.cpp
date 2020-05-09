#include  <iostream> 
using  namespace  std; 
//请在这里补充类Boat和Car的定义 
class Car;
class Boat
{
public:
	Boat(int x);
	friend int totalweight(Boat& b,Car& c);
private:
	int weight;
};
Boat::Boat(int x)
{weight=x;
}
class Car
{
public:
	Car(int y);
	friend int totalweight(Boat& b, Car& c);
private:
	int weight;
};
Car::Car(int y)
{weight=y;
}

int  totalweight(Boat& b,Car& c) 
{ 
        return  b.weight+c.weight; 
} 
int  main() 
{ 
        Boat  b(100); 
        Car  c(200); 
        cout<<totalweight(  b,  c)<<endl; 
        return  0; 
} 


