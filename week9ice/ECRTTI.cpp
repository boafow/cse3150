#include <iostream>
using namespace std;

// base class
class ECLife
{
public:
  virtual void Die() {}
};

// derived class
class ECCat :  public ECLife
{
public:
  void Mew() { }
};

// derived class 2
class ECDog : public ECLife
{
public:
  void Bark() { }
};

// test code
int main()
{
  ECLife *pl1 = new ECCat;
  ECLife *pl2 = new ECDog;
  ECLife *pl3 = new ECCat;

  // How to tell what kind of life it is?
  // How to tell if say pl1 and pl2 point to the same kind of life?
  ECCat * pp1 = dynamic_cast<ECCat *>(pl1);
  if (pp1 != NULL){
	  cout << "cat\n";
  } else {
	  cout << "not cat\n";
  }
  
  const std::type_info &t1 = typeid(*pl1);
  cout << "t1 type: " << t1.name() << endl;

  const std::type_info &t2 = typeid(*pl3);
  cout << "t2 type: " << t2.name() << endl;

  if(t1 == t2){
	  cout << "Same\n";
  } else {
	  cout << "NOT Same\n";
  }

  delete pl1;
  delete pl2;
  delete pl3; 
}

