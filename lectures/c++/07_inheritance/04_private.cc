#include <ap_error.h>
#include <iostream>

/*

abstract class if u define a function as pure virtual: so u cant declare an "Animal a"
If a child do not override that function, the child is itself abstract. This way u force user to override
*/
class Animal {
  unsigned int age; //better a parent not to have data or to have it private, so that children cannot mess up
  double weight;

 public:
  Animal(const unsigned int a, const double w) : age{a}, weight{w} {
    AP_ERROR_GE(weight, 0) << "invalid weight!\n";
  }

  Animal() : Animal{0, 0} {}  // delegating constructor: pass the arguments to another one, where all the checks are done

  virtual void speak() const = 0;		//THIS MAKE ANIMAL ABSTRACT
  virtual void info() const noexcept {
    std::cout << "age:\t" << age << '\n' << "weight:\t" << weight << '\n';
  }

  virtual ~Animal() {}
};

class Dog : public Animal {
 public:
  void speak() const noexcept override { std::cout << "Bau\n"; }
  //Dog() = default;		//this and the following is code duplication: it's the same of the parent
  //Dog(const unsigned int a, const double d) : Animal{a, d} {}
  using Animal::Animal; //populating the child with the same constructor of the parent
};

class Snake : public Animal {
  bool dangerous;

 public:
  Snake(const unsigned int a, const double w, const bool b)
      : Animal{a, w}, dangerous{b} {}
  Snake(const bool b) : Animal{}, dangerous{b} {}
  void info() const noexcept override {
    Animal::info();
    std::cout << "dangerous:\t" << (dangerous ? "true" : "false") << std::endl;
  }
  void speak() const noexcept override { std::cout << "ssss\n"; }
};

inline void newline() noexcept {
  std::cout << std::endl;
}

class DangerousSnake : public Snake {
 public:
  DangerousSnake(const unsigned int a, const double w) : Snake{a, w, true} {}
  DangerousSnake() : Snake{true} {}
};

class NonDangerousSnake : public Snake {
 public:
  NonDangerousSnake(const unsigned int a, const double w)
      : Snake{a, w, false} {}
  NonDangerousSnake() : Snake{false} {}
};

struct Python : public NonDangerousSnake {};

using Anaconda = DangerousSnake; //using can be templated

void print_animal(const Animal& a) noexcept {
  std::cout << "throught ref\n";
  a.info();
  a.speak();
}

int main() {
  try {
    Python s;
    s.info();
    s.speak();

    newline();

    // Animal* p = new DangerousSnake{1, 2.3};
    Animal* p = new Anaconda{1, 2.3};

    std::cout << "through pointer\n";
    p->info();
    p->speak();

    delete p;

    newline();

    print_animal(s);

    return 0;
  } catch (std::runtime_error& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
