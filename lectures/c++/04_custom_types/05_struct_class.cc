#include <array>
#include <iostream>
#include <vector>

struct Point_s {		//members of struct is public: can be accessed from outside. Can contain both data & functions
  double x;
  double y;
  void print();
};  // note ; at the end

void Point_s::print() {
  std::cout << "Structure. x = " << x << "; y = " << y << std::endl;
}

class Point_c {	//members of struct is private: can access only in itself of if specified
  double x;
  double y;

 public:
  void print() {
    std::cout << "Class. x = " << x << "; y = " << y << std::endl;
  }  // note no ; at the end
};   // note ; at the end

int main() {
  Point_s ps;		//it's an object ps of class Point_s.
  ps.x = 9.9;
  ps.y = 3. / 7;

  ps.print();

  Point_c pc;
  // pc.x =7.6; // error: x is private because is unspecified in a class
  pc.print();  // I can access private data through public functions

/*Why private?We want consistent object: we don't want the user to interfere.
*/

  Point_s* p = &ps;		//pointer to object
  p->x = 0.0;		//I access the pointer through ->
  p->print();

  auto& pr = ps;
  ++pr.x;
  pr.print();

  Point_s array_of_structs[8];  // built-in array
  array_of_structs[0].x = 1;
  array_of_structs[0].y = 2;

  std::array<Point_s, 5> as;
  as[3].x = 3;

  std::vector<Point_s> vs;
  vs.push_back(ps);
  vs[0].x = 999;
  ps.x = 11;
  ps.print();
  vs[0].print();

  return 0;
}
