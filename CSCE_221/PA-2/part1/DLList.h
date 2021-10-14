// header file for the DLList class

#ifndef DLLIST_H
#define DLLIST_H

#include <iostream>


class DLList { // doubly linked list class
public:

struct DLListNode { // doubly linked list node
  int obj;
  DLListNode *prev, *next;

  // constructor
  DLListNode(int e=0, DLListNode *p=nullptr, DLListNode *n=nullptr): obj(e), prev(p), next(n){}};


private:
  DLListNode header, trailer;


public:
  DLList();
  DLList(const DLList& dll); // copy constructor
  DLList(DLList&& dll); // move constructor
  ~DLList(); // destructor
  DLList& operator=(const DLList& dll); // copy assignment operator
  DLList& operator=(DLList&& dll); // move assignment operator

  DLListNode *first_node() const; // return the pointer to the first node (header's next)
  const DLListNode *after_last_node() const; // return the pointer to the trailer

  bool is_empty() const; // return if the list is empty
  int first() const; // return the first object
  int last() const; // return the last object
  void insert_first(const int obj); // insert to the first node
  int remove_first(); // remove the first node
  void insert_last(const int obj); // insert to the last node
  int remove_last(); // remove the last node
  void insert_after(DLListNode &p, const int obj);
  void insert_before(DLListNode &p, const int obj);
  int remove_after(DLListNode &p);
  int remove_before(DLListNode &p);
  void make_empty(void);
  void print_list();
};


std::ostream& operator<<(std::ostream& out, const DLList& dll); // output operator

#endif
