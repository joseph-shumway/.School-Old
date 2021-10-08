// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>

// doubly linked list class
template <typename T>
class TemplatedDLList {
public:
// doubly linked list node
  struct DLListNode {
    T obj;
    DLListNode *prev, *next;
    // constructor
    DLListNode(T e=T(), DLListNode *p=nullptr, DLListNode *n=nullptr): obj(e), prev(p), next(n) {}
  };
private:
  DLListNode header, trailer;
public:
  TemplatedDLList(void); // default constructor  
  TemplatedDLList(const TemplatedDLList<T>& dll); // copy constructor
  TemplatedDLList(TemplatedDLList<T>&& dll); // move constructor
  ~TemplatedDLList(); // destructor
  TemplatedDLList<T>& operator=(const TemplatedDLList<T>& dll); // copy assignment operator
  TemplatedDLList<T>& operator=(TemplatedDLList<T>&& dll); // move assignment operator

  // return the pointer to the first node
  DLListNode *first_node(void) const;

  // return the pointer to the trailer
  const DLListNode *after_last_node(void) const;

  // return true if the list is empty
  bool is_empty(void) const;

  T first(void) const; // return the first object
  T last(void) const; // return the last object
  void insert_first(const T obj); // insert to the first node
  T remove_first(); // remove the first node
  void insert_last(const T obj); // insert to the last node
  T remove_last();
  void insert_after(DLListNode &p, const T obj);
  void insert_before(DLListNode &p, const T obj);
  T remove_after(DLListNode &p);
  T remove_before(DLListNode &p);
  void make_empty(void);
};

// output operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const TemplatedDLList<T>& dll);

#endif
