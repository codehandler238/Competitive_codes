#include<iostream>
using namespace std;
class Shape{
	protected:
	double height,width;

	public :virtual double get_area()=0;//pure virtual function.
};
class Rectangle : public Shape{
	public : Rectangle(double a,double b)
	{
		height=a;
		width=b;
	}
	public :double get_area()
	{
		return (height*width);
	}
};
int main()
{
	Rectangle rect(10,20);
	Shape *shape;
	shape=&rect;

	cout<<shape->get_area()<<endl;
}