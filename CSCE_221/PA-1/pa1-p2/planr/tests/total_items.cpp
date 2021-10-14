#include "gtest/gtest.h"
#include "Collection.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, TOTAL_ITEMS) {
  cout << "Attempting to create a Collection" << endl;
  Collection c;
  cout << "Created a Collection" << endl;
  cout << "Attempting to insert "
       << "9"
       << " items. " << endl;
  c.insert_item(
      Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::large));
  c.insert_item(
      Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large));
  c.insert_item(
      Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
  c.insert_item(
      Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::small));
  c.insert_item(
      Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::small));
  c.insert_item(
      Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
  c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
  c.insert_item(
      Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
  c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
  cout << "Items inserted: " << c.total_items() << endl;
  ASSERT_EQ(c.total_items(), 9);
}

TEST(COLLECTION, TOTAL_ITEMS_COLOR) {
  cout << "Attempting to create a Collection" << endl;
  Collection c;
  cout << "Created a Collection" << endl;
  cout << "Attempting to insert "
       << "9"
       << " items. " << endl;
  c.insert_item(
      Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::large));
  c.insert_item(
      Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large));
  c.insert_item(
      Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
  c.insert_item(
      Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::small));
  c.insert_item(
      Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::small));
  c.insert_item(
      Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
  c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
  c.insert_item(
      Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
  c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
  cout << "Items inserted: " << c.total_items() << endl;
  cout << "checking for blue stress_balls" << endl;
  cout << "Expected  blue stress_balls: " << 3 << endl;
  cout << "Actual  blue stress_balls: "
       << c.total_items(Stress_ball_colors::blue) << endl;
  ASSERT_EQ(c.total_items(Stress_ball_colors::blue), 3);
}

TEST(COLLECTION, TOTAL_ITEMS_SIZE) {
  cout << "Attempting to create a Collection" << endl;
  Collection c;
  cout << "Created a Collection" << endl;
  cout << "Attempting to insert "
       << "9"
       << " items. " << endl;
  c.insert_item(
      Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::large));
  c.insert_item(
      Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large));
  c.insert_item(
      Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
  c.insert_item(
      Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::small));
  c.insert_item(
      Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::small));
  c.insert_item(
      Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
  c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
  c.insert_item(
      Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
  c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
  cout << "Items inserted: " << c.total_items() << endl;
  cout << "checking for large stress_balls" << endl;
  cout << "Expected  large stress_balls: " << 3 << endl;
  cout << "Actual  large stress_balls: "
       << c.total_items(Stress_ball_sizes::large) << endl;

  ASSERT_EQ(c.total_items(Stress_ball_sizes::large), 3);
}