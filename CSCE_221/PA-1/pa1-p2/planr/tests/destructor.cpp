#include "gtest/gtest.h"
#include "Collection.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, DESTRUCTOR) {
  srand(time(0));
  int c1n = rand() % 15;
  if (c1n == 0) {
    c1n = 1;
  }
  int cap = rand() % 20;
  cout << "Attempting to create a Collection with initial capacity: " << cap
       << endl;
  Collection cd_dest(cap);
  cout << "Created a Collection with initial capacity: " << cap << endl;
  cout << "Attempting to insert " << c1n << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    cd_dest.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << cd_dest.total_items() << endl;
  cout << "Attempting to use Destructor." << endl;
  cd_dest.~Collection();
  cout << "Checking if destructor has emptied the Collection." << endl;
  if (cd_dest.is_empty()) {
    cout << "Passed: Collection object is empty" << endl;
    ASSERT_TRUE(true);
  } else {
    cout << "Fail: Collection object is not empty. Check is_empty() too."
         << endl;
    ASSERT_TRUE(false);
  }
}
