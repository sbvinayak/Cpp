# Author : Vinayak Bhargav Srinath 


all: final

final: main.o term.o kmap.o
	g++ term.o kmap.o main.o -o final

main.o: main.cpp
	g++ -c main.cpp 

term.o: term.cpp term.h
	g++ -c term.cpp 

kmap.o: kmap.cpp kmap.h
	g++ -c kmap.cpp 

clean:
	rm -rf *.o final
