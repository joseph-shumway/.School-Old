#include "gtest/gtest.h"
#include "Collection.h"
#include "Stress_ball.h"

using namespace std;
using std::cout;
using std::endl;

TEST(COLLECTION, COPY0) {
  srand(time(0));
  int c1n = rand() % 15;
  if (c1n == 0) {
    c1n = 1;
  }
  int cap = rand() % 20;
  int cap2 = rand() % 20;
  cout << "Attempting to create a Collection with initial capacity: " << cap
       << endl;
  Collection c1(cap);
  cout << "Created a Collection with initial capacity: " << cap << endl;
  cout << "Attempting to create a second Collection with initial capacity: "
       << cap2 << endl;
  Collection c2(cap2);
  cout << "Created a Collection with initial capacity: " << cap2 << endl;

  cout << "Attempting to insert " << c1n << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c1.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << c1.total_items() << endl;
  cout << "Attempting to insert " << c1n << " items into second Collection. "
       << endl;
  for (int i = 0; i < c1n; i++) {
    c2.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << c2.total_items() << endl;
  /*    c1.insert_item(Stress_ball());
      c1.insert_item(Stress_ball());
      c1.insert_item(Stress_ball());
      c1.insert_item(Stress_ball());
      c1.insert_item(Stress_ball());
      c1.insert_item(Stress_ball());
      c1.insert_item(Stress_ball());*/

  Stress_ball *arr1 = &(c1[0]);
  {
    cout << "Attempting to use Copy Assignment." << endl;
    c2 = c1;
    cout << "Performing memory location test." << endl;
    if (arr1 == &(c2[0])) {
      cout << "Fail: What happens with memory locations  of objects when a "
              "copy assignment is used. Are they same or different?"
           << endl;
      ASSERT_TRUE(false);
    } else {
      cout << "Passed: Memory location test!" << endl;
      ASSERT_TRUE(true);
    }

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

TEST(COLLECTION, COPY1) {
  srand(time(0));
  int c1n = rand() % 15;
  if (c1n == 0) {
    c1n = 1;
  }
  int cap = rand() % 20;
  int cap2 = rand() % 20;
  cout << "Attempting to create a Collection with initial capacity: " << cap
       << endl;
  Collection c1(cap);
  cout << "Created a Collection with initial capacity: " << cap << endl;
  cout << "Attempting to create a second Collection with initial capacity: "
       << cap2 << endl;
  Collection c2(cap2);
  cout << "Created a Collection with initial capacity: " << cap2 << endl;

  cout << "Attempting to insert " << c1n << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c1.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << c1.total_items() << endl;
  cout << "Attempting to insert " << c1n << " items into second Collection. "
       << endl;
  for (int i = 0; i < c1n; i++) {
    c2.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << c2.total_items() << endl;
  /*     c1.insert_item(Stress_ball());
       c1.insert_item(Stress_ball());
       c1.insert_item(Stress_ball());
       c1.insert_item(Stress_ball());
       c1.insert_item(Stress_ball());
       c1.insert_item(Stress_ball());
       c1.insert_item(Stress_ball());
*/
  Stress_ball *arr1 = &(c1[0]);
  {
    cout << "Attempting to use Copy Assignment." << endl;
    c2 = c2;
    cout << "Performing memory location test." << endl;
    if (arr1 == &(c2[0])) {
      cout << "Fail: What happens with memory locations of objects when a copy "
              "assignment is used. Are they same or different?";
      ASSERT_FALSE(arr1 == &(c2[0]));
    } else {
      cout << "Passed: Memory location test!" << endl;
      ASSERT_FALSE(arr1 == &(c2[0]));
    }

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