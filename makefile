list:	doublelinkedlist.o main.o object.o list.o integer.o
	g++ doublelinkedlist.o main.o object.o list.o integer.o -o list

doublelinkedlist.o: doublelinkedlist.cpp doublelinkedlist.h
	g++ -c doublelinkedlist.cpp

list.o:	list.h list.cpp
	g++ -c list.cpp

object.o:	object.h object.cpp
	g++ -c object.cpp

main.o:	main.cpp
	g++ -c main.cpp

unittest:	doublelinkedlist.o object.o list.o integer.o character.o test.o
	g++ doublelinkedlist.o unittest.o object.o list.o integer.o character.o -o unittest

integer.o:	integer.h integer.cpp
	g++ -c integer.cpp

character.o:	character.h character.cpp
		g++ -c character.cpp

test.o:	unittest.cpp
	g++ -c unittest.cpp

clean:
	rm *.o unittest list
