#include "SortedMPQ.h"
#include <chrono>
using namespace std;

SortedMPQ<int> h;

srand(time(NULL));
for(int i = 0; i < 100; i++){
  h.insert(rand()%1000);
}
for (int i = 0; i < 10; i++) {
  h.remove_min();
}

auto beginI = chrono::high_resolution_clock::now();
for (int i = 0; i < 20; i++) {
  h.insert(rand()%1000);
}
auto endI = chrono::high_resolution_clock::now();

auto beginR = chrono::high_resolution_clock::now();
for (int i = 0; i < 20; i++) {
  h.remove_min();
}
auto endR = chrono::high_resolution_clock::now();

auto timeI = chrono::duration_cast<chrono::microseconds>(endI - beginI);
auto timeR = chrono::duration_cast<chrono::microseconds>(endR - beginR);

if (timeI.count()/20.0 > timeR.count()/20.0) {
  cout << "\nInsertion took longer than removing the minimum\n\n";
  ASSERT_TRUE(true);
}
else {
  cout << "\nRemoving the minimum took longer than insertion\n\n";
  ASSERT_TRUE(false);
}