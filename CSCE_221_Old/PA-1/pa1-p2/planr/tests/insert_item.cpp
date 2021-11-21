#include "gtest/gtest.h"
#include "Collection.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, INSERT_ITEM0) {
  srand(time(0));
  int c1n = rand() % 15;
  if (c1n == 0) {
    c1n = 1;
  }
  int cap = rand() % 20;
  cout << "Attempting to create a Collection with initial capacity: " << cap
       << endl;
  Collection cir(cap);
  cout << "Created a Collection with initial capacity: " << cap << endl;
  cout << "Attempting to insert " << c1n << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    cir.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << cir.total_items() << endl;
  /*cir.insert_item(Stress_ball(Stress_ball_colors::green,
  Stress_ball_sizes::large));
  cir.insert_item(Stress_ball(Stress_ball_colors::blue,
  Stress_ball_sizes::large));
  cir.insert_item(Stress_ball(Stress_ball_colors::red,
  Stress_ball_sizes::medium));
  cir.insert_item(Stress_ball(Stress_ball_colors::blue,
  Stress_ball_sizes::small));
  cir.insert_item(Stress_ball(Stress_ball_colors::yellow,
  Stress_ball_sizes::small));
  cir.insert_item(Stress_ball(Stress_ball_colors::blue,
  Stress_ball_sizes::medium));
  cir.insert_item(Stress_ball(Stress_ball_colors::red,
  Stress_ball_sizes::large));
  cir.insert_item(Stress_ball(Stress_ball_colors::green,
  Stress_ball_sizes::small));
  cir.insert_item(Stress_ball(Stress_ball_colors::red,
  Stress_ball_sizes::small));
  */
  // cir.insert_item(Stress_ball(Stress_ball_colors::red,
  // Stress_ball_sizes::small));
  cout << "Expected number of items: " << c1n << endl;
  if (cir.total_items(), c1n)
    ASSERT_EQ(cir.total_items(), c1n);
  else {
    ASSERT_EQ(cir.total_items(), c1n);
  }
}

TEST(COLLECTION, INSERT_ITEM1) {
  cout << "Attempting to create a Collection." << endl;
  Collection cir;
  cout << "Created a Collection" << endl;
  srand(time(0));
  int c1n = rand() % 10;
  int c2n = rand() % 10;
  if (c1n == 0) {
    c1n = 1;
  }
  if (c2n == 0) {
    c2n = 1;
  }
  int num = rand() % 4;
  std::string color, size, color2;
  int num_size = rand() % 3;
  if (num == 0) {
    color = "red";
  } else if (num == 1) {
    color = "blue";
  } else if (num == 2) {
    color = "green";
  } else if (num == 3) {
    color = "yellow";
  }

  if (num_size == 0) {
    size = "small";
  } else if (num_size == 1) {
    size = "medium";
  } else if (num_size == 2) {
    size = "large";
  }
  cout << "Attempting to insert " << c1n << " items of color " << color
       << " and size " << size << endl;
  for (int i = 0; i < c1n; i++) {
    cir.insert_item((Stress_ball(static_cast<Stress_ball_colors>(num),
                                 static_cast<Stress_ball_sizes>(num_size))));
  }
  int num1 = rand() % 4;
  if (num1 == num) {
    num1 = (num + 1) % 4;
  }
  if (num1 == 0) {
    color = "red";
  } else if (num1 == 1) {
    color = "blue";
  } else if (num1 == 2) {
    color = "green";
  } else if (num1 == 3) {
    color = "yellow";
  }
  cout << "Attempting to insert " << c2n << " items of color " << color
       << " and size " << size << endl;
  for (int i = 0; i < c2n; i++) {
    cir.insert_item(Stress_ball(static_cast<Stress_ball_colors>(num1),
                                static_cast<Stress_ball_sizes>(num_size)));
  }
  /*cir.insert_item(Stress_ball(Stress_ball_colors::green,
  Stress_ball_sizes::large));
  cir.insert_item(Stress_ball(Stress_ball_colors::blue,
  Stress_ball_sizes::large));
  cir.insert_item(Stress_ball(Stress_ball_colors::red,
  Stress_ball_sizes::medium));
  cir.insert_item(Stress_ball(Stress_ball_colors::blue,
  Stress_ball_sizes::small));
  cir.insert_item(Stress_ball(Stress_ball_colors::yellow,
  Stress_ball_sizes::small));
  cir.insert_item(Stress_ball(Stress_ball_colors::blue,
  Stress_ball_sizes::medium));
  cir.insert_item(Stress_ball(Stress_ball_colors::red,
  Stress_ball_sizes::large));
  cir.insert_item(Stress_ball(Stress_ball_colors::green,
  Stress_ball_sizes::small));
  cir.insert_item(Stress_ball(Stress_ball_colors::red,
  Stress_ball_sizes::small));
      */
  cout << "Output comparison:\n";
  cout << "Expected number of items: " << c2n + c1n << endl;
  cout << "Inserted number of items: " << cir.total_items() << endl;

  cout << "Expected number of items of a single color: " << c1n << endl;
  cout << "Inserted number of items of a single color: "
       << cir.total_items(static_cast<Stress_ball_colors>(num)) << endl;
  if (cir.total_items() == c2n + c1n &&
      cir.total_items(static_cast<Stress_ball_colors>(num)) == c1n) {
    ASSERT_EQ(cir.total_items(), c2n + c1n);
    ASSERT_EQ(cir.total_items(static_cast<Stress_ball_colors>(num)), c1n);
  } else {
    ASSERT_EQ(cir.total_items(), c2n + c1n);
    ASSERT_EQ(cir.total_items(static_cast<Stress_ball_colors>(num)), c1n);
  }
}

TEST(COLLECTION, INSERT_ITEM2) {
  srand(time(0));
  int c1n = rand() % 15;
  if (c1n == 0) {
    c1n = 1;
  }
  cout << "Attempting to create a Collection with initial capacity: " << 5
       << endl;
  Collection c1(5);
  cout << "Created a Collection with initial capacity: " << 5 << endl;
  cout << "Attempting to insert " << c1n << " items. " << endl;
  for (int i = 0; i < c1n; i++) {
    c1.insert_item(Stress_ball());
  }
  cout << "Items inserted: " << c1.total_items() << endl;
  /*   c1.insert_item(Stress_ball(Stress_ball_colors::green,
     Stress_ball_sizes::large));
     c1.insert_item(Stress_ball(Stress_ball_colors::blue,
     Stress_ball_sizes::large));
     c1.insert_item(Stress_ball(Stress_ball_colors::red,
     Stress_ball_sizes::medium));
     c1.insert_item(Stress_ball(Stress_ball_colors::blue,
     Stress_ball_sizes::small));
     c1.insert_item(Stress_ball(Stress_ball_colors::yellow,
     Stress_ball_sizes::small));
     c1.insert_item(Stress_ball(Stress_ball_colors::blue,
     Stress_ball_sizes::medium));
     c1.insert_item(Stress_ball(Stress_ball_colors::red,
     Stress_ball_sizes::large));
     c1.insert_item(Stress_ball(Stress_ball_colors::green,
     Stress_ball_sizes::small));
     c1.insert_item(Stress_ball(Stress_ball_colors::red,
     Stress_ball_sizes::small));
   */
  ASSERT_EQ(c1.total_items(), c1n);
}