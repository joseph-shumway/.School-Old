// implementation of the DLList class

#include "DLList.h"

using std::cout;
using std::endl;

DLList::DLList() {
    header.next = &trailer;
    header.prev = nullptr;

    trailer.prev = nullptr;
    trailer.prev = &header;
}

DLList::DLList(const DLList& dll){ // copy constructor    

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

DLList::DLList(DLList&& dll) {// move constructor

    header.next = dll.header.next;
    header.next->prev = &header;
    dll.header.next = &dll.trailer;

    trailer.prev = dll.trailer.prev;
    trailer.prev->next = &trailer;
    dll.trailer.prev = &dll.header;
} 

DLList::~DLList(){ // destructor

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

DLList& DLList::operator=(const DLList& dll){// copy assignment operator
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

DLList& DLList::operator=(DLList&& dll) { // move assignment operator
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
DLList::DLListNode* DLList::first_node() const {
    return header.next;
}

// return the pointer to the trailer
const DLList::DLListNode* DLList::after_last_node() const {
    return &trailer;
}

// return if the list is empty
bool DLList::is_empty() const {
    if (header.next == &trailer) {
        return true;
    }
    
    return false;
}

int DLList::first() const {// return the first object
    return header.next->obj;
}

int DLList::last() const { // return the last object
    return trailer.prev->obj;
}

void DLList::insert_first(const int obj) { // insert to the first node
    DLListNode *node = new DLListNode(obj);
    DLListNode *firstNode = header.next;

    firstNode->prev = node;
    node->prev = &header;
    node->next = firstNode;
    header.next = node;

}

int DLList::remove_first() { // remove the first node
    
    int obj= 0;

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

void DLList::insert_last(const int obj) { // insert to the last node
    DLListNode *node = new DLListNode(obj);
    DLListNode *lastNode = trailer.prev;

    lastNode->next = node;
    node->next = &trailer;
    node->prev = lastNode;
    trailer.prev = node;
}

int DLList::remove_last() { // remove the last node
    int obj= 0;

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

void DLList::insert_after(DLListNode &p, const int obj) {

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

void DLList::insert_before(DLListNode &p, const int obj) {
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

int DLList::remove_after(DLListNode &p) {
    if (p.next == nullptr)
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

    cout << "Before: " << endl;
    print_list();

    DLListNode *nextNode = node->next->next;
    int i = node->next->obj;
    delete node->next;
    node->next = nextNode;
    nextNode->prev = node;

    cout << "After: " << endl;
    print_list();

    cout << "Value Removed: " << i << " at Node " << p.obj << endl << endl;

    return i;
}

int DLList::remove_before(DLListNode &p) {
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

    cout << "Before: " << endl;
    print_list();

    DLListNode *prevNode = node->prev->prev;
    int i = node->prev->obj;
    delete node->prev;
    node->prev = prevNode;
    prevNode->next = node;

    cout << "After: " << endl;
    print_list();

    cout << "Value Removed: " << i << " at Node " << p.obj << endl << endl;

    return i;
}

void DLList::make_empty(void) {
    while (header.next->next != nullptr) {
        this->remove_first();
    } 
}

void DLList::print_list() {
    DLListNode *node = first_node();

    int counter = 0;
    while (node->next != nullptr) {
        
        cout << "Node " << counter << ": " << node->obj << "        prev: " << node->prev->obj << "       next: " << node->next->obj << endl;
        counter++;
        node = node->next;
    }
}

std::ostream& operator<<(std::ostream& out, const DLList& dll){ // output operator
    DLList::DLListNode *node = dll.first_node();
    
    while (node->next != nullptr) {
        out << node->obj << ", ";
        node = node->next;
    }

    return out;
    
}