#include <iostream>

struct Base {
  Base() { std::cout << "Base\n"; }
 /* virtual */ ~Base() { std::cout << "~Base\n"; }
};

struct Derived : public Base {
  Derived() { std::cout << "Derived\n"; }
  ~Derived() { std::cout << "~Derived\n"; }
};

int main() {
  { Derived d; } //inside a scope: so both constructor and desctructor are called

  std::cout << "\n\npointers\n";
  Base* p = new Derived;  //derived is a base, so u can use a pointer of type base on a derived
  delete p;		//destructor of type base, but we want to use derived =>decomment

  return 0;
}

/*
compile this to understand in what order u construct and destruct child and parents
in order to maintain a resource acquisition is initialization!
If the parent function is virtual, even the child is. (unless u use final, which breaks this chain of "virtual" inheritance)
*/
