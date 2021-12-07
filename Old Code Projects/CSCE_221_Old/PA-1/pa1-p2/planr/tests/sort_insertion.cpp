#include "gtest/gtest.h"
#include "Collection.h"
#include "Stress_ball.h"

#include "utils/test_functions.h"

using namespace std;

TEST(COLLECTION, SORT_INSERTION0) {
  // Insertion Sort
  {
    srand(time(0));
    int c1n = rand() % 10;
    if (c1n < 3) {
      c1n = 3;
    }
    Collection c;
    for (int i = 0; i < c1n; i++) {
      c.insert_item(Stress_ball());
    }
    /*  c.insert_item(Stress_ball(Stress_ball_colors::red,Stress_ball_sizes::medium));
      c.insert_item(Stress_ball(Stress_ball_colors::green,Stress_ball_sizes::small));
      c.insert_item(Stress_ball(Stress_ball_colors::blue,Stress_ball_sizes::large));
      c.insert_item(Stress_ball(Stress_ball_colors::yellow,Stress_ball_sizes::medium));
      c.insert_item(Stress_ball(Stress_ball_colors::red,Stress_ball_sizes::small));

      */
    cout << "\nBefore sorting:\n" << c;
    sort_by_size(c, Sort_choice::insertion_sort);
    cout << "\nAfter sorting:\n" << c;
    if (assert_sorted(c)) {
      ASSERT_TRUE(true);
    } else {
      cout << "Not sorted! Average case (random order) fails. Check in your "
              "compiler."
           << endl;
      ASSERT_TRUE(false);
    }
  }
}

TEST(COLLECTION, SORT_INSERTION1) {
  // Insertion Sort
  {
    Collection c1;
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
    sort_by_size(c1, Sort_choice::insertion_sort);
    if (assert_sorted(c1)) {
      ASSERT_TRUE(true);
    } else {
      cout << "Not sorted! Best case (sorting an already sorted array) fails. "
              "Check in your compiler."
           << endl;
      ASSERT_TRUE(false);
    }
  }
}

TEST(COLLECTION, SORT_INSERTION2) {
  // Insertion Sort
  {
    Collection c2;
    c2.insert_item(
        Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
    c2.insert_item(
        Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::large));
    c2.insert_item(
        Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
    c2.insert_item(
        Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
    c2.insert_item(
        Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
    sort_by_size(c2, Sort_choice::insertion_sort);
    if (assert_sorted(c2)) {
      ASSERT_TRUE(true);
    } else {
      cout << "Not sorted! Worst case (Sorting array which is sorted in "
              "descending order) fails. Check in your compiler."
           << endl;
      ASSERT_TRUE(false);
    }
  }
}