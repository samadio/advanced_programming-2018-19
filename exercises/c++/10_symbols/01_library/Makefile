EXE= main.x
GDIR= ${CURDIR}
LFLAGS = -lhello -L$(GDIR)
CXXFLAGS = -I include -std=c++11
CXX = c++
SRC = source/hello.cc
OBJ = $(SRC:.cc=.o)

all: $(EXE)

$(EXE): main.o
	$(CXX) $^ -o $(EXE) $(LFLAGS) 
	
libhello.so: $(OBJ)
	$(CXX) -shared -o $@ $^

%.o:%.cc
	$(CXX) -fpic -o $@ -c $< -I include
	
main.o:main.cc libhello.so
	$(CXX) -o $@ -c $< -I include

source/hello.o: include/hello.h

main.o: libhello.so

clean:
	@rm -f *~ */*~ libhello.so main.o source/*.o $(EXE) */*~ *~

.PHONY: clean all format
