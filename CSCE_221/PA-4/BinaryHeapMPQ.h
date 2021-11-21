#ifndef BINARYHEAP_MPQ_H
#define BINARYHEAP_MPQ_H

#include "BinaryHeap.h"
#include <stdexcept>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a binary heap
 */
template <typename T>
class BinaryHeapMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // It is enough if the 4 methods in  BinaryHeapMPQ calls the corresponding implemented methods in BinaryHeap.h.
   // To hold the elements use BinaryHeap (from BinaryHeap.h)
   // For remove_min() and min() throw exception if the BinaryHeapMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.
   
   public:
      T remove_min();
      T min();
      bool is_empty();
      void insert(const T& data);

      // create heap for use in this template
      BinaryHeap<T> heap;
};




// Remove minimum from MPQ and return it
template <typename T>
T BinaryHeapMPQ<T>::remove_min() {
   if (this->is_empty()) {
      throw std::domain_error("List is empty!");
   }
   
   return heap.remove_min();
}

// Get the minimum from MPQ
template <typename T>
T BinaryHeapMPQ<T>::min() {
   if (this->is_empty()) {
      throw std::domain_error("List is empty!");
   }
   
   return heap.min();
}

// Check if MPQ is empty
template <typename T>
bool BinaryHeapMPQ<T>::is_empty() {
   return heap.is_empty();
}

// Insert into MPQ
template <typename T>
void BinaryHeapMPQ<T>::insert(const T& data) {
   heap.insert(data);
}


#endif