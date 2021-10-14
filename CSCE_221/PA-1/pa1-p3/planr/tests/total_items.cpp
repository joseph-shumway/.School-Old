#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"

using namespace std;

TEST(COLLECTION, TOTAL_ITEMS)
{

    {
        cout << "Create a collection for Stress_ball." << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> cir;
        cout << "Inserting 9 Stress_balls." << endl;
        cir.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::large));
        cir.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large));
        cir.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
        cir.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::small));
        cir.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::small));
        cir.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
        cir.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        cir.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        cir.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
        cout << "Number of Stress_balls successfully inserted: " << cir.total_items() << endl;
        cout << "Actual number of Stress_balls of color blue: " << cir.total_items(Stress_ball_colors::blue) << endl;
        cout << "Expected number of Stress_balls of color blue: " << 3 << endl;
        ASSERT_EQ(cir.total_items(Stress_ball_colors::blue), 3);
    }
    {
        cout << "Create a collection for Jeans." << endl;
        Collection<Jeans, Jeans_colors, Jeans_sizes> cirj;
        cout << "Inserting 9 Jeans." << endl;
        cirj.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        cirj.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::large));
        cirj.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::medium));
        cirj.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::small));
        cirj.insert_item(Jeans(Jeans_colors::white, Jeans_sizes::small));
        cirj.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
        cirj.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::large));
        cirj.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::small));
        cirj.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        cout << "Number of Jeans successfully inserted: " << cirj.total_items() << endl;
        cout << "Actual number of Jeans of color blue: " << cirj.total_items(Jeans_colors::blue) << endl;
        cout << "Expected number of Jeans of color blue: " << 3 << endl;
        ASSERT_EQ(cirj.total_items(Jeans_colors::blue), 3);
    }
    {
        cout << "Create a collection for Stress_ball." << endl;
        Collection<Stress_ball, Stress_ball_colors, Stress_ball_sizes> cir;
        cout << "Inserting 9 Stress_balls." << endl;
        cir.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::large));
        cir.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large));
        cir.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::medium));
        cir.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::small));
        cir.insert_item(Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::small));
        cir.insert_item(Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium));
        cir.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large));
        cir.insert_item(Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::small));
        cir.insert_item(Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::small));
        cout << "Number of Stress_balls successfully inserted: " << cir.total_items() << endl;
        cout << "Actual number of Stress_ball of small size: " << cir.total_items(Stress_ball_sizes::small) << endl;
        cout << "Expected number of Stress_ball of small size: " << 4 << endl;
        ASSERT_EQ(cir.total_items(Stress_ball_sizes::small), 4);
    }
    {
        cout << "Create a collection for Jeans." << endl;
        Collection<Jeans, Jeans_colors, Jeans_sizes> cirj;
        cout << "Inserting 9 Jeans." << endl;
        cirj.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::large));
        cirj.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::large));
        cirj.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::medium));
        cirj.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::small));
        cirj.insert_item(Jeans(Jeans_colors::white, Jeans_sizes::small));
        cirj.insert_item(Jeans(Jeans_colors::blue, Jeans_sizes::medium));
        cirj.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::large));
        cirj.insert_item(Jeans(Jeans_colors::grey, Jeans_sizes::small));
        cirj.insert_item(Jeans(Jeans_colors::black, Jeans_sizes::small));
        cout << "Number of Jeans successfully inserted: " << cirj.total_items() << endl;
        cout << "Actual number of Jeans of small size: " << cirj.total_items(Jeans_sizes::small) << endl;
        cout << "Expected number of Jeans of small size: " << 4 << endl;
        ASSERT_EQ(cirj.total_items(Jeans_sizes::small), 4);
    }
}