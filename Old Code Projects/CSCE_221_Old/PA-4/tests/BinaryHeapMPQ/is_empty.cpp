#include "BinaryHeapMPQ.h"

BinaryHeapMPQ<double> h;

ASSERT_TRUE(h.is_empty());

h.insert(0.1);

ASSERT_FALSE(h.is_empty());