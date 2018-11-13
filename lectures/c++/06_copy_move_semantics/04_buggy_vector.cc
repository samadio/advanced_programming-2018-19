#include <iostream>

template <typename num>
class Vector {
  num* elem;
  std::size_t _size;

 public:
  explicit Vector(const std::size_t length) //used for constructor who can BE INVOKED WITH JUST 1 ARGUMENT:
  								    //if I dont say anithing, the compiler can implicitely build a converter from
  								    // typeofargument->class
      : elem{new num[length]{}}, _size{length} {}

  ~Vector() noexcept { delete[] elem; }

  const num& operator[](const std::size_t& i) const noexcept { return elem[i]; }
  num& operator[](const std::size_t& i) noexcept { return elem[i]; }

  std::size_t size() const noexcept { return _size; }

  //functions nedeed for range-for
  const num* begin() const noexcept { return elem; } //use const
  num* begin() noexcept { return elem; }		//noexcept: no exception will be throwned, to optimize

  const num* end() const noexcept { return elem + _size; }
  num* end() noexcept { return elem + _size; }
};

// TEST IN ORDER TO SEE THE PROBLEMS OF EXPLICIT

/*
template<class T>
void debug(const Vector<T> v)
{
std::cout<< "       "<<v.size()<<std::endl;
}
*/


int main() {
  Vector<int> v1{3};
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;

  std::cout << "v1: ";
  for (const auto x : v1){
    std::cout << x << " ";
  }
  std::cout << std::endl;

  Vector<int> v2{v1};  // default copy constructor: copy by value. Fine in general but PROBLEMS FOR POINTERS
  				   //if I copy by value a pointer I'm copying its address
  				   //this means that both v1 and v2 contains the same adress in the heap, so when I modify using v1,I've
  				   //modified even the memory v2 points to, and the same modifying v2. This is a SHALLOW COPY

  std::cout << "v2 after default copy ctor: "; //fine
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v1[0] = 99;

  std::cout << "v2 after v1 has been changed: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v2[1] = -999;

  std::cout << "v1 after v2 has been changed: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

/*part of the test*/	//		debug<int>(1);

  return 0;
}

/*

Sentinel approach: begin gets the first element of vector, end gets the sentinel, which is the element following the last one

*/
