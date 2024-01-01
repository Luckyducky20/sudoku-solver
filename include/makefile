err = -Wall -Werror -Wuninitialized -std=c++20
cc = g++




all: test_animation
	
sudokuUtils.o: sudokuUtils.cpp
	$(cc) $(err) -c sudokuUtils.cpp

boardNumber.o: boardNumber.cpp
	$(cc) $(err) -c boardNumber.cpp

fileUtiles.o: fileUtils.cpp
	$(cc) $(err) -c fileUtils.cpp



# section for test
test_colors: test_colors.cpp
	$(cc) $(err) test_colors.cpp
	./a.out

test_animation: test_animation_multiboard.cpp sudokuUtils.o boardNumber.o
	$(cc) $(err) test_animation_multiboard.cpp sudokuUtils.o boardNumber.o
	cat 01.txt 02.txt 01.txt 02.txt 01.txt 02.txt | ./a.out
test_getFileContents: test_getFileContents.cpp fileUtils.o sudokuUtils.o boardNumber.o
	$(cc) $(err) test_getFileContents.cpp fileUtils.o sudokuUtils.o boardNumber.o
	./a.out

test_getFileNames: fileUtils.o sudokuUtils.o boardNumber.o test_getFileNames.cpp
	$(cc) $(err) test_getFileNames.cpp fileUtils.o sudokuUtils.o boardNumber.o
	./a.out

test_generateBoardBatch: fileUtils.o test_generateBoardBatch.cpp sudokuUtils.o boardNumber.o
	$(cc) $(err) fileUtils.o test_generateBoardBatch.cpp sudokuUtils.o boardNumber.o
	./a.out

clean:
	rm a.out
	rm *.o
