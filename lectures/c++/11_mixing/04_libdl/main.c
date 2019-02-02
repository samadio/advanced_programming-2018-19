#include <dlfcn.h>

int main(int argc, char* argv[]) {
  void* handle; /* handle for dynamic object */
  void (*hi)(); /* function pointer for symbol */ //returntype (*nameofpointer)(args);
  int (*rep)(char*);
  handle = dlopen("./libhello.so", RTLD_LAZY); //"path",way to look for symbols
  if (handle) { //equal to handle!=nullptr: in C if there's a problem no error is raised, just returns a nullptr
    hi = (void (*)())dlsym(handle, "hello"); //casted to void (*)()
    (*hi)(); //calling the function
    rep = (int (*)(char*))dlsym(handle, "repeat");
    rep("I dont't care what fox says");
    dlclose(handle);
  }
  return 0;
}
