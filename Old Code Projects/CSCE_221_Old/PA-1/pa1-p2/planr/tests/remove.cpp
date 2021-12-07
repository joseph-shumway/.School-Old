#include "gtest/gtest.h"
#include "Collection.h"
#include "Stress_ball.h"
#include "vector"

using namespace std;

struct CollectionTB {
  Collection * c;
  std::vector<Stress_ball> * ref;

  void insert(const Stress_ball & sb) {
    c->insert_item(sb);
    ref->push_back(sb);
  }

  void insert_n(const Stress_ball & sb, int n) {
    for(int i = 0; i < n; i++)
      insert(sb);
  }

  void remove_this(const Stress_ball & sb) {
    c->remove_this_item(sb);
    ref->erase(std::remove_if(ref->begin(), ref->end(), [sb](const Stress_ball sb1) { return sb1 == sb; }), ref->end());
  }

  void validate_state() {
    ASSERT_EQ(c->total_items(), ref->size()) << "The total number of items in the collection does not match the expected number after removal";

    for(int i = 0; i < c->total_items(); i++) {
      ASSERT_TRUE((*c)[i] == (*ref)[i]) << "Removing an item resulted in a invalid state";
    }
  }
};

TEST(COLLECTION, REMOVE0) {
  /* SETUP TESTS */
  Stress_ball target1(Stress_ball_colors::red,   Stress_ball_sizes::small);
  Stress_ball target2(Stress_ball_colors::blue,  Stress_ball_sizes::large);
  Stress_ball target3(Stress_ball_colors::green, Stress_ball_sizes::medium);

  Stress_ball padding1(Stress_ball_colors::blue, Stress_ball_sizes::small);
  Stress_ball padding2(Stress_ball_colors::green, Stress_ball_sizes::large);

  srand(0x456789U);
  
  const char * THROW_MSG  = "Removing item not in the collection should throw";

  for(int i = 0; i < 10; i++) {
    Collection c;
    std::vector<Stress_ball> ref;

    CollectionTB t;
    t.c = &c;
    t.ref = &ref;

    /* Creating following Collection: */
    /* target1 [padding sb] target2 [padding sb] target3 */

    t.insert(target1);
    t.insert_n(padding1, rand() % 25);
    t.insert(target2);
    t.insert_n(padding2, rand() % 15);
    t.insert(target3);


    // Remove 1
    t.remove_this(target1);
    ASSERT_ANY_THROW(t.remove_this(target1)) << THROW_MSG;
    t.validate_state();

    // Remove 2
    t.remove_this(target2);
    ASSERT_ANY_THROW(t.remove_this(target2)) << THROW_MSG;
    t.validate_state();

    // Remove 3
    t.remove_this(target3);
    ASSERT_ANY_THROW(t.remove_this(target3)) << THROW_MSG;
    t.validate_state();
  }
}

TEST(COLLECTION, REMOVE1) {
  Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);
  Stress_ball not_sb(Stress_ball_colors::green, Stress_ball_sizes::large);

  srand(time(0));
  int c1n = rand() % 25;

  cout << "Attempting to create a Collection" << endl;
  Collection c;
  cout << "Created a Collection" << endl;
  cout << "Attempting to insert " << c1n + 4 << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c.insert_item(not_sb);
  }
  c.insert_item(sb);
  c.insert_item(not_sb);
  c.insert_item(not_sb);
  c.insert_item(not_sb);
  cout << "Total number of Stress_balls inserted: " << c.total_items() << endl;
  cout << "Removing a Stress_ball object from Collection. (Only the first "
          "occurance needs to be removed.)"
       << endl;
  c.remove_this_item(sb);
  cout << "Remaining Stress_balls: " << c.total_items() << endl;
  cout << "Checking whether the intended Stress_ball is removed: "
       << (c.contains(sb) ? "False" : "True") << endl;
  ASSERT_FALSE(c.contains(sb));
  c.insert_item(sb);
  c.insert_item(sb);
  cout << "Inserting again. Total number of Stress_balls: " << c.total_items()
       << endl;
  cout << "Removing a Stress_ball object from Collection. (Only the first "
          "occurance needs to be removed.)"
       << endl;
  c.remove_this_item(sb);
  cout << "Checking whether one occurance of Stress_ball is removed: "
       << (c.contains(sb) ? "True" : "False") << endl;
  ASSERT_TRUE(c.contains(sb));
}

TEST(COLLECTION, REMOVE2) {
  Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);
  Stress_ball not_sb(Stress_ball_colors::green, Stress_ball_sizes::large);

  srand(time(0));
  int c1n = rand() % 25;

  cout << "Attempting to create a Collection" << endl;
  Collection c;
  cout << "Created a Collection" << endl;
  cout << "Attempting to insert " << c1n + 4 << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c.insert_item(not_sb);
  }
  c.insert_item(sb);
  c.insert_item(not_sb);
  c.insert_item(not_sb);
  c.insert_item(not_sb);
  cout << "Total number of Stress_balls inserted: " << c.total_items() << endl;
  cout << "Removing a Stress_ball object from Collection. (Only the first "
          "occurance needs to be removed.)"
       << endl;
  c.remove_this_item(sb);
  cout << "Remaining Stress_balls: " << c.total_items() << endl;
  cout << "Checking whether the intended Stress_ball is removed: "
       << (c.contains(sb) ? "False" : "True") << endl;
  ASSERT_FALSE(c.contains(sb));
  c.insert_item(sb);
  c.insert_item(sb);
  cout << "Inserting again. Total number of Stress_balls: " << c.total_items()
       << endl;
  cout << "Removing a Stress_ball object from Collection. (Only the first "
          "occurance needs to be removed.)"
       << endl;
  c.remove_this_item(sb);
  cout << "Checking whether one occurance of Stress_ball is removed: "
       << (c.contains(sb) ? "True" : "False") << endl;
  ASSERT_TRUE(c.contains(sb));
}

TEST(COLLECTION, REMOVE3) {
  Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);
  Stress_ball not_sb(Stress_ball_colors::green, Stress_ball_sizes::large);

  cout << "Attempting to create a Collection" << endl;
  Collection c;
  cout << "Created a Collection" << endl;
  cout << "Attempting to insert " << 4 << " items. " << endl;
  c.insert_item(sb);
  c.insert_item(not_sb);
  c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
  c.insert_item(
      Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
  cout << "Total number of Stress_balls inserted: " << c.total_items() << endl;
  Collection copy(c);
  // cout<<c;
  cout << "Removing any random Stress_ball object from Collection." << endl;
  Stress_ball removed = c.remove_any_item();
  // cout<<removed;
  cout << "Remaining Stress_balls: " << c.total_items() << endl;
  cout << "Expected number of Stress_balls: " << 3 << endl;
  // cout<<c;
  cout << "Checking if removed stress_ball was part of Collection: "
       << (copy.contains(removed) ? "True" : "False") << endl;
  // cout<<copy;
  ASSERT_TRUE(copy.contains(removed));
  ASSERT_EQ(c.total_items(), 3);
}

TEST(COLLECTION, REMOVE4) {
  Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);
  Stress_ball not_sb(Stress_ball_colors::green, Stress_ball_sizes::large);

  cout << "Attempting to create a Collection" << endl;
  Collection c;
  cout << "Created a Collection" << endl;
  srand(time(0));
  int c1n = rand() % 100;
  if (c1n < 3) {
    c1n = 3;
  }
  // c1n=0;
  cout << "Attempting to insert " << c1n << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c.insert_item(Stress_ball());
  }
  cout << "Total number of Stress_balls inserted: " << c.total_items() << endl;
  cout << "Removing any random Stress_ball object from Collection." << endl;
  c.remove_any_item();
  cout << "Remaining Stress_balls: " << c.total_items() << endl;
  cout << "Emptying the Collection" << endl;
  c.make_empty();
  cout << "Remaining Stress_balls: " << c.total_items() << endl;
  //bool check = false;
  try {
    cout << "Removing from an empty Collection" << endl;
    c.remove_any_item();
    cout << "Remaining Stress_balls: " << c.total_items() << endl;
  } catch (...) {
    cout << "Throw() triggered. Remaining Stress_balls: " << c.total_items()
         << endl;
    //check = true;
  }
  // ASSERT_TRUE(check);
}
