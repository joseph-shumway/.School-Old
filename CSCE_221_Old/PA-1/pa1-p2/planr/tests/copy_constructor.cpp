#include "Collection.h"
#include "Stress_ball.h"
#include "gtest/gtest.h"

using namespace std;

TEST(COLLECTION, COPY0) {
  srand(time(0));
  int c1n = rand() % 15;
  int cap = rand() % 20;
  if (cap == 0) {
    cap = 1;
  }
  if (c1n == 0) {
    c1n = 1;
  }
  cout << "Attempting to create a Collection with initial capacity: " << cap
       << endl;
  Collection c1(cap);
  cout << "Created a Collection with initial capacity: " << cap << endl;
  cout << "Attempting to insert " << c1n << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c1.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << c1.total_items() << endl;
  /*c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  */
  Stress_ball *arr1 = &(c1[0]);
  {
    cout << "Attempting to use Copy Constructor." << endl;
    Collection c3(c1);
    cout << "Performing memory location test." << endl;
    if (arr1 == &(c3[0])) {
      cout << "Fail: What happens with memory locations of objects when a copy "
              "constructor is used. Are they same or different?"
           << endl;
      ASSERT_FALSE(arr1 == &(c3[0]));
    } else {
      cout << "Passed: Memory location test!" << endl;
      ASSERT_FALSE(arr1 == &(c3[0]));
    }
    cout << "Checking if copied and original Collection have the same number "
            "of Stress_balls."
         << endl;
    if (c1.total_items() == c3.total_items()) {
      cout << "Passed: Copied and original Collection have the same number of "
              "Stress_balls"
           << endl;
      ASSERT_TRUE(true);
    } else {
      cout << "Fail: Copied object and Original object do not have same number "
              "of items."
           << endl;
      ASSERT_TRUE(false);
    }
  }
}

TEST(COLLECTION, COPY1) {
  srand(time(0));
  int c1n = rand() % 15;
  int cap = rand() % 20;
  if (c1n == 0) {
    c1n = 1;
  }
  cout << "Attempting to create a Collection with initial capacity: " << cap
       << endl;
  Collection c1(cap);
  cout << "Created a Collection with initial capacity: " << cap << endl;
  cout << "Attempting to insert " << c1n << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c1.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << c1.total_items() << endl;
  /*c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  c1.insert_item(Stress_ball());
  */
  {
    cout << "Attempting to use Copy Constructor." << endl;
    Collection c2(c1);
    cout << "Checking if copied and original Collection have the same number "
            "of Stress_balls."
         << endl;
    if (c1.total_items() == c2.total_items()) {
      cout << "Passed: Copied and original Collection have the same number of "
              "Stress_balls"
           << endl;
      ASSERT_TRUE(true);
    } else {
      cout << "Fail: Copied object and Original object do not have same number "
              "of items."
           << endl;
      ASSERT_TRUE(false);
    }
  }
}