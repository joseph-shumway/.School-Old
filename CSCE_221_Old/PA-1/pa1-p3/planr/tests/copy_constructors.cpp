#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, COPY_CONSTRUCTORS)
{
    {
        cout << "Create a collection for Stress_ball." << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c1(20);
        cout << "Inserting 7 Stress_balls." << endl;
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        cout << "Number of Stress_balls successfully inserted: " << c1.total_items() << endl;
        Stress_ball *arr1 = &(c1[0]);
        {
            cout << "Using copy constructor" << endl;
            Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c2(c1);
            cout << "Performing memory location test." << endl;
            if (arr1 == &(c2[0]))
            {
                cout << "Fail: What happens with memory locations of objects when a copy constructor is used. Are they same or different?" << endl;
                ASSERT_FALSE(arr1 == &(c2[0]));
            }
            else
            {
                cout << "Passed: Memory location test!" << endl;
                ASSERT_FALSE(arr1 == &(c2[0]));
            }
            cout << "Checking if copied and original Collection have the same number of Stress_balls." << endl;
            if (c1.total_items() == c2.total_items())
            {
                cout << "Passed: Copied and original Collection have the same number of Stress_balls" << endl;
                ASSERT_TRUE(true);
            }
            else
            {
                cout << "Fail: Copied object and Original object do not have same number of items." << endl;
                ASSERT_TRUE(false);
            }
        }
        {
            cout << "Create a collection for Jeans." << endl;
            Collection<Jeans, Jeans_colors, Jeans_sizes> c5(20);
            cout << "Inserting 7 Jeans." << endl;
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            cout << "Number of Jeans successfully inserted: " << c5.total_items() << endl;
            cout << "Using copy constructor" << endl;
            Jeans *arr5 = &(c5[0]);
            {
                Collection<Jeans, Jeans_colors, Jeans_sizes> c6(c5);
                cout << "Performing memory location test." << endl;
                if (arr5 == &(c6[0]))
                {
                    cout << "Fail: What happens with memory locations of objects when a copy constructor is used. Are they same or different?" << endl;
                    ASSERT_FALSE(arr5 == &(c6[0]));
                }
                else
                {
                    cout << "Passed: Memory location test!" << endl;
                    ASSERT_FALSE(arr5 == &(c6[0]));
                }
                cout << "Checking if copied and original Collection have the same number of Stress_balls." << endl;
                if (c5.total_items() == c6.total_items())
                {
                    cout << "Passed: Copied and original Collection have the same number of Stress_balls" << endl;
                    ASSERT_TRUE(true);
                }
                else
                {
                    cout << "Fail: Copied object and Original object do not have same number of items." << endl;
                    ASSERT_TRUE(false);
                }
            }
        }
    }

    {
        cout << "Create a collection for Stress_ball." << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c1(20);
        cout << "Inserting 7 Stress_balls." << endl;
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        c1.insert_item(Stress_ball());
        cout << "Number of Stress_balls successfully inserted: " << c1.total_items() << endl;
        Stress_ball *arr1 = &(c1[0]);
        {
            cout << "Using copy constructor" << endl;
            Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c2(c1);
            cout << "Performing memory location test." << endl;
            if (arr1 == &(c2[0]))
            {
                cout << "Fail: What happens with memory locations of objects when a copy constructor is used. Are they same or different?" << endl;
                ASSERT_FALSE(arr1 == &(c2[0]));
            }
            else
            {
                cout << "Passed: Memory location test!" << endl;
                ASSERT_FALSE(arr1 == &(c2[0]));
            }
        }
        {
            cout << "Create a collection for Jeans." << endl;
            Collection<Jeans, Jeans_colors, Jeans_sizes> c5(20);
            cout << "Inserting 7 Jeans." << endl;
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            c5.insert_item(Jeans());
            cout << "Number of Jeans successfully inserted: " << c5.total_items() << endl;
            cout << "Using copy constructor" << endl;
            Jeans *arr5 = &(c5[0]);
            {
                Collection<Jeans, Jeans_colors, Jeans_sizes> c6(c5);
                cout << "Performing memory location test." << endl;
                if (arr5 == &(c6[0]))
                {
                    cout << "Fail: What happens with memory locations of objects when a copy constructor is used. Are they same or different?" << endl;
                    ASSERT_FALSE(arr5 == &(c6[0]));
                }
                else
                {
                    cout << "Passed: Memory location test!" << endl;
                    ASSERT_FALSE(arr5 == &(c6[0]));
                }
            }
        }
    }
}