err = -Wall -Werror -Wuninitialized -std=c++20
cc = g++
td = _testing
mu = include

all: manualBoardInput
	./a.out <01.txt

manualBoardInput: manualFileConverter.cpp sudokuUtils.o boardNumber.o
	$(cc) $(err) manualFileConverter.cpp sudokuUtils.o boardNumber.o

sudokuUtils.o: $(mu)/sudokuUtils.cpp 
	$(cc) $(err) $(mu)/sudokuUtils.cpp -c

boardNumber.o: $(mu)/boardNumber.cpp
	$(cc) $(mu)/boardNumber.cpp -c 

reset_batches:
	cp batches/resetNum batches/batchCount
	rm batches/*batch_0* -r

clean:
	rm a.out
	rm *.o
	rm boards/*converted*
