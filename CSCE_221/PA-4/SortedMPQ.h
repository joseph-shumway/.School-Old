#ifndef SORTEDMPQ_H
#define SORTEDMPQ_H

#include <stdexcept>
#include <list>
#include <vector>
#include "MPQ.h"

/*
 * Minimum Priority Queue based on a linked list
 */
template <typename T>
class SortedMPQ: MPQ<T> {
   // Implement the four funtions (insert, is_empty, min, remove_min) from MPQ.h
   // To hold the elements use std::list
   // For remove_min() and min() throw exception if the SortedMPQ is empty. Mimir already has a try/catch block so don't use try/catch block here.

   public:
      T remove_min();
      T min();
      bool is_empty();
      void insert(const T& data);
      void sort();

      std::list<T> list;
      std::vector<T> v_list;
};

// Remove minimum from MPQ and return it
template <typename T>
T SortedMPQ<T>::remove_min() {
   if (this->is_empty()) {
      throw std::domain_error("List is empty!");
   }

   T min = list.front();
   list.pop_front();

   return min;
}

// Get the minimum from MPQ
template <typename T>
T SortedMPQ<T>::min() {
   if (this->is_empty()) {
      throw std::domain_error("List is empty!");
   }
   
   return list.front();
}

// Check if MPQ is empty
template <typename T>
bool SortedMPQ<T>::is_empty() {
   return (list.size() == 0);
}

// Insert into MPQ
template <typename T>
void SortedMPQ<T>::insert(const T& data) {
   typename std::list<T>::iterator iter = list.begin();
   
   
   for (int i = 0; i < list.size(); i++)
   {
      if (*iter > data) {
         list.insert(iter, data);
         return;
      }
      std::advance(iter, 1);
   }


   list.push_back(data);
   
}

#endif