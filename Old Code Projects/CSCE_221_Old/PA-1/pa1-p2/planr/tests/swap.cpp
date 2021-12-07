#include "gtest/gtest.h"
#include "Collection.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, SWAP) {
  cout << "Attempting to create two Collections" << endl;
  Collection c1;
  Collection c2;
  cout << "Created" << endl;
  srand(time(0));
  int c1n = rand() % 10;
  if (c1n < 3) {
    c1n = 3;
  }
  int c2n = rand() % 10;
  if (c2n < 3) {
    c2n = 3;
  }
}
