
cc = g++
cpp = ../cppFiles/
h = ../headerFiles/
lib = ../lib/

all: ray
	./a.out

clean:
	rm a.out



test_tile: 
	$(cc) $(cpp)sudokuTile.cpp test_tile.cpp -I$(h)

ray: RaylibTest.o
	$(cc) RaylibTest.o -I$(h) $(lib)libraylib.a

RaylibTest.o: RaylibTest.cpp
	$(cc) RaylibTest.cpp -c -I$(h)

rayTest: 
	$(cc) raylibTest.cpp -I$(h) $(lib)libraylib.a

















