#include <cstring>  // strcmp
#include <iostream>

int func1(const char* a);
int func2(const char* a);
void func3(const char* a);

int main() {
  int a{8};
  int* pi{&a};

  char** ppc;

  int* ap[7];	//array of pointer of size 7: you can do int** p=ap;

  void* pv{pi};
  // *pv; // we cannot dereference void*
  // ++pv; // we cannot increment. Why?
  int* pi2{static_cast<int*>(pv)};

  pv = ppc;
  pv = ap;
  pv = pi;

  pi = nullptr;	//null pointer: it empties a pointer
  ppc = nullptr;
  // ap = nullptr;  // error, why?
  ap[0] = nullptr;
  int** bbb;
  bbb = ap;
  pv = nullptr;
  pi2 = 0;  // older codes. gets the nullptr

  // pi = NULL; // please don't do this

  double* da{new double[5]{}};  
  delete[]da; //it releases the heap memory, but the pointer is still there: dangling pointer
  da=nullptr;  //difference between pointer and reference: pointer can point to nothing, reference has to be referred to something


  if (pi != nullptr)
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi) //true when pi!=nullpointer
    std::cout << "pi is not nullptr and I can dereference it " << *pi
              << std::endl;

  if (pi == nullptr)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  if (!pi)
    std::cout << "pi is nullptr and I CANNOT dereference it \n";

  // strings are special type of char[]
  char word[]{"Hello"};
  char word2[]{'H', 'e', 'l', 'l', 'o', 0};
  if (strcmp(word, word2) == 0)  // word == word2 is
                                 // implementation-dependent (it might
                                 // compare the two pointers, i.e. the
                                 // two addresses of word and word2)
    std::cout << "same\n";
  else
    std::cout << "different\n";

  int (*fp)(const char*);  //pointer to a function which returns an int and takes a const char as argument.Be careful about (*fp). Parentesys are mandatory in order to avoid compiler get confused. With pointer to a function u can feed a function with a function:integral(sin(x))
  fp = func1;

  fp("hello");

  fp = &func2;
  fp("world");

  // fp = func3; // error: wrong signature: func3 need void result, fp is pointer to integer
  auto xx = func3;

  xx("auto");

  decltype(&func3) x = func3;
  x("decltype");

  return 0;
}

int func1(const char* a) {
  std::cout << "1111: " << a << std::endl;
  return 1;
}

int func2(const char* a) {
  std::cout << "2222: " << a << std::endl;
  return 2;
}

void func3(const char* a) {
  std::cout << "3333: " << a << std::endl;
}
