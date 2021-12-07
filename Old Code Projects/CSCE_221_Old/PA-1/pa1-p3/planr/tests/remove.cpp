#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"

using namespace std;

#define LOG_LINE (cout << "LINE_COUNTER Reached Line: " << __LINE__ << endl);


TEST(COLLECTION, REMOVE)
{
    {
        Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);
        Stress_ball not_sb(Stress_ball_colors::green, Stress_ball_sizes::large);
        cout << "Create a collection for Stress_ball" << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c;
        cout << "Inserting 7 Stress_ball" << endl;
        c.insert_item(not_sb);
        c.insert_item(not_sb);
        c.insert_item(not_sb);
        c.insert_item(sb);
        c.insert_item(not_sb);
        c.insert_item(not_sb);
        c.insert_item(not_sb);
        cout << "Number of successfully inserted Stress_ball: " << c.total_items() << endl;
        cout << "Emptying collection" << endl;
        c.make_empty();
        try
        {
            cout << "Removing an item" << endl;
            c.remove_this_item(sb);
        }
        catch (...)
        {
            cout << "throw() caught!" << endl;
        }
        //ASSERT_TRUE(check);
        cout << "Inserting two Stress_balls" << endl;
        c.insert_item(sb);
        c.insert_item(not_sb);
        cout << "Number of successfully inserted Stress_ball: " << c.total_items() << endl;
        cout << "Removing an item" << endl;
        c.remove_this_item(sb);
        cout << "Number of Stress_balls after removal: " << c.total_items() << endl;
        ASSERT_EQ(c.total_items(), 1);
    }

    LOG_LINE;

    {
        cout << "Create a collection for Jeans" << endl;
        Jeans jn(Jeans_colors::black, Jeans_sizes::small);
        Jeans not_jn(Jeans_colors::blue, Jeans_sizes::large);

        Collection<Jeans, Jeans_colors, Jeans_sizes> c1;
        cout << "Inserting 7 Jeans" << endl;
        c1.insert_item(not_jn);
        c1.insert_item(not_jn);
        c1.insert_item(not_jn);
        c1.insert_item(jn);
        c1.insert_item(not_jn);
        c1.insert_item(not_jn);
        c1.insert_item(not_jn);
        cout << "Number of successfully inserted Jeans: " << c1.total_items() << endl;
        cout << "Emptying collection" << endl;
        c1.make_empty();
        try
        {
            cout << "Removing an item" << endl;
            c1.remove_this_item(jn);
        }
        catch (...)
        {
            cout << "throw() caught!" << endl;
        }
        //ASSERT_TRUE(check);
        cout << "Inserting two Jeans" << endl;
        c1.insert_item(jn);
        c1.insert_item(not_jn);
        cout << "Number of successfully inserted Jeans: " << c1.total_items() << endl;
        cout << "Removing an item" << endl;
        c1.remove_this_item(jn);
        cout << "Number of Jeans after removal: " << c1.total_items() << endl;
        ASSERT_EQ(c1.total_items(), 1);
    }

    LOG_LINE;
    
    {
        Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);
        Stress_ball not_sb(Stress_ball_colors::green, Stress_ball_sizes::large);

        cout << "Create a collection for Stress_ball" << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c;
        cout << "Inserting 7 Stress_ball" << endl;
        c.insert_item(not_sb);
        c.insert_item(not_sb);
        c.insert_item(not_sb);
        c.insert_item(sb);
        c.insert_item(not_sb);
        c.insert_item(not_sb);
        c.insert_item(not_sb);
        cout << "Number of Stress_ball inserted successfully: " << c.total_items() << endl;
        cout << "Removing the same Stress_ball twice" << endl;
        c.remove_this_item(sb);
        cout << "Number of Stress_ball after removal: " << c.total_items() << endl;
        cout << "Expected number of Stress_ball after removal: " << 6 << endl;
        ASSERT_EQ(c.total_items(), 6);
    }
    
    LOG_LINE;
    
    {
        Jeans jn(Jeans_colors::black, Jeans_sizes::small);
        Jeans not_jn(Jeans_colors::blue, Jeans_sizes::large);
        cout << "Create a collection for Jeans" << endl;
        Collection<Jeans, Jeans_colors, Jeans_sizes> c1;
        cout << "Inserting 7 Jeans" << endl;

        c1.insert_item(not_jn);
        c1.insert_item(not_jn);
        c1.insert_item(not_jn);
        c1.insert_item(jn);
        c1.insert_item(not_jn);
        c1.insert_item(not_jn);
        c1.insert_item(not_jn);
        cout << "Number of Jeans inserted successfully: " << c1.total_items() << endl;
        cout << "Removing the same Jeans twice" << endl;
        c1.remove_this_item(jn);
        cout << "Number of Jeans after removal: " << c1.total_items() << endl;
        cout << "Expected number of Jeans after removal: " << 6 << endl;
        ASSERT_EQ(c1.total_items(), 6);
    }

    LOG_LINE;
    
    {
        {
            Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);
            Stress_ball not_sb(Stress_ball_colors::green, Stress_ball_sizes::large);
            cout << "Create a collection for Stress_ball" << endl;
            Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c;
            try
            {
                cout << "Removing an item" << endl;
                c.remove_this_item(sb);
            }
            catch (...)
            {
                cout << "throw() caught!" << endl;
            }
            cout << "Checking if collection is empty()" << endl;
            if (c.total_items() == 0)
            {
                cout << "Pass" << endl;
                ASSERT_TRUE(true);
            }
            else
            {
                cout << "Failed" << endl;
                ASSERT_TRUE(false);
            }
        }

        Jeans jn(Jeans_colors::black, Jeans_sizes::small);
        Jeans not_jn(Jeans_colors::blue, Jeans_sizes::large);
        cout << "Create a collection for Jeans" << endl;

        Collection<Jeans, Jeans_colors, Jeans_sizes> c1;

        try
        {
            cout << "Removing an item" << endl;
            c1.remove_this_item(jn);
        }
        catch (...)
        {
            cout << "throw() caught!" << endl;
        }
        cout << "Checking if collection is empty()" << endl;
        if (c1.total_items() == 0)
        {
            cout << "Pass" << endl;
            ASSERT_TRUE(true);
        }
        else
        {
            cout << "Failed" << endl;
            ASSERT_TRUE(false);
        }
    }

    LOG_LINE;
    
    {
        Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);
        Stress_ball not_sb(Stress_ball_colors::green, Stress_ball_sizes::large);
        cout << "Create a collection for Stress_ball" << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c(10);
        cout << "Inserting 4 Stress_ball" << endl;
        c.insert_item(Stress_ball());
        c.insert_item(Stress_ball());
        c.insert_item(Stress_ball());
        c.insert_item(Stress_ball());
        cout << "Number of successfully inserted Stress_ball: " << c.total_items() << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> copy(c);
        cout << "Remove any item" << endl;
        c.remove_any_item();
        cout << "Number of Stress_balls after removal: " << c.total_items() << endl;
        ASSERT_EQ(c.total_items(), 3);
    }

    LOG_LINE;
    
    {
        cout << "Create a collection for Jeans" << endl;
        Collection<Jeans, Jeans_colors, Jeans_sizes> c(10);
        cout << "Inserting 4 Jeans" << endl;
        c.insert_item(Jeans());
        c.insert_item(Jeans());
        c.insert_item(Jeans());
        c.insert_item(Jeans());
        cout << "Number of Jeans inserted successfully: " << c.total_items() << endl;
        Collection<Jeans, Jeans_colors, Jeans_sizes> copy(c);
        cout << "Removing an item" << endl;
        c.remove_any_item();
        cout << "Number of Jeans after removal: " << c.total_items() << endl;
        if (c.total_items() == 3)
        {
            ASSERT_TRUE(true);
        }
        else
        {
            ASSERT_TRUE(false);
        }
    }
}
