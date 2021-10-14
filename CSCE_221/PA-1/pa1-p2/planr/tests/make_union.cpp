#include "gtest/gtest.h"
#include "Collection.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, MAKE_UNION) {
  cout << "Attempting to create two Collections" << endl;
  Collection c;
  Collection c1;
  cout << "Created" << endl;
  srand(time(0));
  int c1n = rand() % 10;
  int c2n = rand() % 10;
  if (c1n < 3) {
    c1n = 3;
  }
  if (c2n < 3) {
    c2n = 3;
  }
  cout << "Attempting to insert " << c1n * 5 << " items to Collection 1. "
       << endl;
  for (int i = 0; i < c1n; i++) {
    c.insert_item(
        Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
    c.insert_item(
        Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
    c.insert_item(
        Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large));
    c.insert_item(
        Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
    c.insert_item(
        Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
  }
  cout << "Items inserted: " << c.total_items() << endl;
  cout << "Attempting to insert " << c2n * 5 << " items to Collection 2. "
       << endl;
  for (int i = 0; i < c2n; i++) {
    c1.insert_item(
        Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
    c1.insert_item(
        Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
    c1.insert_item(
        Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
    c1.insert_item(
        Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
    c1.insert_item(
        Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
  }
  cout << "Items inserted: " << c1.total_items() << endl;
  cout << "Before Union:\nCollection one size: " << c1n * 5 << endl;
  cout << "Collection two size: " << c2n * 5 << endl;
  Collection c2 = make_union(c, c1);
  ASSERT_EQ(c2.total_items(), 5 * (c1n + c2n));
  cout << "After Union:\nCollection three size: " << c2.total_items() << endl;
  cout << "Number of balls of a color (Ex: red): "
       << c2.total_items(Stress_ball_colors::red) << endl;
  cout << "Expected number of balls of a color (Ex: red): " << 2 * (c1n + c2n)
       << endl;
  cout << "Number of balls of a size (Ex: small): "
       << c2.total_items(Stress_ball_sizes::small) << endl;
  cout << "Expected number of balls of a size (Ex: small): " << 2 * (c1n + c2n)
       << endl;

  if (c2.total_items(Stress_ball_colors::red) == 2 * (c1n + c2n) &&
      c2.total_items(Stress_ball_sizes::small) == 2 * (c1n + c2n)) {
    ASSERT_TRUE(true);
  } else {
    cout << "After union operation, the Stress_balls of both the Collections "
            "should be present in the third Collection. Some Stress_Balls are "
            "missing or have changed."
         << endl;
    ASSERT_TRUE(false);
  }
}
