#include <iostream>

struct X {
  char member;
};

int main() {
  X x1;                 // default ctor
  X x2{x1};             // copy ctor
  X x3{std::move(x2)};  // move ctor
  X x4{};               // default ctor calling {} to each member
  x4 = x3;              // copy assignment
  X x5;                 // default ctor
  x5 = std::move(x4);   // move assignment
  std::cout << x5.member << std::endl;  // what do you expect??
  return 0;
}

/*
a copy can be shallow or deep, but for definition a copy x2 of x1 holds x2==x1

int a
int & b=a L-value reference
instead int&& b is a R-value

it compiles because the compiler can generate all the functions for u

WARNING: the declaration X x1 and X x2{} are different only if u use the default constructor

*/
