#include "doublylinkedlist.h"
#include <iostream>
#include <math.h>

/*
 * Iterator
 */
template<class T>
typename DoublyLinkedList<T>::Iterator& 
DoublyLinkedList<T>::Iterator::operator++() //pre increment
{
Iterator_Base::current = Iterator_Base::current->rlink; //for the precise position of current, declare Iterator_Base:: or use this-> pointer
return *this;
}

template<class T>
typename DoublyLinkedList<T>::Iterator  
DoublyLinkedList<T>::Iterator::operator++(int) 
{
Iterator pos = *this;   //post increment
Iterator_Base::current = Iterator_Base::current->rlink;
return pos;
}

template<class T>
typename DoublyLinkedList<T>::Iterator& 
DoublyLinkedList<T>::Iterator::operator--() //pre decrement
{
Iterator_Base::current = Iterator_Base::current->llink; 
return *this;
}

template<class T>
typename DoublyLinkedList<T>::Iterator  
DoublyLinkedList<T>::Iterator::operator--(int) 
{
Iterator pos = *this; //post decrement
Iterator_Base::current = Iterator_Base::current->llink;
return pos;
}


/*
 * Reverse Iterator
 */
template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator&
DoublyLinkedList<T>::Reverse_Iterator::operator++() //reverse normal iterator. pre increment
{
Iterator_Base::current = Iterator_Base::current->llink;
return *this;
}

template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator
DoublyLinkedList<T>::Reverse_Iterator::operator++(int)  //post increment
{
Reverse_Iterator pos = *this;
Iterator_Base::current = Iterator_Base::current->llink;
return pos;
}

template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator&
DoublyLinkedList<T>::Reverse_Iterator::operator--() // pre decrement
{
Iterator_Base::current = Iterator_Base::current->rlink;
return *this;
}

template<class T>
typename DoublyLinkedList<T>::Reverse_Iterator
DoublyLinkedList<T>::Reverse_Iterator::operator--(int)  //post decrement
{
Reverse_Iterator pos = *this;
Iterator_Base::current = Iterator_Base::current->rlink;
return pos;
}

/*
 * Doubly linked list
 */
// Default constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
first = new NodeType;   //memory allocation
first->rlink = first->llink = first;    //when it's empty node, point each other.
}

// Copy constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& source)
{
if(this != &source) //when it's not same with itself.
{
 first = new NodeType; //do it like default constructor
 first->rlink = first->llink = first;

 for(Iterator iter = source.Begin(); iter != source.End(); iter++)  //traverse the iterator of source.
 {
  NodeType* temp = iter.GetNodePointer(); //As the current is under protected, use the Getter function(GetNodePointer()).
  InsertLast(temp->data); //put it next to the last one.
 }

}
}


// Destructor
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
for(Iterator iter = Begin(); iter != End(); iter++) //traversing the iterator
    DeleteFirst();  //delete from the first one.
}


// Assignment operator
template<class T>
DoublyLinkedList<T>& 
DoublyLinkedList<T>::operator = (const DoublyLinkedList<T>& source)
{
if(this != &source) //when it's not same with the source.
{
 first = new NodeType; //do it like default constructor
 first->rlink = first->llink = first;

 for(Iterator iter = source.Begin(); iter != source.End(); iter++)  //traversing the source's iterator.
 {
  NodeType* temp = iter.GetNodePointer();   //access to current by using GetNodePointer
  InsertLast(temp->data);   //put it next to the last one.
 }
}
return *this;   //As it's non void function, we shoud return something. Like *this.
}



// Total number of nodes in the list
template<class T>
int 
DoublyLinkedList<T>::Size() const
{
int count = 0;  //stores the size.

for(Iterator iter = Begin(); iter != End(); ++iter) //traverse the iterator.
count++;    //As it traverses, add one at count variable.

return count;
}


// Insert a new node to the list as the first node
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator 
//typename Iterator
DoublyLinkedList<T>::InsertFirst(const T& data)
{
NodeType* newNode = new NodeType;   //stores data value at newNode, memory allocation.
newNode->data = data;   //data storage

if(first->rlink == nullptr)//when it's empty list
{
 first->llink = first->rlink = newNode;
 newNode->rlink = nullptr;
 newNode->llink = nullptr;
}

else
{
 newNode->llink = first->rlink->llink;
 newNode->rlink = first->rlink;
 first->rlink->llink = newNode;
 first->rlink = newNode;
}

return newNode;
}


// Insert a new node to the list as the last node
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator
DoublyLinkedList<T>::InsertLast(const T & data)
{
NodeType* newNode = new NodeType;
newNode->data = data;

if(first->rlink == nullptr)//when it's empty list
{
 first->llink = first->rlink = newNode;
 newNode->rlink = nullptr;
 newNode->llink = nullptr;
}

else
{
 newNode->llink = first->llink;
 newNode->rlink = first->llink->rlink;
 first->llink->rlink = newNode;
 first->llink = newNode;
}

return newNode;
}

// Insert a new node to the list after pos
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator 
DoublyLinkedList<T>::InsertNext(DoublyLinkedList<T>::Iterator pos, const T & data)
{
NodeType* newNode = new NodeType;   //make newNode and memory allocation
newNode->data = data;   //data storage in newNode

if(first->rlink == nullptr)// when it's empty list
{
 first->llink = first->rlink = newNode;
 newNode->rlink = nullptr;
 newNode->llink = nullptr;
}

else
{
 NodeType* posNode = pos.GetNodePointer();  //as current Node is under protected class, use GetNodePointer function
 NodeType* posNext = posNode->rlink;    //set posNext as the next node of the current node
 newNode->rlink = posNext;
 newNode->llink = posNode;
 posNext->llink = newNode;
 posNode->rlink = newNode;
}

return newNode;
}


// Insert a new node to the list before pos
// Return the pointer of new node
template<class T>
typename DoublyLinkedList<T>::Iterator 
DoublyLinkedList<T>::InsertPrev(DoublyLinkedList<T>::Iterator pos, const T & data)
{
NodeType* newNode = new NodeType;   //make newNode and memory allocation
newNode->data = data;   //data storage in newNode

if(first->rlink == nullptr)//when it's empty list
{
 first->llink = first->rlink = newNode;
 newNode->rlink = nullptr;
 newNode->llink = nullptr;
}

else
{
 NodeType* posNode = pos.GetNodePointer();
 NodeType* posPrev = posNode->llink;
 newNode->llink = posPrev;
 newNode->rlink = posNode;
 posPrev->rlink = newNode;
 posNode->llink = newNode;
}

return newNode;
}


// Delete node at pos in the list
template<class T>
bool 
DoublyLinkedList<T>::DeleteNode(Iterator pos)
{
if(first->rlink == first && first->llink == first) //when it's empty list
 return false;

else
{
 NodeType* del_pos = pos.GetNodePointer();  //stores data of deleting node's current value.

 if(del_pos->llink == nullptr)//when it's first element
  DeleteFirst();

 else if(del_pos->rlink == nullptr)//when it's last element
  DeleteLast();

 else//그 외
 {
  del_pos->llink->rlink = del_pos->rlink;
  del_pos->rlink->llink = del_pos->llink;
 }
}

return true;
}

// Delete first node
template<class T>
bool 
DoublyLinkedList<T>::DeleteFirst()
{
if(first->rlink == first && first->llink == first)  //when it's empty list
 return false;

else
{

 if(first->rlink->rlink != nullptr) //when the nodes are more than one.
 {
  first->rlink = first->rlink->rlink;
  first->rlink->llink = nullptr;
 }

 else//when the node is just one.
  first->rlink = first->llink = first;

}

 return true;
}


// Delete last node
template<class T>
bool 
DoublyLinkedList<T>::DeleteLast()
{
if(first->rlink == first && first->llink == first)//when it's empty list
 return false;

else
{
 if(first->rlink == first->llink)//when the node is just one.
 {
  first->rlink = first->llink = first;
 }

 else   //when the nodes are more than one.
 {
  first->llink->llink->rlink = first->llink->rlink;
  first->llink = first->llink->llink;
 }
 
}
 return true;
}


template<class T>
void 
DoublyLinkedList<T>::Print(bool reverse)
{
if(reverse)
{
		for(Reverse_Iterator rit = rBegin(); rit!=rEnd(); rit++)
		{	
			std::cout << *rit << ", ";
		}
	}
	else 
	{		
		for(Iterator it = Begin(); it!=End(); it++)
		{	
			std::cout << *it << ", ";
		}		
	}
	
	std::cout << std::endl;
}

