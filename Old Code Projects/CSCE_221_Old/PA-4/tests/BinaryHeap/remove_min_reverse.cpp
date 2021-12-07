#include "BinaryHeap.h"
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

BinaryHeap<int> h;
srand(time(NULL));
int input[10];
for(int i = 0; i < 10; i++){
  input[i] = rand()%1000;
}

std::sort(input,input+10);
cout << "Expected Output:" << endl;
for(int i = 0; i < 10; i++){
  cout << input[i] << ' ';
  h.insert(input[9-i]);
}
cout << endl;
cout << "Your Output:" << endl;
for(int i = 0; i < 10; i++){
  if(h.min() != input[i]){
    cout << h.min() << " out of order removal" << endl;
  }
  int n = h.remove_min();
  ASSERT_EQ(n,input[i]);
  cout << n << ' ';
}
cout << endl;