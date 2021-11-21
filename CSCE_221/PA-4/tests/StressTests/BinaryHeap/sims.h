#ifndef SIMS_H
#define SIMS_H
#include <cctype>
#include <chrono>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;
using namespace chrono;
/*
 * Runs a simulation of jobs on a CPU
 *   input_file is name of file containing jobs
 *   output_file is name of file to write out the results
 */
bool run_sim_unsorted(string input_file, string output_file) {
    // Attempt to open input file
    ifstream ifs(input_file);
    if (!ifs.is_open()) {
        cout << "Error opening: " << input_file << endl;
        return false;
    }

    // Attempt to open output file
    ofstream ofs(output_file);
    if (!ofs.is_open()) {
        cout << "Error opening: " << output_file << endl;
        return false;
    }

    // Create MPQs for simulation
    UnsortedMPQ<CPU_Job> v_mpq;
    
    // Read jobs from input file and place in each MPQ
    int num_jobs = 0;
    CPU_Job temp;
    while (ifs >> temp) {
        v_mpq.insert(temp);
        num_jobs++;
    }

    // Time slice of cpu
    int time_slice = 0;

    // Run simulation for vector MPQ
    ofs << "Running simulation for UnsortedMPQ with " << num_jobs << " jobs" << endl;
    while (true) {
        time_slice++;
        // No jobs left to process
        if (v_mpq.is_empty()) {
            break;
        }

        // Process current job
        int time = v_mpq.min().length;
        ofs << v_mpq.min() << endl;       

        // The job is finished, if so remove from queue
        v_mpq.remove_min();
    }
    // Simulation finished
    ofs << "No more jobs to run" << endl << endl;
    return true;
}
bool run_sim_sorted(string input_file, string output_file) {
    // Attempt to open input file
    ifstream ifs(input_file);
    if (!ifs.is_open()) {
        cout << "Error opening: " << input_file << endl;
        return false;
    }

    // Attempt to open output file
    ofstream ofs(output_file);
    if (!ofs.is_open()) {
        cout << "Error opening: " << output_file << endl;
        return false;
    }

    // Create MPQs for simulation
    SortedMPQ<CPU_Job> ll_mpq;
    
    // Read jobs from input file and place in each MPQ
    int num_jobs = 0;
    CPU_Job temp;
    while (ifs >> temp) {
        ll_mpq.insert(temp);
        num_jobs++;
    }
    // Run simulation for linked list MPQ
    int time_slice = 0;
    ofs << "Running simulation for SortedMPQ with " << num_jobs << " jobs" << endl;
    while (true) {
        time_slice++;
        // No jobs left to process
        if (ll_mpq.is_empty()) {
            break;
        }
        
        // Process current job
        int time = ll_mpq.min().length;
        ofs << ll_mpq.min() << endl;       

        // The job is finished, if so remove from queue
        ll_mpq.remove_min();
    }
    // Simulation finished
    ofs << "No more jobs to run" << endl << endl;
    return true;
}
bool run_sim_heap(string input_file, string output_file) {
    // Attempt to open input file
    ifstream ifs(input_file);
    if (!ifs.is_open()) {
        cout << "Error opening: " << input_file << endl;
        return false;
    }

    // Attempt to open output file
    ofstream ofs(output_file);
    if (!ofs.is_open()) {
        cout << "Error opening: " << output_file << endl;
        return false;
    }

    // Create MPQs for simulation
    BinaryHeapMPQ<CPU_Job> bh_mpq;
    
    // Read jobs from input file and place in each MPQ
    int num_jobs = 0;
    CPU_Job temp;
    while (ifs >> temp) {
        bh_mpq.insert(temp);
        num_jobs++;
    }
    // Run simulation for binary heap MPQ
    int time_slice = 0;
    ofs << "Running simulation for BinaryHeapMPQ with " << num_jobs << " jobs" << endl;
    while (true) {
        time_slice++;
        // No jobs left to process
        if (bh_mpq.is_empty()) {
            break;
        }
        
        // Process current job
        int time = bh_mpq.min().length;
        ofs << bh_mpq.min() << endl;       

        // The job is finished, if so remove from queue
        bh_mpq.remove_min();
    }
    // Simulation finished
    ofs << "No more jobs to run" << endl << endl;
    return true;
}

/*
 * Timing simulation for MPQs
 *   input_file is name of jobs file
 *   output_file is name of file to write timings to
 */
bool time_sim(string input_file, string output_file) {
    // Attempt to open input file
    ifstream ifs(input_file);
    if (!ifs.is_open()) {
        cout << "Error opening: " << input_file << endl;
        return false;
    }

    // Attempt to open output file
    ofstream ofs(output_file);
    if (!ofs.is_open()) {
        cout << "Error opening: " << output_file << endl;
        return false;
    }

    // Create MPQs
    UnsortedMPQ<CPU_Job> v_mpq;
    SortedMPQ<CPU_Job> ll_mpq;
    BinaryHeapMPQ<CPU_Job> bh_mpq;
    
    // Read jobs from file and store in vector to later load into MPQs
    int num_jobs = 0;
    CPU_Job temp;
    vector<CPU_Job> jobs;
    while (ifs >> temp) {
        jobs.push_back(temp);
        num_jobs++;
    }

    steady_clock::time_point t1;
    steady_clock::time_point t2;
    duration<double> time_span;

    // Timing simulation for vector MPQ
    ofs << "Timing simulation for UnsortedMPQ with " << num_jobs << " jobs" << endl;
    
    // Start the timer for vector MPQ
    t1 = steady_clock::now();
    
    // Insert jobs into MPQ 
    for (auto x : jobs) {
        v_mpq.insert(x);
    }

    // Run the jobs
    int time_slice = 0;
    CPU_Job* current_job = nullptr;
    while (true) {
        time_slice++;
        // No jobs left to process
        if (v_mpq.is_empty()) {
            break;
        }
        
        // Process current job
        int time = v_mpq.min().length;
        while(time != 0){
            time--;
        }        

        // The job is finished, if so remove from queue
        v_mpq.remove_min();
    }

    // End the timer for vector MPQ
    t2 = steady_clock::now();
    
    // Calculate time for simulation and write to file
    time_span = duration_cast<duration<double>>(t2 - t1);
    ofs << "Timing: " << time_span.count() * 1000 << " millisec" << endl << endl;

    // Timing simulation for linked list MPQ
    ofs << "Timing simulation for SortedMPQ with " << num_jobs << " jobs" << endl;
    
    // Start the timer for linked list MPQ
    t1 = steady_clock::now();

    // Insert jobs into MPQ 
    for (auto x : jobs) {
        ll_mpq.insert(x);
    }

    // Run the jobs
    time_slice = 0;
    current_job = nullptr;
    while (true) {
        time_slice++;
        // No jobs left to process
        if (ll_mpq.is_empty()) {
            break;
        }
        
        // Process current job
        int time = ll_mpq.min().length;
        while(time != 0){
            time--;
        }        

        // The job is finished, if so remove from queue
        ll_mpq.remove_min();
    }

    // End the timer for linked list MPQ
    t2 = steady_clock::now();

    // Calculate time for simulation and write to file
    time_span = duration_cast<duration<double>>(t2 - t1);
    ofs << "Timing: " << time_span.count() * 1000 << " millisec" << endl << endl;

    // Timing simulation for binary heap MPQ
    ofs << "Timing simulation for BinaryHeapMPQ with " << num_jobs << " jobs" << endl;
    
    // Start the timer for binary heap MPQ
    t1 = steady_clock::now();

    // Insert jobs into MPQ 
    for (auto x : jobs) {
        bh_mpq.insert(x);
    }

    // Run the jobs
    time_slice = 0;
    current_job = nullptr;
    while (true) {
        time_slice++;
        // No jobs left to process
        if (bh_mpq.is_empty()) {
            break;
        }
        
        // Process current job
        int time = bh_mpq.min().length;
        while(time != 0){
            time--;
        }        

        // The job is finished, if so remove from queue
        bh_mpq.remove_min();
    }

    // End the timer for binary heap MPQ
    t2 = steady_clock::now();
    
    // Calculate time for simulation and write to file
    time_span = duration_cast<duration<double>>(t2 - t1);
    ofs << "Timing: " << time_span.count() * 1000 << " millisec" << endl << endl;
    return true;
}

#endif