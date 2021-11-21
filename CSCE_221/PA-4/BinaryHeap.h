#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <stdexcept>
#include <iostream>
#include <vector>
#include <math.h>

using std::cout;
using std::endl;


// Binary Heap class
 
template <typename T>
class BinaryHeap {
    public:
        //Implement the below 4 methods. Please note these methods are not from MPQ.h
        //BinaryHeap class does not inherit MPQ class 
        //Implement BinaryHeap insert operation
        //Also implement upheap and downheap operations (functions provided below) and call them from wherever necessary
        void insert(const T& data);

        // Return true if BinaryHeap is empty otherwise false
        bool is_empty();

        // Return minimum element in the BinaryHeap
        T min();

        // Remove minimum element in the BinaryHeap and return it
        T remove_min();

    private:
        
        std::vector<T> elements;
        int size = 0;

        void down_heap(int i);
        void up_heap(int i);





        // ----------------------- Pre-implemented helper functions -------------------------- //
        
        //swaps two elements at positions a and b
        void swap(int a, int b) { T c(elements[a]); elements[a] = elements[b]; elements[b] = c;}

        //Returns the right child index of current index
        int right_child(int i) {return 2*i + 2;}

        //Returns the left child index of current index
        int left_child(int i) {return 2*i + 1;}

        //Returns the parent index of current index
        int parent(int i) {return floor((i-1)/2);}

        //Checks if current index is an internal node
        bool is_internal(int i) {return left_child(i) < size || right_child(i) < size;}

        //Checks if current index is a leaf
        bool is_leaf(int i) {return left_child(i) >= size && right_child(i) >= size;}
};

// inserts an item into binary heap
template <typename T>
void BinaryHeap<T>::insert(const T& data) {
    if (is_empty()) {
        elements.push_back(data);
    } else {
        elements.push_back(data);
        up_heap(elements.size() - 1);
    }
}

// Return true if BinaryHeap is empty otherwise false
template <typename T>
bool BinaryHeap<T>::is_empty() {
    
    // cout << "Size: " << elements.size() << endl;
    if (elements.size() == 0) {
        // cout << "EMPTY" << endl << endl;
        return true;
    }

    // cout << "NOT EMPTY" << endl << endl;

    return false;
}

// Return minimum element in the BinaryHeap
template <typename T>
T BinaryHeap<T>::min() {
    return elements.at(0);
}

// Remove minimum element in the BinaryHeap and return it
template <typename T>
T BinaryHeap<T>::remove_min() {
    
    T result = elements.at(0);

    // swap first (min) and last element
    this->swap(0, elements.size() - 1);
    // cout << "swapped" << endl;

    // remove last element (min)
    elements.pop_back();
    // cout << "popped" << endl;

    // restructure tree
    this->down_heap(0);
    // cout << "heaped" << endl;
    
    for (auto each : elements) {
        // cout << each << " ";
    }

    // cout << endl;

    return result;

}

// Restores the binary heap property starting from a node that is smaller than its parent
template <typename T>
void BinaryHeap<T>::up_heap(int i){
    int parent_index = parent(i);

    while (elements.at(i) < elements.at(parent_index))
    {
        this->swap(i, parent_index);
        i = parent_index;
        parent_index = parent(i);
    }
}

// Restores the binary heap property starting from a node that is larger than its children
template <typename T>
void BinaryHeap<T>::down_heap(int i){
    int right_index = right_child(i);
    int left_index = left_child(i);
    int min = i;

    // check if left side is smaller
    if (elements.size() > left_index && elements.at(left_index) < elements.at(min)) {
        min = left_index;
    } 

    // check if right size is smaller
    if (elements.size() > right_index && elements.at(right_index) < elements.at(min)) {
        min = right_index;
    }

    // recursively go through child nodes and swap down until in the right spot
    if (min != i) {
        this->swap(i, min);
        down_heap(min);
    }
}
#endif