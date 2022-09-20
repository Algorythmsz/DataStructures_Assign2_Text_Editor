#include "doublylinkedlist.h"
#include "texteditor.h"
#include <iostream>

using namespace std;


int main()
{
	// 
	// 1. Test Doubly Linked List
	//
	DoublyLinkedList<int> list;
	
	list.InsertFirst( 10 );	
	std::cout << "List 1 Size : " << list.Size() << std::endl;
	list.Print();
	std::cout << "--" << std::endl;

	list.InsertFirst( 20 );
	std::cout << "List 1 Size : " << list.Size() << std::endl;
	list.Print();
	std::cout << "--" << std::endl;
	
	list.InsertFirst( 30 );
	std::cout << "List 1 Size : " << list.Size() << std::endl;
	list.Print();
	std::cout << "--" << std::endl;

	list.InsertFirst( 40 );
	std::cout << "List 1 Size : " << list.Size() << std::endl;
	list.Print();
	std::cout << "--" << std::endl;
	
	list.InsertLast( 50 );
    std::cout << "List 1 Size : " << list.Size() << std::endl;
	list.Print();
	std::cout << "--" << std::endl;

	list.InsertLast( 60 );
	std::cout << "List 1 Size : " << list.Size() << std::endl;
	list.Print();
	std::cout << "--" << std::endl;

	// assignment operator test
	DoublyLinkedList<int> list2;
	list2 = list;

	std::cout << "List 2 Size : " << list2.Size() << std::endl;
	list2.Print();
	std::cout << "--" << std::endl;

	// copy constructor test
	DoublyLinkedList<int> list3 = list;

	std::cout << "List 3 Size : " << list3.Size() << std::endl;
	list3.Print();
	std::cout << "--" << std::endl;
	
	list.DeleteFirst();
	std::cout << "List 1 Size : " << list.Size() << std::endl;
	list.Print();
	std::cout << "--" << std::endl;

	list.DeleteLast();
	std::cout << "List 1 Size : " << list.Size() << std::endl;
	list.Print();
	std::cout << "--" << std::endl;
	
	std::cout << "List 2 Size : " << list2.Size() << std::endl;
	list2.Print();
	std::cout << "--" << std::endl;
	
	std::cout << "List 3 Size : " << list3.Size() << std::endl;
	list3.Print();
	std::cout << "--" << std::endl;
	
	// insert middle test
	DoublyLinkedList<int>::Iterator it = list3.Begin();
	std::cout << "First element of list 3 : " << *it << std::endl;
	it++;
	std::cout << "Second element of list 3 : " << *it << std::endl;
	std::cout << "70 will be inserted after " << *it << std::endl;
	it = list3.InsertNext(it, 70);
	list3.Print();
	std::cout << "65 will be inserted before 70" << std::endl;
	it = list3.InsertPrev(it, 65);
	list3.Print();
	it++;it++;it++;
	std::cout << *it << " will be deleted" << std::endl;
	list3.DeleteNode(it);
	list3.Print();
	std::cout << "--" << std::endl;
	
	 //2. Test texteditor
	
	TextEditor vi;

	std::cout << "Print out the current buffer:" << std::endl;
	vi.PrintAll();

	vi.Insert("I am doing my assignment 2.");
	vi.Insert("This assignment is not so easy.");
	vi.Insert("But it is really fun.");
	vi.Insert("I hope I can make it.");
	vi.Insert("KU CSE rocks!");

	vi.PrintAll();
	vi.Print();

	std::cout << "Move up" << std::endl;
	vi.MoveUp();
	vi.Print();

	std::cout << "Move up" << std::endl;
	vi.MoveUp();
	vi.Print();

	std::cout << "Delete the current line" << std::endl;
	vi.Delete();
	vi.Print();

	std::cout << "Print out the current buffer:" << std::endl;
	vi.PrintAll();
    
	std::cout << "Move down" << std::endl;
	vi.MoveDown();
	vi.Print();

	std::cout << "Insert new line" << std::endl;
	vi.Insert("Finally I made it~");

	std::cout << "Print out the current buffer:" << std::endl;
	vi.PrintAll();


	// 3. Test interactive mode
	vi.Run();

	return 0;
}
