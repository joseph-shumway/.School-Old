#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, UNION)
{
    {
        cout << "Create a collection for Stress_ball." << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c;
        cout << "Inserting 5 Stress_balls." << endl;
        c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
        c.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        c.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large));
        c.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
        c.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
        cout << "Number of Stress_balls successfully inserted: " << c.total_items() << endl;
        cout << "Create another collection for Stress_ball." << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c1;
        cout << "Inserting 5 Stress_balls." << endl;
        c1.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
        c1.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        c1.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
        c1.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::medium));
        c1.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        cout << "Number of Stress_balls successfully inserted: " << c1.total_items() << endl;
        cout << "Union the two collections and assign it to a third Stress_ball Collection." << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> c2 = make_union(c, c1);

        cout << "Number of Stress_balls successfully inserted: " << c2.total_items() << endl;
        cout << "Expected number of Stress_balls: " << 10 << endl;
        ASSERT_EQ(c2.total_items(), 10);
        cout << "Actual number of Stress_balls of color blue: " << c2.total_items(Stress_ball_colors::red) << endl;
        cout << "Expected number of Stress_balls of color blue: " << 4 << endl;
        ASSERT_EQ(c2.total_items(Stress_ball_colors::red), 4);
        cout << "Actual number of Stress_ball of small size: " << c2.total_items(Stress_ball_sizes::small) << endl;
        cout << "Expected number of Stress_ball of small size: " << 4 << endl;
        ASSERT_EQ(c2.total_items(Stress_ball_sizes::small), 4);
    }
    {
        cout << "Create a collection for Jeans." << endl;
        Collection<Jeans, Jeans_colors, Jeans_sizes> c;
        cout << "Inserting 5 Jeans." << endl;
        c.insert_item(Jeans(Jeans_colors::white, Jeans_sizes::medium));
        c.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        c.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::large));
        c.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::medium));
        c.insert_item(Jeans(Jeans_colors::white, Jeans_sizes::small));
        cout << "Number of Jeans successfully inserted: " << c.total_items() << endl;
        cout << "Create another collection for Jeans." << endl;
        Collection<Jeans, Jeans_colors, Jeans_sizes> c1;
        cout << "Inserting 5 Jeans." << endl;
        c1.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::small));
        c1.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        c1.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
        c1.insert_item(Jeans(Jeans_colors::white, Jeans_sizes::medium));
        c1.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        cout << "Number of Jeans successfully inserted: " << c1.total_items() << endl;
        cout << "Union the two collections and assign it to a third Stress_ball Collection." << endl;
        Collection<Jeans, Jeans_colors, Jeans_sizes> c2 = make_union(c, c1);

        cout << "Number of Jeans successfully inserted: " << c2.total_items() << endl;
        cout << "Expected number of Jeans: " << 10 << endl;
        ASSERT_EQ(c2.total_items(), 10);
        cout << "Actual number of Jeans of color blue: " << c2.total_items(Jeans_colors::grey) << endl;
        cout << "Expected number of Jeans of color blue: " << 2 << endl;
        ASSERT_EQ(c2.total_items(Jeans_colors::grey), 2);
        cout << "Actual number of Jeans of small size: " << c2.total_items(Jeans_sizes::small) << endl;
        cout << "Expected number of Jeans of small size: " << 4 << endl;
        ASSERT_EQ(c2.total_items(Jeans_sizes::small), 4);
    }
}