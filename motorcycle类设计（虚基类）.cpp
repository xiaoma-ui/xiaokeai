#include  "iostream" 
using  namespace  std; 
class vehicle
{ 
	public:
		void run();
		void stop();
		vehicle(int c,int d);
		~vehicle();
	private:
		int maxspeed,weight;	
};
void vehicle::run()
{
	cout<<"vehicle run"<<endl;
}
void vehicle::stop()
{
	cout<<"vehicle stop"<<endl;
}
vehicle::vehicle(int c,int d)
{
	maxspeed=c;weight=d;
	cout<<"vehicle constructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
}
vehicle::~vehicle()
{
	cout<<"vehicle destructor called. maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
}
class bicycle:virtual public vehicle
{
	public:
		bicycle(int a,int b,int c);
		~bicycle();
	private:
		int height;
}; 

bicycle::bicycle(int a,int b,int c):vehicle(a,b)
{
	height=a;
	cout<<"bicycle constructor called. height:"<<height<<endl;
}
bicycle::~bicycle()
{
	cout<<"bicycle destructor called. height:"<<height<<endl;
}

class motorcar:virtual public vehicle
{
	public:
		motorcar(int a,int b,int c);
		~motorcar();
	private:
		int seatnum;
};

motorcar::motorcar(int a,int b,int c):vehicle(a,b)
{
	seatnum=a;
	cout<<"motorcar constructor called. seatnum:"<<seatnum<<endl;
}
motorcar::~motorcar()
{
	cout<<"motorcar destructor called. seatnum:"<<seatnum<<endl;
	
}
class motorcycle:virtual public bicycle,virtual public motorcar
{
	public:
		motorcycle(int a,int b,int c,int d);
		~motorcycle();
};
motorcycle::motorcycle(int a,int b,int c,int d):bicycle(a,c,d),motorcar(b,c,d),vehicle(c,d)
{
	cout<<"motorcycle constructor called"<<endl;
}
motorcycle::~motorcycle()
{
	cout<<"motorcycle destructor called"<<endl;
}


int  main(int  argc,  char  *argv[]) 
{ 
        motorcycle  m(1,  2,  3,  4);//1表示height，2表示seatnum，3表示maxspeed，4表示weight 
        m.run(); 
        m.stop(); 
        return  0; 
}

