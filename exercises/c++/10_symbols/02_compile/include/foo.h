#include "utility.h"

#ifndef FOO_H_
#define FOO_H_

extern std::string to_upper(const std::string& os);

struct Foo{
  static double f;
  std::string bar;
  Foo() = delete;
  Foo(const std::string& s) : bar{to_upper(s)} {};
};

double Foo::f;

#endif
