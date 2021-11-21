#include "BinaryHeapMPQ.h"
#include "cpu-job.h"
#include "UnsortedMPQ.h"
#include "SortedMPQ.h"
#include "sims.h"

int main() {
    time_sim("SetSize100000.txt", "TimeSim100000.txt");
    system("cat TimeSim100000.txt");
    return 0;
}

