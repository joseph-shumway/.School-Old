#include "BinaryHeapMPQ.h"
#include "cpu-job.h"
#include "UnsortedMPQ.h"
#include "SortedMPQ.h"
#include "sims.h"

/*
 * Main driver for simulations
 */
int main() {

    // Run simulation for 100000 jobs
    cout << "Running simulation on SetSize10000.txt" << endl;
    run_sim_sorted("SetSize10000.txt", "RunSim10000.txt");

    return 0;
}

