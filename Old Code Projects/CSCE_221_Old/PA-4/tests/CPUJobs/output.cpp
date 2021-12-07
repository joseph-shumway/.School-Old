#include "cpu-job.h"
#include <iostream>
#include <sstream>
#include <string>
#include <random>
using namespace std;

srand(time(NULL));
int r1 = rand()%1000;
int r2 = rand()%10+1;
int r3 = rand()%21;

CPU_Job a;
CPU_Job b(2021, 5, -7);
CPU_Job c;
c.ID = r1;
c.length = r2;
c.prior = r3;

string testA = "Job 0 with length 0 and priority 0";
string testB = "Job 2021 with length 5 and priority -7";
string testC = "Job " + to_string(r1) + " with length " + to_string(r2) + " and priority " + to_string(r3);

stringstream ss;
ss << a;
string s = ss.str();
cout << "\nExpected Output: " << testA << endl;
cout << "Your Output: " << s << endl << endl;
ASSERT_EQ(testA, s);
ss.str("");

ss << b;
s = ss.str();
cout << "Expected Output: " << testB << endl;
cout << "Your Output: " << s << endl << endl;
ASSERT_EQ(testB, s);
ss.str("");

ss << c;
s = ss.str();
cout << "Expected Output: " << testC << endl;
cout << "Your Output: " << s << endl << endl;
ASSERT_EQ(testC, s);