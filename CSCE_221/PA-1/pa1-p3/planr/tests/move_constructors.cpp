#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, MOVE_CONSTRUCTORS)
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
            cout << "Using move constructor" << endl;
            Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c2(move(c1));
            cout << "Performing memory location test." << endl;
            if (arr1 == &(c2[0]))
            {
                cout << "Passed: Memory location test!" << endl;
                ASSERT_TRUE(true);
            }
            else
            {
                cout << "Fail: What happens with memory locations of objects when a move constructor is used. Are they same or different?" << endl;
                ASSERT_TRUE(false);
            }
            cout << "Checking if moved object is empty or not." << endl;
            if (c1.is_empty())
            {
                cout << "Passed: It is empty" << endl;
                ASSERT_TRUE(true);
            }
            else
            {
                cout << "Fail: Should the object that is passed to the constructor be empty after constructor's operation is completed?" << endl;
                ASSERT_TRUE(false);
            }
        }

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

        Jeans *arr5 = &(c5[0]);
        {
            cout << "Using move constructor" << endl;
            Collection<Jeans, Jeans_colors, Jeans_sizes> c6(move(c5));
            cout << "Performing memory location test." << endl;
            if (arr5 == &(c6[0]))
            {
                cout << "Passed: Memory location test!" << endl;
                ASSERT_TRUE(true);
            }
            else
            {
                cout << "Fail: What happens with memory locations of objects when a move constructor is used. Are they same or different?" << endl;
                ASSERT_TRUE(false);
            }
            cout << "Checking if moved object is empty or not." << endl;
            if (c5.is_empty())
            {
                cout << "Passed: It is empty" << endl;
                ASSERT_TRUE(true);
            }
            else
            {
                cout << "Fail: Should the object that is passed to the constructor be empty after constructor's operation is completed?" << endl;
                ASSERT_TRUE(false);
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
            cout << "Using move constructor" << endl;
            Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c2 = move(c1);
            cout << "Performing memory location test." << endl;
            if (arr1 == &(c2[0]))
            {
                cout << "Passed: Memory location test!" << endl;
                ASSERT_TRUE(true);
            }
            else
            {
                cout << "Fail: What happens with memory locations of objects when a move constructor is used. Are they same or different?" << endl;
                ASSERT_TRUE(false);
            }
        }

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

        Jeans *arr5 = &(c5[0]);
        {
            cout << "Using move constructor" << endl;
            Collection<Jeans, Jeans_colors, Jeans_sizes> c6 = move(c5);
            cout << "Performing memory location test." << endl;
            if (arr5 == &(c6[0]))
            {
                cout << "Passed: Memory location test!" << endl;
                ASSERT_TRUE(true);
            }
            else
            {
                cout << "Fail: What happens with memory locations of objects when a move constructor is used. Are they same or different?" << endl;
                ASSERT_TRUE(false);
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
        {
            cout << "Using move constructor" << endl;
            Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c2(move(c1));

            cout << "Checking if moved object is empty or not." << endl;
            if (c1.is_empty())
            {
                cout << "Passed: It is empty" << endl;
                ASSERT_TRUE(true);
            }
            else
            {
                cout << "Fail: Should the object that is passed to the constructor be empty after constructor's operation is completed?" << endl;
                ASSERT_TRUE(false);
            }
        }

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

        {
            cout << "Using move constructor" << endl;
            Collection<Jeans, Jeans_colors, Jeans_sizes> c6(move(c5));

            cout << "Checking if moved object is empty or not." << endl;
            if (c5.is_empty())
            {
                cout << "Passed: It is empty" << endl;
                ASSERT_TRUE(true);
            }
            else
            {
                cout << "Fail: Should the object that is passed to the constructor be empty after constructor's operation is completed?" << endl;
                ASSERT_TRUE(false);
            }
        }
    }
}
