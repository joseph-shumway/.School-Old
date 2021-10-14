#include "gtest/gtest.h"
#include "Collection.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, CONTAINS) {
  cout << "Attempting to create a Collection" << endl;
  Collection c;
  cout << "Created a Collection" << endl;
  cout << "Attempting to insert n items. " << endl;
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
  cout << "Items inserted" << endl;
  Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);
  Stress_ball not_sb(Stress_ball_colors::green, Stress_ball_sizes::medium);
  cout << "Checking for contains()" << endl;
  ASSERT_TRUE(c.contains(sb));
  ASSERT_FALSE(c.contains(not_sb));
}
