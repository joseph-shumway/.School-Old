#include "gtest/gtest.h"
#include "Collection.h"

using namespace std;

TEST(COLLECTION, MOVE0) {
  srand(time(0));
  int c1n = rand() % 15;
  if (c1n == 0) {
    c1n = 1;
  }
  int cap = rand() % 20;
  cout << "Attempting to create a Collection with initial capacity: " << cap
       << endl;
  Collection c1(cap);
  cout << "Created a Collection with initial capacity: " << cap << endl;
  cout << "Attempting to insert " << c1n << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c1.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << c1.total_items() << endl;
  Stress_ball *arr1 = &(c1[0]);
  cout << "Attempting to use Move Constructor." << endl;
  Collection c2(move(c1));
  cout << "Performing memory location test." << endl;
  if (arr1 == &(c2[0])) {
    cout << "Passed: Memory location test!" << endl;
    ASSERT_TRUE(true);
  } else {
    cout << "Fail: What happens with memory locations of objects when a move "
            "constructor is used. Are they same or different?"
         << endl;
    ASSERT_TRUE(false);
  }
  cout << "Checking if moved object is empty or not." << endl;
  if (c1.is_empty()) {
    cout << "Passed: It is empty" << endl;
    ASSERT_TRUE(true);
  } else {
    cout << "Fail: Should the object that is passed to the constructor be "
            "empty after constructor's operation is completed?"
         << endl;
    ASSERT_TRUE(false);
  }
}

TEST(COLLECTION, MOVE1) {
  srand(time(0));
  int c1n = rand() % 15;
  if (c1n == 0) {
    c1n = 1;
  }
  int cap = rand() % 20;
  cout << "Attempting to create a Collection with initial capacity: " << cap
       << endl;
  Collection c1(cap);
  cout << "Created a Collection with initial capacity: " << cap << endl;
  cout << "Attempting to insert " << c1n << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c1.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << c1.total_items() << endl;

  Stress_ball *arr1 = &(c1[0]);
  cout << "Attempting to use Move Constructor." << endl;
  Collection c2(move(c1));
  cout << "Performing memory location test." << endl;
  if (arr1 == &(c2[0])) {
    cout << "Passed: Memory location test!" << endl;
    ASSERT_TRUE(true);
  } else {
    cout << "Fail: What happens with memory locations of objects when a move "
            "constructor is used. Are they same or different?"
         << endl;
    ASSERT_TRUE(false);
  }
}

TEST(COLLECTION, MOVE2) {
  srand(time(0));
  int c1n = rand() % 15;
  if (c1n == 0) {
    c1n = 1;
  }
  int cap = rand() % 20;
  cout << "Attempting to create a Collection with initial capacity: " << cap
       << endl;
  Collection c1(cap);
  cout << "Created a Collection with initial capacity: " << cap << endl;
  cout << "Attempting to insert " << c1n << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c1.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << c1.total_items() << endl;
  cout << "Attempting to use Move Constructor." << endl;
  Collection c2(move(c1));
  cout << "Performing memory location test." << endl;
  if (c1.is_empty()) {
    cout << "Passed: Memory location test!" << endl;
    ASSERT_TRUE(true);
  } else {
    cout << "Fail: Should the object that is passed to the constructor be "
            "empty after constructor's operation is completed?"
         << endl;
    ASSERT_TRUE(false);
  }
}