#include "gtest/gtest.h"
#include "Collection.h"

using namespace std;

TEST(COLLECTION, ONE_ARGUEMENT) {
  srand(time(0));
  int c1n = rand() % 100;
  cout << "Attempting to create Collection objects." << endl;
  Collection c(c1n);
  Collection c1 = Collection(c1n + 1);
  Collection *c2 = new Collection(c1n + 2);
  cout << "Created Collections with initial capacities: " << c1n << " "
       << c1n + 1 << " " << c1n + 2 << " " << endl;
  cout << "Checking if the Collection object is empty. " << endl;
  if (c.is_empty() && c1.is_empty() && (*c2).is_empty()) {
    cout << "Passed!" << endl;
    ASSERT_TRUE(true);
  } else {
    cout << "Fail: Collection(s) is/are not empty after creating. " << endl;
    ASSERT_TRUE(false);
  }
}
