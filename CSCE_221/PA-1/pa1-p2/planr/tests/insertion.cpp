#include "gtest/gtest.h"
#include "Collection.h"
#include "Stress_ball.h"

#include <sstream>

using namespace std;

TEST(COLLECTION, INSERTION) {
  std::stringstream ss;

  cout << "Attempting to create a Collection" << endl;
  Collection c;
  cout << "Created a Collection" << endl;
  ss << "blue large" << endl;
  ss << "red medium" << endl;
  ss << "red medium" << endl;
  ss << "blue large" << endl;
  ss << "red medium" << endl;
  ss << "green small" << endl;
  ss << "blue small" << endl;
  ss << "yellow medium" << endl;
  ss << "yellow small" << endl;
  ss << "green medium";

  cout << "Success" << endl;
  cout << "Using >> opertor" << endl;
  
  ss >> c;
  cout << "Checking if the contents in the file match the Collection object"
       << endl;
  ASSERT_EQ(c.total_items(), 10);
  ASSERT_EQ(c.total_items(Stress_ball_colors::yellow), 2);
  ASSERT_EQ(c.total_items(Stress_ball_sizes::medium), 5);
  ASSERT_EQ(c.total_items(Stress_ball_colors::green), 2);
  ASSERT_EQ(c.total_items(Stress_ball_sizes::small), 3);
  ASSERT_EQ(c.total_items(Stress_ball_colors::blue), 3);
  ASSERT_EQ(c.total_items(Stress_ball_colors::red), 3);
  ASSERT_EQ(c.total_items(Stress_ball_sizes::large), 2);
}
