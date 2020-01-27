#include<iostream>
using namespace std;
 
class A
{
  int x;
public:
  A() { x = 0; }
  A(int i) { x = i; }
  void print() { cout << x; }
};
 
class B: virtual public A
{
public:
  B():A(10) {  }
};
 
class C:  virtual public A 
{
public:
  C():A(10) {  }
};
 
class D: public B, public C {
  public:
    // D() : A(0), B(), C() {};
};
 
int main()
{
    // Error in the following line
    // no default constructor exists for class "A" -- 
    // detected during implicit generation of "D::D()" at line 35
    D d;
    // As D doesn't have an explicit default constructor declared and defined
    // the compiler will automatically generate one for it which will 
    // call each of the default constructors of the parents on the hierarchy
    // Class A doesn't have a default constructor which gives the error when
    // generating an instance of D
    // To solve this, either define a default constructor for D which calls
    // the parametrized constructor of A with a value or define a default
    // constructor for class A
    // I implemeted both and chose to define a default construtor for class A
    d.print();
    // W

    return 0;
}