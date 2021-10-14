#include "Collection.h"
#include "Stress_ball.h"
#include "gtest/gtest.h"

using namespace std;

TEST(COLLECTION, BRACKET) {
  cout << "Attempting to create a Collection" << endl;
  Collection c5;
  cout << "Created a Collection" << endl;
  srand(time(0));
  int c1n = rand() % 10;
  if (c1n < 3) {
    c1n = 3;
  }
  // c1n=0;
  Stress_ball sb(Stress_ball_colors::green, Stress_ball_sizes::medium);
  cout << "Attempting to insert " << c1n + c1n + 1 << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c5.insert_item(Stress_ball());
  }
  c5.insert_item(sb);
  for (int i = 0; i < c1n; i++) {
    c5.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << c5.total_items() << endl;
  cout << "Attempting to access random index with [] operator" << endl;
  string color, size;

  int ex_color = (int)sb.get_color();
  int ur_color = (int)c5[c1n].get_color();
  int ex_size = (int)sb.get_size();
  int ur_size = (int)c5[c1n].get_size();

  if (ex_color == 0) {
    color = "red";
  } else if (ex_color == 1) {
    color = "blue";
  } else if (ex_color == 2) {
    color = "green";
  } else if (ex_color == 3) {
    color = "yellow";
  }

  if (ex_size == 0) {
    size = "small";
  } else if (ex_size == 1) {
    size = "medium";
  } else if (ex_size == 2) {
    size = "large";
  }
  cout << "\nExpected Stress_ball color: " << color;
  cout << "\nExpected Stress_ball size: " << size;

  if (ur_color == 0) {
    color = "red";
  } else if (ur_color == 1) {
    color = "blue";
  } else if (ur_color == 2) {
    color = "green";
  } else if (ur_color == 3) {
    color = "yellow";
  }

  if (ur_size == 0) {
    size = "small";
  } else if (ur_size == 1) {
    size = "medium";
  } else if (ur_size == 2) {
    size = "large";
  }

  cout << "\nYour Stress_ball color: " << color;

  cout << "\nYour Stress_ball size: " << size << endl;
  if (c5[c1n].get_color() == sb.get_color() &&
      c5[c1n].get_size() == sb.get_size()) {
    ASSERT_EQ(c5[c1n].get_color(), sb.get_color());
    ASSERT_EQ(c5[c1n].get_size(), sb.get_size());
  } else {
    cout << "[] is accessing the wrong index." << endl;
    ASSERT_EQ(c5[c1n].get_color(), sb.get_color());
    ASSERT_EQ(c5[c1n].get_size(), sb.get_size());
  }
}
