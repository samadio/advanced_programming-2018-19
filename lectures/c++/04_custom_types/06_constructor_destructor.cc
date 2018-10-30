#include <iostream>
#include <string>


//constructors don't have return type and have the same name of the class

struct Foo {		//this is struct declaration
  int _i;
  double _d;
  std::string _s;

  Foo(const int i, const double d,
      const std::string& s);  // custom constructor: 
      
  Foo();  // default constructor: no argument

  ~Foo();  // destructor
};

Foo::Foo(const int i, const double d, const std::string& s) //this is the custom constructor, declared outside
    : _i{i},
      _d{d},
      _s{s}
// _i, _d, _s must be initialized in the same order they have been declared

{
  std::cout << "custom ctor\n";
  // if you want/need you can use _i, _d, _s and change their value
  // with the usual notation +,-,=,*, call a function..
  // don't use {} because this notation is reserved for the
  // construction of the variables and at this point they have already
  // been constructed
}

Foo::Foo() {		//this is default constructor
  std::cout << "default ctor\n";
}

Foo::~Foo() {		//this is default destructor
  std::cout << "dtor\n";
}



//OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& os, const Foo& f) {	//operator are similar to functions, ostream is a class in the std namespace
  os << f._i << " " << f._d << " " << f._s << std::endl;
  return os;
}






int main() {
  Foo f0;    // call default ctor
  Foo f1{};  // call default ctor
  // Foo f2(); // compiler error

  Foo f2{8, 2.2, "hello"};
  std::cout << "f0: " << f0 << "f1: " << f1 << "f2: " << f2 << std::endl;

  // the destructor is automatically called when the variable goes out of scope
  return 0;
}
