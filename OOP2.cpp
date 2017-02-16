#include<iostream>
using namespace std;
class Test{
public:
	int a;
	Test(){}
	Test(int b){a=b;}
	Test(const Test & b){a=b.a;}
	Test& operator = (const Test & b){return *this;}
};
int main()
{
	Test p=10;
	Test q;
	q=p;
	q=20;
	//p=20;
	cout<<p.a<<endl;
	cout<<q.a<<endl;
}
