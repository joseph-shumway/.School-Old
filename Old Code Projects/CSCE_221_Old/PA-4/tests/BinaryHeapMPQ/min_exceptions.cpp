#include "BinaryHeapMPQ.h"
#include <iostream>
using namespace std;

bool test_min = false, test_remove_min = false;

BinaryHeapMPQ<int> h;

try{
  int s = h.min();
}
catch(...){
  test_min = true;
  cout << "min() exception caught" << endl;
}

try{
  int s = h.remove_min();
}
catch(...){
  test_remove_min = true;
  cout << "remove_min() exception caught" << endl;
}
ASSERT_TRUE(test_min);
ASSERT_TRUE(test_remove_min);