#include "cpu-job.h"
#include <random>

srand(time(NULL));

int x = rand()%1000;
int y = rand()%10+1;
int z = rand()%10-5;

CPU_Job a;
CPU_Job b(2021, 5, -7);
CPU_Job c;

c.ID = x;
c.length = y;
c.prior = z;

ASSERT_TRUE(a.ID == 0);
ASSERT_TRUE(a.length == 0);
ASSERT_TRUE(a.prior == 0);
ASSERT_TRUE(b.ID == 2021);
ASSERT_TRUE(b.length == 5);
ASSERT_TRUE(b.prior == -7);
ASSERT_TRUE(c.ID == x);
ASSERT_TRUE(c.length == y);
ASSERT_TRUE(c.prior == z);