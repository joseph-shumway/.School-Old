#include "gtest/gtest.h"
#include "Collection.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, MAKE_EMPTY) {
  cout << "Attempting to create a Collection with capacity 3" << endl;
  Collection cd(3);
  cout << "Created a Collection with initial capacity: " << 3 << endl;
  cout << "Attempting to insert " << 3 << " items. " << endl;
  cd.insert_item(
      Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
  cd.insert_item(
      Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::small));
  cd.insert_item(
      Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
  cout << "Items inserted: " << cd.total_items() << endl;
  cout << "Attempting to empty Collection." << endl;
  cd.make_empty();

  if (cd.is_empty()) {
    cout << "Passed" << endl;
    ASSERT_TRUE(true);
  } else {
    cout << "Fail: check if the necessary fields are 0 (or) NULL" << endl;
    ASSERT_TRUE(false);
  }
}
