#include <iostream>

int main(int argc, char* argv[]) {
  for (auto i = 0; i < argc; ++i) //argc is number of command line arguments, argv contain them
    std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
  return 0;
}
