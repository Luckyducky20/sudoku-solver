err = -Wall -Werror -Wuninitialized -std=c++20
cc = g++
inc = ../../include/


all: test_animation
	
sudokuUtils.o: $(inc)sudokuUtils.cpp
	$(cc) $(err) -c $(inc)sudokuUtils.cpp

boardNumber.o: $(inc)boardNumber.cpp
	$(cc) $(err) -c $(inc)boardNumber.cpp

fileUtils.o: $(inc)fileUtils.cpp
	$(cc) $(err) -c $(inc)fileUtils.cpp


# section for test
test_animation: test_animation_multiboard.cpp sudokuUtils.o boardNumber.o
	$(cc) $(err) test_animation_multiboard.cpp sudokuUtils.o boardNumber.o
	cat ../01.txt ../02.txt ../01.txt ../02.txt ../01.txt ../02.txt | ./a.out

clean:
	rm a.out
	rm *.o
