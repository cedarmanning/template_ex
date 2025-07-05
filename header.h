//includes
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cctype>
#include <cstring>
using namespace std;

// HEADER
// Cedar Manning -- cedarman@pdx.edu
// PROGRAM #2 - CS302
// header file to hold class and struct declarations

// error code struct, used to describe issues during runtime
struct errorCode
{
    string description;
    
    errorCode(const string & description);
};

// Base Class: Client

class Client 
{
    public:
        Client();   // constructor
        ~Client();  // destructor
        Client(const Client& other);    // param construct
        Client & operator=(const Client& other);    // asign op

        // Operator overloads
        bool operator ==(const Client& other) const;
        bool operator != (const Client& other) const;
        bool operator < (const Client& other) const;
        bool operator <= (const Client& other) const;
        bool operator > (const Client& other) const;
        bool operator >= (const Client& other) const;
        Client & operator += (int domains);
        Client operator + (int domains) const;

        friend ostream & operator << (ostream& out, const Client &);    // out overload, calls display
        friend istream & operator >> (istream& in, Client& client);     // in overload, calls input

        // other functions
        int display() const;    // displays object members
        int input();    // sets members with user input
        int copy(const Client & other); // copies other like object

    protected:
        // protected data members
        char* clientName;
        string contactEmail;
        int domainCount;
};

// Derived Class: Personal
class Personal : public Client 
{
    public:
        Personal(); // construct
        ~Personal();    // destruct
        Personal(const Personal& other);    // param construct

        // operator overloads
        Personal& operator = (const Personal& other);

        // other functions
        int display() const;    // displays members, calls parent display
        int input();    // sets members, calls parent input

        friend ostream & operator << (ostream& out, const Personal &);  // overloaded out, displays members

    private:
        // data members
        string preferredDomain;
        int emailAccountCount;
};

// Derived Class: Business

class Business : public Client
{
    public:
        Business(); // constructor
        ~Business();    // destruct
        Business(const Business& other);    // param construct
        Business & operator = (const Business& other);  // equals op

        // other functions
        int display() const;    // displays members, calls parent display
        int input();    // sets members with user input, calls parent inpt


        friend ostream & operator << (ostream& out, const Business &);  // overloaded out, calls parent and derived display

    private:
        // data members
        string subdomainPrefix;
        bool emailForwardingEnabled;
};


// Derived Class: Corporate
class Corporate : public Client 
{
    public:
        Corporate();    // construct
        ~Corporate();   // destruct
        Corporate(const Corporate& other);  // param construct
        Corporate & operator = (const Corporate& other);  // equals op

        // other functions
        int display() const;
        int input();

        friend ostream & operator << (ostream& out, const Corporate &); // overloaded out, calls parent and derived display

    private:
        // data members
        char * departmentTag;   // dynamically allocated
        int employeeEmailCount;
};

// Templated Node
template <typename T>
class Node
{
    public:
        Node(); // constructor
        Node(const T & data);   // param construct
        ~Node();    // destruct

        Node<T> * getNext() const;  // get next pointer
        Node<T> * getPrev() const;  // get previous pointer
        int setNext(Node<T> *); // set next pointer
        int setPrev(Node<T> *); // set previous pointer

        int display() const;    // displays node, will call << op

    private:
        // data members
        Node<T> * next;
        Node<T> * prev;
        T data;
};

// Templated Doubly Linked List
template <typename T>
class DoublyLinkedList
{
    public:
        DoublyLinkedList(); // construct
        DoublyLinkedList(const DoublyLinkedList & toCopy);  // param construct
        ~DoublyLinkedList();    // destructor

        int insert(const T& item);  // insert node into DLL
        int remove(const T& item);  // remove item from DLL
        int display() const;    // displays DLL
        int clear();    // clears (removes all) nodes

    private:
        // data members
        Node<T> * head; // head node

        // recursive calls for wrapper functions
        int display(Node<T> * current) const;   
        int clear(Node<T>* current);
};

#include "structure.tpp"
