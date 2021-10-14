#include "gtest/gtest.h"
#include "Collection.h"

using namespace std;

TEST(COLLECTION, NO_ARGUMENTS) {
  cout << "Attempting to create Collection objects." << endl;
  Collection c;
  Collection c1 = Collection();
  Collection *c2 = new Collection();
  cout << "Created Collection objects." << endl;
  int *p = (int *)&c;
  int *p1 = (int *)&c1;
  int *p2 = (int *)c2;
  cout << "Checking if parameters are initialized accordingly." << endl;
  if (*p == 0 && *p1 == 0 && *p2 == 0) {
    cout << "Passed!" << endl;
    ASSERT_TRUE(true);
  } else {
    cout << "Fail: size and capacity not 0 or array not null." << endl;
    ASSERT_TRUE(false);
  }
}