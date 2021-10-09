#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, CONSTRUCTORS)
{
    cout << "Create a collection for Stress_ball." << endl;
    Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c;
    cout << "Check if collection is created and empty." << endl;

    if (c.is_empty())
    {
        ASSERT_TRUE(c.is_empty());
        cout << "Passed." << endl;
    }
    else
    {
        cout << "Collection of Stress_balls not empty" << endl;
        ASSERT_TRUE(c.is_empty());
    }
    cout << "Create a collection for Jeans." << endl;
    Collection<Jeans, Jeans_colors, Jeans_sizes> c_j;
    //c_j.insert_item(Jeans());
    cout << "Check if collection is created and empty." << endl;
    if (c_j.is_empty())
    {
        ASSERT_TRUE(c_j.is_empty());
        cout << "Passed." << endl;
    }
    else
    {
        cout << "Collection of Jeans not empty" << endl;
        ASSERT_TRUE(c_j.is_empty());
    }

    cout << "Create a collection for Stress_ball with capacity as parameter." << endl;
    Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c11(10);
    cout << "Check if collection is created and empty." << endl;
    if (c11.is_empty())
    {
        ASSERT_TRUE(c11.is_empty());
        cout << "Passed." << endl;
    }
    else
    {
        cout << "Collection of Stress_balls not empty" << endl;
        ASSERT_TRUE(c11.is_empty());
    }
    cout << "Create a collection for Jeans with capacity as parameter." << endl;
    Collection<Jeans, Jeans_colors, Jeans_sizes> c12(10);
    cout << "Check if collection is created and empty." << endl;
    if (c12.is_empty())
    {
        ASSERT_TRUE(c12.is_empty());
        cout << "Passed." << endl;
    }
    else
    {
        cout << "Collection of Stress_balls not empty" << endl;
        ASSERT_TRUE(c12.is_empty());
    }
}