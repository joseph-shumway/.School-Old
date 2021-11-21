#include "UnsortedMPQ.h"
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

bool test_min = false, test_remove_min = false;

UnsortedMPQ<int> h;
srand(time(NULL));
int input[30];
for(int i = 0; i < 30; i++){
  input[i] = rand()%1000;
  h.insert(input[i]);
}

std::sort(input,input+30);
ASSERT_EQ(h.min(),input[0]);

cout << "Expected Output:" << endl;
for(int i = 0; i < 30; i++){
  cout << input[i] << ' ';
}
cout << endl;
cout << "Your Output:" << endl;
for(int i = 0; i < 30; i++){
  if(h.min() != input[i]){
    cout << h.min() << " out of order removal" << endl;
  }
  int n = h.remove_min();
  ASSERT_EQ(n,input[i]);
  cout << n << ' ';
}
cout << endl;

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
test_min = false;
test_remove_min = false;

ASSERT_TRUE(h.is_empty());

h.insert(0.1);

ASSERT_FALSE(h.is_empty());

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
ASSERT_FALSE(test_min);
ASSERT_FALSE(test_remove_min);

int input2[30];
for(int i = 0; i < 30; i++){
  input2[i] = rand()%1000;
  h.insert(input2[i]);
}

std::sort(input2,input2+30);
ASSERT_EQ(h.min(),input2[0]);

cout << "Expected Output:" << endl;
for(int i = 0; i < 30; i++){
  cout << input2[i] << ' ';
}

cout << endl;
cout << "Your Output:" << endl;
for(int i = 0; i < 30; i++){
  if(h.min() != input2[i]){
    cout << h.min() << " out of order removal" << endl;
  }
  int n = h.remove_min();
  ASSERT_EQ(n,input2[i]);
  cout << n << ' ';
}
cout << endl;