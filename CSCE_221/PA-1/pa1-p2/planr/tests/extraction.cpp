#include "Collection.h"
#include "Stress_ball.h"
#include "gtest/gtest.h"
#include <fstream>

using namespace std;

TEST(COLLECTION, EXTRACTION) {
  cout << "Attempting to create a Collection" << endl;
  Collection c;
  cout << "Created a Collection" << endl;
  cout << "Attempting to insert "
       << "5"
       << " items. " << endl;

  c.insert_item(
      Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
  c.insert_item(
      Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
  c.insert_item(
      Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large));
  c.insert_item(
      Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
  c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
  cout << "Items inserted: " << c.total_items() << endl;
  stringstream ss;
  cout << "Using << operator" << endl;
  ss << c;
  cout << "Checking output of << operator" << endl;
  if (ss.str() ==
          "(red,medium)(green,small)(blue,large)(yellow,medium)(red,small)" ||
      ss.str() == "(red,medium)\n(green,small)\n(blue,large)\n(yellow,medium)"
                  "\n(red,small)\n" ||
      ss.str() == "(red, medium)(green, small)(blue, large)(yellow, "
                  "medium)(red, small)" ||
      ss.str() == "(red, medium)\n(green, small)\n(blue, large)\n(yellow, "
                  "medium)\n(red, small)\n") {
    cout << "Passed" << endl;
    cout << "<< outputs: " << endl;
    cout << ss.str();
    ASSERT_TRUE(true);
  } else {
    cout << "\nYour << output: " << endl;
    cout << ss.str();
    cout << "\nExpected << output:" << endl;
    cout << "(red, medium)\n(green, small)\n(blue, large)\n(yellow, "
            "medium)\n(red, small)\n"
         << endl;
    ASSERT_TRUE(false);
  }
}
