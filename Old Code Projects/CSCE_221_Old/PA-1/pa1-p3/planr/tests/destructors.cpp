#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, DESTRUCTORS)
{
    {
        cout << "Create a collection for Stress_ball." << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> cd_dest(3);
        cout << "Inserting 1 Stress_ball" << endl;
        cd_dest.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
        cout << "Number of Stress_balls inserted successfully: " << cd_dest.total_items() << endl;
        cout << "Calling destructor on Stress_ball Collection" << endl;
        cd_dest.~Collection();
        cout << "Destructor executed" << endl;
        cout << "Checking if the Stress_ball Collection is empty" << endl;
        if (cd_dest.is_empty())
        {
            ASSERT_TRUE(cd_dest.is_empty());
            cout << "Passed." << endl;
        }
        else
        {
            cout << "Collection of Stress_balls not empty" << endl;
            ASSERT_TRUE(cd_dest.is_empty());
        }
    }
    {
        cout << "Create a collection for Jeans." << endl;
        Collection<Jeans, Jeans_colors, Jeans_sizes> cd(3);
        cout << "Inserting 1 Jeans" << endl;
        cd.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
        cout << "Number of Jeans inserted successfully: " << cd.total_items() << endl;
        cout << "Calling destructor on Jeans Collection" << endl;
        cd.~Collection();
        cout << "Destructor executed" << endl;
        cout << "Checking if the Jeans Collection is empty" << endl;
        if (cd.is_empty())
        {
            ASSERT_TRUE(cd.is_empty());
            cout << "Passed." << endl;
        }
        else
        {
            cout << "Collection of Jeans not empty" << endl;
            ASSERT_TRUE(cd.is_empty());
        }
    }
}