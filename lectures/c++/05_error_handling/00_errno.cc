#include <cmath>
#include <iostream>

int main() {
  double d = std::sqrt(-9);
  std::cout << d << " " << errno << std::endl;
  return 0;
}


//error handling: if I call sqrt(-9) no complain, but d is a NaN. So how can I check? using a macro errno, which is !=0 when something bad happens: here we have errno=33. 
