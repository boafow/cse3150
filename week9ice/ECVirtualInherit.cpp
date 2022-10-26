#include <iostream>
using namespace std;

// Base
class Base
{
public:
  Base() : val(1) {}
  Base(int x) : val(x) {}
  int GetVal() const { return val; }

private:
  int val;
};

// Derived class 1
class Derived1 : public virtual Base
{
public:
  // initialize base to be 2
  Derived1() : Base(2) {} 
};

// Derived class 2 
class Derived2 : public virtual Base
{
public:
  // initialize base to be 3 
  Derived2() : Base(3) {}
};

// Multiple inherit
class MultiC :  public Derived1, public Derived2
{
public:
  // initialize
  MultiC()/*:Base(4)*/  {}
};

// test
int main()
{
  MultiC m;
  cout << "m's value: " << m.GetVal() << endl;

  Base *p0 = &m;
  cout << "m's value (from Base): " << p0->GetVal() << endl;
  Derived1 *p1 = &m;
  cout << "m's value (from Derived1): " << p1->GetVal() << endl;
  MultiC *p2 = (MultiC *)p0;
  cout << "m's value (from Derived2): " << p2->GetVal() << endl;
}

