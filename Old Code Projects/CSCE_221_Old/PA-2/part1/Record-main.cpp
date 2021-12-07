#include "Record.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Record rec;
    vector<Record> vec;

    // Attempt to open the file, exit on error
    ifstream ifs("/mnt/c/.School/CSCE_221/PA-2/Book.txt");
    if (!ifs.is_open()) {
        cout << "Book.txt not found";
        return 1;
    }

    // Load the records from the file into the vector,
    while (ifs >> rec) {
        vec.push_back(rec);
    }

    Record rasdf = Record("Larry Potter And The Chamber Of Secrets", "J. K. Rowling", "978-0439064873", "2000", "1st edition");
    
    // Print the records,
    for (auto x: vec) {
        cout << (x < rasdf) << endl << endl;
    }

    // // Test comparison operation.  With given data, record will only match itself
    // for (auto x: vec) {
    //     cout << "*************************" << endl;
    //     for (auto y: vec) {
    //         if (x == y) {
    //             cout << x.get_title() << endl;
    //             cout << x.get_author() << endl;
    //             cout << x.get_ISBN() << endl;
    //             cout << "***EQUAL***" << endl;
    //             cout << y.get_title() << endl;
    //             cout << y.get_author() << endl;
    //             cout << y.get_ISBN() << endl;
    //             cout << "-------------------------" << endl;
    //         }
    //     }
    // }
    return 0;
}