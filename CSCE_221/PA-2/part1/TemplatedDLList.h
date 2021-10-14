// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>
using std::cout;
using std::endl;

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
  void print_list(void);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const TemplatedDLList<T>& dll);

#endif


// --end declaration, begin assignment

template <typename T>
TemplatedDLList<T>::TemplatedDLList() {
    header.next = &trailer;
    header.prev = nullptr;

    trailer.prev = nullptr;
    trailer.prev = &header;
}

template <typename T>
TemplatedDLList<T>::TemplatedDLList(const TemplatedDLList<T>& dll){ // copy constructor    

    DLListNode *temp = dll.header.next; // create temp node to traverse DLL
    
    // first node copy
    if (temp->next != nullptr) { // make sure there's a node to copy
        header.next = new DLListNode(); // create next node
        header.next->obj = temp->obj; 
        trailer.prev = header.next;
    }
    
    // keep copying nodes until the next node is trailer and the node after is nullptr
    while (temp->next->next != nullptr) {
        
        temp = temp->next; // move forward one node
        this->insert_last(temp->obj); // copy dll node and insert to end of current list
    }    
} 

template <typename T>
TemplatedDLList<T>::TemplatedDLList(TemplatedDLList<T>&& dll) {// move constructor

    header.next = dll.header.next;
    header.next->prev = &header;
    dll.header.next = &dll.trailer;

    trailer.prev = dll.trailer.prev;
    trailer.prev->next = &trailer;
    dll.trailer.prev = &dll.header;
} 

template <typename T>
TemplatedDLList<T>::~TemplatedDLList(){ // destructor

    while (header.next->next != nullptr) {
        this->remove_first();
    } 

    //delete header.next;
    //delete trailer.prev;

    header.next = nullptr;
    header.prev = nullptr;
    trailer.next = nullptr;
    trailer.prev = nullptr;
} 

template <typename T>
TemplatedDLList<T>& TemplatedDLList<T>::operator=(const TemplatedDLList<T>& dll){// copy assignment operator
    this->make_empty();

    DLListNode *temp = dll.header.next; // create temp node to traverse DLL
    
    // first node copy
    if (temp->next != nullptr) { // make sure there's a node to copy
        header.next = new DLListNode(); // create next node
        header.next->obj = temp->obj; 
        trailer.prev = header.next;
        header.next->prev = &header;
        header.next->next = &trailer;
    }
    
    // keep copying nodes until the next node is trailer and the node after is nullptr
    while (temp->next->next != nullptr) {
        temp = temp->next; // move forward one node
        this->insert_last(temp->obj); // copy dll node and insert to end of current list
    }  


    return *this;
}

template <typename T>
TemplatedDLList<T>& TemplatedDLList<T>::operator=(TemplatedDLList<T>&& dll) { // move assignment operator
    if (this != &dll) {
        // header.next = dll.header.next;
        // trailer.prev = dll.trailer.prev;
        
        header.next = dll.header.next;
        header.next->prev = &header;
        dll.header.next = &dll.trailer;

        trailer.prev = dll.trailer.prev;
        trailer.prev->next = &trailer;
        dll.trailer.prev = &dll.header;
    }
    return *this;
}

// return the pointer to the first node (header's next)
template <typename T>
typename TemplatedDLList<T>::DLListNode* TemplatedDLList<T>::first_node() const {
    return header.next;
}

// return the pointer to the trailer
template <typename T>
const typename TemplatedDLList<T>::DLListNode* TemplatedDLList<T>::after_last_node() const {
    return &trailer;
}

// return if the list is empty
template <typename T>
bool TemplatedDLList<T>::is_empty() const {
    if (header.next == &trailer) {
        return true;
    }
    
    return false;
}

template <typename T>
T TemplatedDLList<T>::first(void) const {// return the first object
    return header.next->obj;
}

template <typename T>
T TemplatedDLList<T>::last() const { // return the last object
    return trailer.prev->obj;
}

template <typename T>
void TemplatedDLList<T>::insert_first(const T obj) { // insert to the first node
    DLListNode *node = new DLListNode(obj);
    DLListNode *firstNode = header.next;

    firstNode->prev = node;
    node->prev = &header;
    node->next = firstNode;
    header.next = node;

}

template <typename T>
T TemplatedDLList<T>::remove_first() { // remove the first node
    
    T obj;

    if (header.next->next != nullptr)
    {
        DLListNode *firstNode = header.next;
        DLListNode *secondNode = header.next->next;

        obj = firstNode->obj;
        secondNode->prev = &header;
        header.next = secondNode;

        //delete firstNode->next;
        //delete firstNode->prev;
        firstNode->next = nullptr;
        firstNode->prev = nullptr;

        delete firstNode;
        firstNode = nullptr;
        
    } else {
        throw std::out_of_range("The list is empty!");
    }

    return obj;
    

}

template <typename T>
void TemplatedDLList<T>::insert_last(const T obj) { // insert to the last node
    DLListNode *node = new DLListNode(obj);
    DLListNode *lastNode = trailer.prev;

    lastNode->next = node;
    node->next = &trailer;
    node->prev = lastNode;
    trailer.prev = node;
}

template <typename T>
T TemplatedDLList<T>::remove_last() { // remove the last node
    T obj= 0;

    if (trailer.prev->prev != nullptr)
    {
        DLListNode *lastNode = trailer.prev;
        DLListNode *secondLastNode = trailer.prev->prev;

        obj = lastNode->obj;
        secondLastNode->next = &trailer;
        trailer.prev = secondLastNode;
        delete lastNode;
        lastNode = nullptr;
    } else {
        throw std::out_of_range("The list is empty!");
    }

    return obj;
}

template <typename T>
void TemplatedDLList<T>::insert_after(DLListNode &p, const T obj) {

    DLListNode *node = &header;
    while (node->obj != p.obj)
    {
        node = node->next;
        if ((node->next == nullptr)) {
            cout << endl;
            throw std::invalid_argument("Position is out of range!");
        }
    }

    DLListNode *newNode = new DLListNode();
    newNode->obj = obj;

    DLListNode *nextNode = node->next;
    node->next = newNode;
    newNode->prev = node;
    newNode->next = nextNode;
    nextNode->prev = newNode;  
}

template <typename T>
void TemplatedDLList<T>::insert_before(DLListNode &p, const T obj) {
    DLListNode *node = &header;
    while (node->obj != p.obj)
    {
        node = node->next;
        if ((node->next == nullptr)) {
            cout << endl;
            throw std::invalid_argument("Position is out of range!");
        }
    }

    DLListNode *newNode = new DLListNode();
    newNode->obj = obj;

    DLListNode *prevNode = node->prev;
    node->prev = newNode;
    newNode->prev = prevNode;
    newNode->next = node;
    prevNode->next = newNode;  
}

template <typename T>
T TemplatedDLList<T>::remove_after(DLListNode &p) {
    if (p.next == nullptr)
    {
        throw std::invalid_argument("Position is out of range!");
    }
    
    
    
    DLListNode *node = &header;
    while (node != &p)
    {
        node = node->next;
        if ((node->next->next == nullptr) || (node->next == nullptr)) {
            //cout << endl;
            throw std::invalid_argument("Position is out of range!");
        }
    }

    //cout << "Before: " << endl;
    //print_list();

    DLListNode *nextNode = node->next->next;
    T i = node->next->obj;
    delete node->next;
    node->next = nextNode;
    nextNode->prev = node;

    //cout << "After: " << endl;
    //print_list();

    //cout << "Value Removed: " << i << " at Node " << p.obj << endl << endl;

    return i;
}

template <typename T>
T TemplatedDLList<T>::remove_before(DLListNode &p) {
    if (p.prev->prev == nullptr)
    {
        throw std::invalid_argument("Position is out of range!");
    }
    
    
    
    DLListNode *node = &header;
    while (node != &p)
    {
        node = node->next;
        if ((node->next->next == nullptr) || (node->next == nullptr)) {
            cout << endl;
            throw std::invalid_argument("Position is out of range!");
        }
    }

    //cout << "Before: " << endl;
    //print_list();

    DLListNode *prevNode = node->prev->prev;
    T i = node->prev->obj;
    delete node->prev;
    node->prev = prevNode;
    prevNode->next = node;

    //cout << "After: " << endl;
    //print_list();

    //cout << "Value Removed: " << i << " at Node " << p.obj << endl << endl;

    return i;
}

template <typename T>
void TemplatedDLList<T>::make_empty(void) {
    while (header.next->next != nullptr) {
        this->remove_first();
    } 
}

template <typename T>
void TemplatedDLList<T>::print_list() {
    DLListNode *node = first_node();

    T counter = 0;
    while (node->next != nullptr) {
        
        cout << "Node " << counter << ": " << node->obj << "        prev: " << node->prev->obj << "       next: " << node->next->obj << endl;
        counter++;
        node = node->next;
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const TemplatedDLList<T>& dll){ // output operator
  typename TemplatedDLList<T>::DLListNode *node = dll.first_node();
    
    while (node->next != nullptr) {
        out << node->obj << ", ";
        node = node->next;
    }

    return out;
}
