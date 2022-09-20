assign_2 : main.o texteditor.o
	g++ main.o texteditor.o -o assign_2

main.o : main.cpp doublylinkedlist.h doublylinkedlist.txx
	g++ -c main.cpp -o main.o

texteditor.o : texteditor.cpp texteditor.h
	g++ -c texteditor.cpp -o texteditor.o
