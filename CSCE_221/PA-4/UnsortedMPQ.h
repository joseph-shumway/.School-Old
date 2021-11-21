#ifndef UNSORTEDMPQ_H
#define UNSORTEDMPQ_H

#include <stdexcept>
#include <vector>
#include "MPQ.h"

using std::vector;
using std::cout;
using std::endl;

/**
 * Minimum Priority Queue based on a vector
 */
template <typename T>
class UnsortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::vector
   // For remove_min() and min() just throw exception if the UnsortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.

   public:
      T remove_min();
      T min();
      bool is_empty();
      void insert(const T& data);
      

      // create our list
      vector<T> list;
};

// Remove minimum from MPQ and return it
template <typename T>
T UnsortedMPQ<T>::remove_min() {
   if (this->is_empty()) {
      throw std::domain_error("List is empty!");
   }
   
   T min = list.at(0);
   int index= 0;
   
   for (int i = 0; i < list.size(); i++) {
       if (min > list.at(i)) {min = list.at(i); index = i;}
   }

   list.erase(list.begin() + index);

   return min;
}

// Get the minimum from MPQ
template <typename T>
T UnsortedMPQ<T>::min() {
   if (this->is_empty()) {
      throw std::domain_error("List is empty!");
   }
   
   T min = list.at(0);

   for (auto each : list) {
       if (min > each) {min = each;}
   }

   return min;
}

// Check if MPQ is empty
template <typename T>
bool UnsortedMPQ<T>::is_empty() {
   return (list.size() == 0);
}

// Insert into MPQ
template <typename T>
void UnsortedMPQ<T>::insert(const T& data) {
   list.push_back(data);
}

template <typename T>
bool operator<(const T& lhs, const T& rhs) {
   if (lhs < rhs) {
      return true;
   }
   return false;
}

#endif