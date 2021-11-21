#include "UnsortedMPQ.h"
#include <random>
#include <algorithm>

srand(time(NULL));

UnsortedMPQ<int> h;
int number1 = rand()%1000;
int number2 = rand()%1000;
h.insert(number1);
h.insert(number2);
ASSERT_EQ(h.min(), std::min(number1,number2));