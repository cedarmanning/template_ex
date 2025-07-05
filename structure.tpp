#include "header.h"

// Cedar Manning -- cedarman@pdx.edu
// PROGRAM #2 - CS302

// STRUCTURE.TPP
// .tpp file for Structure Implementation

// Node Declarations Below
// -----------------------

template <typename T>
Node<T>::Node() : next(nullptr), prev(nullptr), data()
{}

template <typename T>
Node<T>::Node(const T & dat) : next(nullptr), prev(nullptr), data(dat)
{}

template <typename T>
Node<T>::~Node()
{
    next = nullptr;
    prev = nullptr;
}

template <typename T>
Node<T> * Node<T>::getNext() const
{
    return next;
}

template <typename T>
Node<T> * Node<T>::getPrev() const
{
    return prev;
}

template <typename T>
int Node<T>::setNext(Node<T> * Next)
{
    next = Next;
    return 1;
}

template <typename T>
int Node<T>::setPrev(Node<T> * Prev)
{
    prev = Prev;
    return 1;
}

template <typename T>
int Node<T>::display() const
{
    cout << data;
    cout << endl;
    return 1;
}

template <typename T>
ostream & operator << (ostream& out, const Node<T> & node)
{   
    node.display();

    return out;
}

// Doubly Linked List Declarations Below
// -----------------------

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}

template <typename T>
int DoublyLinkedList<T>::insert(const T& item)
{
    Node<T> * temp = new Node<T>(item);
    if(!head)
    {
        head = temp;
        return 1;
    }

    head->setPrev(temp);
    temp->setNext(head);
    head = temp;
    return 1;
}

template <typename T>
int DoublyLinkedList<T>::display() const
{
    if(!head)
    {
        throw errorCode("Attempted to Display Empty List");
        return 0;
    }

    return display(head);
}

template <typename T>
int DoublyLinkedList<T>::display(Node<T> * current) const
{
    if(!current) return 0;

    cout << *current;

    return display(current->getNext());
}

template <typename T>
int DoublyLinkedList<T>::clear() 
{
    return clear(head);
}

template <typename T>
int DoublyLinkedList<T>::clear(Node<T>* current) 
{
    if (!current) 
    {
        head = nullptr;
        return 0;
    }

    Node<T> * next = current->getNext();
    delete current;
    return 1 + clear(next);
}
