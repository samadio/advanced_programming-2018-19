#include <assert.h>
#include <cmath>
#include <iostream>

#include "ap_error.h"

/*
If you use the flag -DNDEBUG the assert is ignored, useful for saving time when you checked everything is ok: assert not compiled

*/

// implement a square root function that "deals with" negative
// numbers. Moreover according to the logic of the program, d should
// never be greater than 50
double square_root(const double d);

int main() {
  try {
    std::cout << "please insert a number\n";
    double number;
    std::cin >> number;
    double d = square_root(number);
    std::cout << "square root of " << number << " is " << d << '\n';
    return 0;
  } catch (const std::runtime_error& e) {
    std::cerr << e.what() << '\n';
    return 1;
  } catch (...) {
    std::cerr << "Unknown exception. Aborting.\n";
    return 3;
  }
}

double square_root(const double d) {
  // test the pre-conditions
  assert(d >= 0 && d <= 50);  // provided by C, no execptions: simply exit the program witout any customized message

// AP_ASSERT(d>=0 && d<=50) <<  "d should be in the range [0,50]"; //it's a macro that works like an assert (to save time with -DNDEBUG), but can give customized message and use try and catch

  // AP_ASSERT_IN_RANGE(d,0,50);
  return sqrt(d);
}
