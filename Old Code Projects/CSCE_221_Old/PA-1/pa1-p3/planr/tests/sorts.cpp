#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"
#include "test_functions.h"

using namespace std;

TEST(COLLECTION, SORTS)
{
    {
        Collection<Jeans, Jeans_colors, Jeans_sizes> c;
        c.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::medium));
        c.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        c.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::large));
        c.insert_item(Jeans(Jeans_colors::white, Jeans_sizes::medium));
        c.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::small));
        cout << "Bubble sort on Jeans collection Average case" << endl;
        sort_by_size(c, Sort_choice::bubble_sort);
        if (assert_sorted(c))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Jeans Collection Average case sorting failed" << endl;
            ASSERT_TRUE(false);
        }

        Collection<Jeans, Jeans_colors, Jeans_sizes> c2;
        c2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        c2.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::large));
        c2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
        c2.insert_item(Jeans(Jeans_colors::white, Jeans_sizes::medium));
        c2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::small));
        cout << "Bubble sort on Jeans collection Worst case" << endl;
        sort_by_size(c2, Sort_choice::bubble_sort);
        if (assert_sorted(c2))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Jeans Collection Worst case sorting failed" << endl;
            ASSERT_TRUE(false);
        }
    }
    {
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c;
        c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
        c.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        c.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large));
        c.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
        c.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
        c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
        cout << "Bubble sort on Stress_ball collection Average case" << endl;
        sort_by_size(c, Sort_choice::bubble_sort);
        if (assert_sorted(c))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Stress_ball Collection Average case sorting failed" << endl;
            ASSERT_TRUE(false);
        }
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c1;
        c1.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
        c1.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        c1.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
        c1.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
        c1.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        cout << "Bubble sort on Stress_ball collection Best case" << endl;
        sort_by_size(c1, Sort_choice::bubble_sort);
        if (assert_sorted(c1))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Stress_ball Collection Best case sorting failed" << endl;
            ASSERT_TRUE(false);
        }
    }
    {
        Collection<Jeans, Jeans_colors, Jeans_sizes> c;
        c.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::medium));
        c.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        c.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::large));
        c.insert_item(Jeans(Jeans_colors::white, Jeans_sizes::medium));
        c.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::small));
        cout << "insertion sort on Jeans collection Average case" << endl;
        sort_by_size(c, Sort_choice::insertion_sort);
        if (assert_sorted(c))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Jeans Collection Average case sorting failed" << endl;
            ASSERT_TRUE(false);
        }

        Collection<Jeans, Jeans_colors, Jeans_sizes> c2;
        c2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        c2.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::large));
        c2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
        c2.insert_item(Jeans(Jeans_colors::white, Jeans_sizes::medium));
        c2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::small));
        cout << "insertion sort on Jeans collection Worst case" << endl;
        sort_by_size(c2, Sort_choice::insertion_sort);
        if (assert_sorted(c2))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Jeans Collection Worst case sorting failed" << endl;
            ASSERT_TRUE(false);
        }
    }
    {
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c;
        c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
        c.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        c.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large));
        c.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
        c.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
        c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
        cout << "insertion sort on Stress_ball collection Average case" << endl;
        sort_by_size(c, Sort_choice::insertion_sort);
        if (assert_sorted(c))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Stress_ball Collection Average case sorting failed" << endl;
            ASSERT_TRUE(false);
        }
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c1;
        c1.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
        c1.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        c1.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
        c1.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
        c1.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        cout << "insertion sort on Stress_ball collection Best case" << endl;
        sort_by_size(c1, Sort_choice::insertion_sort);
        if (assert_sorted(c1))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Stress_ball Collection Best case sorting failed" << endl;
            ASSERT_TRUE(false);
        }
    }
    {
        Collection<Jeans, Jeans_colors, Jeans_sizes> c;
        c.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::medium));
        c.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        c.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::large));
        c.insert_item(Jeans(Jeans_colors::white, Jeans_sizes::medium));
        c.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::small));
        cout << "selection sort on Jeans collection Average case" << endl;
        sort_by_size(c, Sort_choice::selection_sort);
        if (assert_sorted(c))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Jeans Collection Average case sorting failed" << endl;
            ASSERT_TRUE(false);
        }

        Collection<Jeans, Jeans_colors, Jeans_sizes> c2;
        c2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        c2.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::large));
        c2.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
        c2.insert_item(Jeans(Jeans_colors::white, Jeans_sizes::medium));
        c2.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::small));
        cout << "selection sort on Jeans collection Worst case" << endl;
        sort_by_size(c2, Sort_choice::selection_sort);
        if (assert_sorted(c2))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Jeans Collection Worst case sorting failed" << endl;
            ASSERT_TRUE(false);
        }
    }
    {
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c;
        c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
        c.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        c.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large));
        c.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
        c.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
        c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
        cout << "selection sort on Stress_ball collection Average case" << endl;
        sort_by_size(c, Sort_choice::selection_sort);
        if (assert_sorted(c))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Stress_ball Collection Average case sorting failed" << endl;
            ASSERT_TRUE(false);
        }
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c1;
        c1.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
        c1.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        c1.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
        c1.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
        c1.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        cout << "selection sort on Stress_ball collection Best case" << endl;
        sort_by_size(c1, Sort_choice::selection_sort);
        if (assert_sorted(c1))
        {
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Stress_ball Collection Best case sorting failed" << endl;
            ASSERT_TRUE(false);
        }
    }
}