#include "BinaryHeapMPQ.h"
#include "cpu-job.h"
#include "UnsortedMPQ.h"
#include "SortedMPQ.h"
#include "sims.h"

int main() {
    time_sim("SetSize10000.txt", "TimeSim10000.txt");
    system("cat TimeSim10000.txt");
    return 0;
}

