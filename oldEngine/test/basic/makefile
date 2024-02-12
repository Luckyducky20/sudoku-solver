err = -Wall -Werror -Wuninitialized -std=c++20
cc = g++
inc = ../../include/


all: test_colors
	
sudokuUtils.o: $(inc)sudokuUtils.cpp
	$(cc) $(err) -c $(inc)sudokuUtils.cpp

boardNumber.o: $(inc)boardNumber.cpp
	$(cc) $(err) -c $(inc)boardNumber.cpp

fileUtils.o: $(inc)fileUtils.cpp
	$(cc) $(err) -c $(inc)fileUtils.cpp



# section for test
test_colors: test_colors.cpp 
	$(cc) $(err) test_colors.cpp
	./a.out

test_getFileContents: test_getFileContents.cpp fileUtils.o sudokuUtils.o boardNumber.o
	$(cc) $(err) test_getFileContents.cpp fileUtils.o sudokuUtils.o boardNumber.o
	./a.out

test_getFileNames: fileUtils.o sudokuUtils.o boardNumber.o test_getFileNames.cpp
	$(cc) $(err) test_getFileNames.cpp fileUtils.o sudokuUtils.o boardNumber.o
	./a.out

test_generateBoardBatch: fileUtils.o test_generateBoardBatch.cpp sudokuUtils.o boardNumber.o
	$(cc) $(err) fileUtils.o test_generateBoardBatch.cpp sudokuUtils.o boardNumber.o
	./a.out

manualBoardInput: manualFileConverter.cpp sudokuUtils.o boardNumber.o
	$(cc) $(err) manualFileConverter.cpp sudokuUtils.o boardNumber.o
	./a.out <../01.txt
clean:
	rm a.out
	rm *.o
