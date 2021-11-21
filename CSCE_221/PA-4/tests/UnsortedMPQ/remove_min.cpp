#include "UnsortedMPQ.h"
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

UnsortedMPQ<int> h;
srand(time(NULL));
int input[10];
for(int i = 0; i < 10; i++){
  input[i] = rand()%1000;
  h.insert(input[i]);
}

std::sort(input,input+10);
cout << "Expected Output:" << endl;
for(int i = 0; i < 10; i++){
  cout << input[i] << ' ';
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