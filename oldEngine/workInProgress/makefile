err = -Wall -Werror -Wuninitialized -std=c++20
cc = g++

all: getFileContents 

fileSys: fileSystem.cpp fileUtils.o
	$(cc) $(err) fileSystem.cpp fileUtils.o
	./a.out




getFileContents: ../include/test_getFileContents.cpp fileUtils.o
	$(cc) $(err) ../include/test_getFileContents.cpp fileUtils.o
	./a.out

fileNames: fileUtils.o
	$(cc) $(err) ../include/test_getFileNames.cpp fileUtils.o
	./a.out


fileUtils.o: ../include/fileUtils.cpp
	$(cc) $(err) -c ../include/fileUtils.cpp


clean:
	rm *.o
	rm a.out
