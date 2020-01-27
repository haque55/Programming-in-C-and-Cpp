#include<iostream>
using namespace std;
 
class A
{
  int x;
public:
  void setX(int i) {x = i;}
  void print() { cout << x; }
};
 
class B:  public virtual A
{
public:
  B()  { setX(10); }
};
 
class C:  public virtual A  
{
public:
  C()  { setX(20); }
};
 
class D: public B, public C {
};
 
int main()
{
    D d;
    // Error in the following line
    // error: request for member 'print' is ambiguous
    d.print();
    // Multiple inheritance from class B and C creates ambiguity for the methods
    // inherited from the both of them
    // Calling the print() method which was originally inherited from class A
    // will create an ambiguity where the compiler won't know which 
    // inherited print(), from B or C, to call
    // To solve this, both classes B and C should virtually inherit the methods
    // and data members of class A, therefore ensuring that only one of the 
    // methods gets inherited and no duplicates arise
    return 0;
}