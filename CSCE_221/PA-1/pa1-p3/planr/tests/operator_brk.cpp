#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, OPERATOR_BRK)
{
    {
        cout << "Create a collection for Stress_ball." << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c;
        Stress_ball sb(Stress_ball_colors::green, Stress_ball_sizes::medium);
        cout << "Inserting 3 Stress_balls." << endl;
        c.insert_item(Stress_ball());
        c.insert_item(Stress_ball());
        c.insert_item(sb);
        cout << "Number of Stress_balls successfully inserted: " << c.total_items() << endl;
        cout << "Accessing the third Stress_ball" << endl;
        if (c[2].get_color() == sb.get_color() && c[2].get_size() == sb.get_size())
        {
            cout << "The color and size are correct." << endl;
            ASSERT_EQ(c[2].get_color(), sb.get_color());
            ASSERT_EQ(c[2].get_size(), sb.get_size());
        }
        else
        {
            cout << "color and size are not as expected" << endl;
            ASSERT_EQ(c[2].get_color(), sb.get_color());
            ASSERT_EQ(c[2].get_size(), sb.get_size());
        }
    }
    {
        cout << "Create a collection for Stress_ball." << endl;
        Collection<Jeans, Jeans_colors, Jeans_sizes> c;
        Jeans jn(Jeans_colors::white, Jeans_sizes::xlarge);
        cout << "Inserting 3 Jeans." << endl;
        c.insert_item(Jeans());
        c.insert_item(Jeans());
        c.insert_item(jn);
        cout << "Number of Jeans successfully inserted: " << c.total_items() << endl;
        cout << "Accessing the third Jeans" << endl;
        if (c[2].get_color() == jn.get_color() && c[2].get_size() == jn.get_size())
        {
            cout << "The color and size are correct." << endl;
            ASSERT_EQ(c[2].get_color(), jn.get_color());
            ASSERT_EQ(c[2].get_size(), jn.get_size());
        }
        else
        {
            cout << "color and size are not as expected" << endl;
            ASSERT_EQ(c[2].get_color(), jn.get_color());
            ASSERT_EQ(c[2].get_size(), jn.get_size());
        }
    }
}