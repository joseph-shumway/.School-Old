#include "BinaryHeap.h"
#include <random>

srand(time(NULL));

BinaryHeap<int> h;
int number = rand()%1000;
h.insert(number);
ASSERT_EQ(h.min(),number);
