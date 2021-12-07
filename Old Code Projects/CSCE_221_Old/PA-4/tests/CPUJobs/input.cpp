#include "cpu-job.h"
#include <fstream>
using namespace std;

// Test vector with data from SetSize10.txt
CPU_Job test[10];
test[0] = CPU_Job(7, 7, 8);
test[1] = CPU_Job(1, 2, 11);
test[2] = CPU_Job(6, 2, 15);
test[3] = CPU_Job(3, 8, 3);
test[4] = CPU_Job(2, 10, -16);
test[5] = CPU_Job(8, 3, -3);
test[6] = CPU_Job(4, 7, -16);
test[7] = CPU_Job(9, 9, -3);
test[8] = CPU_Job(10, 9, -3);
test[9] = CPU_Job(5, 9, 11);

ifstream ifs("SetSize10.txt");
CPU_Job jobs[10];
for (int i = 0; i < 10; i++) {
  ifs >> jobs[i];
}

// Check if input operator assigned things correctly
for (int i = 0; i < 10; i++) {
  ASSERT_TRUE(jobs[i].ID == test[i].ID);
  ASSERT_TRUE(jobs[i].length == test[i].length);
  ASSERT_TRUE(jobs[i].prior == test[i].prior);
}