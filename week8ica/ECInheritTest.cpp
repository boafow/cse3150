class Shape {
public:
  void foo() { /* do nothing */ }
};

class Rectangle : public Shape {
};

class Square : public Rectangle {
public:
  void bar() { foo(); }
};

void Test(Shape &s) {  /* do nothing */ }

int main()
{
  Square s;
  s.bar();
  //Test(s);

  //Rectangle r;
  //Test(r);
}

