#include "cpu-job.h"

srand(time(NULL));
int r1 = rand()%100;
int r2 = rand()%10+1;
int r3 = rand()%21;


// Manual testing of < operator
CPU_Job a;
CPU_Job b(2021, 25, -7);
ASSERT_TRUE(b < a); // Check if priority is compared

CPU_Job c;
c.ID = r1;
c.length = r2;
c.prior = r3;

// Check if priority is compared
ASSERT_EQ(b < c, b.prior < c.prior);
c.prior = -9;
c.length = 30;
c.ID = 2022;
ASSERT_FALSE(b < c);

// Make sure length matters
c.prior = -7;
c.length = r2;
c.ID = r1;
ASSERT_TRUE(c < b);
c.length = 30;
ASSERT_TRUE(b < c);

// Check if ID is compared when priorities are equal
c.prior = -7;
c.length = 25;
c.ID = r3;
ASSERT_TRUE(c < b);
c.ID = 2022;
ASSERT_TRUE(b < c);