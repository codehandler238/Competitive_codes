1-Only static const varaibles can be initialized inside a class.
2-When an object is declared along with its class first entire parent chain constructors are called
3-If there is a reference in class it needs to be initialized using initialization list
4-Conversion operator convert object to a different type
syntax-
operator return type() {return ___}
5-When we make a function virtual, compiler adds an extra pointer vptr to objects of the class.
The extra pointer vptr adds to the size of objects.(If a class have more than one virtual functions then also Only
one vptr is added)
6-When a nested is used '>>' cause an error '> >'is correct.
7-
class Test{
	static int count;
}
int Test::count=0;
int main()
{
	Test a;
}
Works fine.if initialization occur inside main it causes error.initialization must occur outside the class.without initialization program also works.
8-this pointer is not available to static member methods in C++, as static methods can be called using class name also.
9-In C++, if a class has a constructor which can be called with a single argument, 
then this constructor becomes conversion constructor because such a constructor allows automatic conversion to the class being constructed.
10-reference to private members of a class can be returned.
11-
class Test{
public:
	int a;
	Test(int i=0):a(i){}
	Test(const Test& t):a(t.a){}
};
int main()
{
	Test t;
	cout<<t.a<<" ";
	t.a=2;
	Test tmp=t;
	cout<<tmp.a<<endl;
}
Works perfectly fine.
12-Objects are always destroyed in reverse order of their creation.
13- An inherited class can not access private data members of the parent class.
14- A const object can only call const functions.
15-
class Base {
   protected:
      int x;
   public:
      Base (int i){ x = i;}
};
 
class Derived : public Base {
   public:
      Derived (int i):Base(i) { } Derived class can not directly initialize protected member.
      void print() { cout << x; }
};
16-
t2 = t1;  calls assignment operator, same as "t2.operator=(t1);" Test& operator = (const Test &t)
Test t3 = t1;  calls copy constructor, same as "Test t3(t1);" Test(const Test &t)
17-In tempaltes value of nontype parameters must be constant.