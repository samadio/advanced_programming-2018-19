#include <iostream>

template <typename T>
void print_sentinel(const T* a, const std::size_t l);

int main() {
  int a{8}, b{7};
  int* pi{&a};

  const int* pc = &a;
  // *pc = 7; 	// error: I can change its content.
  a = 15;  // I can obviously change a

  int* const cp = &a;   //you can change the value it contains but u cant change its address
  a = b;
  *cp = 33;
  // cp = &b;   // error

  const int* const cpc = &a;  // points to a fixed memory location and cannot change it
  // *cpc = 0;  // error
  // cpc = &n;  // error
  a = 99;

  int aa[4]{};
  print_sentinel(aa, 4);

  return 0;
}

template <typename T>
void print_sentinel(const T* a, const std::size_t l) {
  const T* const end{a + l}; //it's the element right after the end of the vector a and cannot change nor in value or address
  for (; a != end; ++a) //a=a+1
    std::cout << *a << std::endl; //a[i]=*(&a[0]+i)==*(a+i)
}
