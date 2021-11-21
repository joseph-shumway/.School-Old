#include "BinaryHeapMPQ.h"
#include "cpu-job.h"
#include "UnsortedMPQ.h"
#include "SortedMPQ.h"
#include "sims.h"

int main() {
    time_sim("SetSize1000.txt", "TimeSim1000.txt");
    system("cat TimeSim1000.txt");
    return 0;
}

