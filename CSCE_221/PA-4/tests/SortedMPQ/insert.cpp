#include "SortedMPQ.h"
#include <random>
#include <algorithm>

SortedMPQ<int> h;
srand(time(NULL));
int input[10];
for(int i = 0; i < 10; i++){
  input[i] = rand()%1000;
  h.insert(input[i]);
}

std::sort(input,input+10);
ASSERT_EQ(h.min(),input[0]);