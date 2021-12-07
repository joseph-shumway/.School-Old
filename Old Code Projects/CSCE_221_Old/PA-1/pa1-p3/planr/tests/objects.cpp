#include "gtest/gtest.h"
#include "Collection.h"
#include "Jeans.h"
#include "Stress_ball.h"
#include <sstream>

using namespace std;

TEST(COLLECTION, OBJECTS)
{
    {
        Stress_ball rs(Stress_ball_colors::red, Stress_ball_sizes::small);
        Stress_ball rs1(Stress_ball_colors::red, Stress_ball_sizes::small);

        Stress_ball *bs = new Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::small);

        Stress_ball bl = Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large);
        Stress_ball bl1 = Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::large);

        EXPECT_TRUE(rs == rs1) << "Two (red, small) stressballs are equal";
        EXPECT_TRUE(bl == bl1) << "Two (blue, large) stressballs are equal";
        EXPECT_FALSE(rs == *bs) << "A (red, small) stressball differs from a (blue, small)";
        EXPECT_FALSE(*bs == rs) << "A (blue, small) != (red, small)";
        EXPECT_FALSE(*bs == bl) << "A (blue, small) stressball is not equal to a (blue, large) stressball";

        delete bs;
    }

    {
        Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);

        EXPECT_EQ(sb.get_color(), Stress_ball_colors::red);
    }

    {
        Stress_ball sb = Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium);

        EXPECT_EQ(sb.get_color(), Stress_ball_colors::blue);
    }

    {
        Stress_ball *sb = new Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::large);

        EXPECT_EQ(sb->get_color(), Stress_ball_colors::green);

        delete sb;
    }

    {
        Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);

        EXPECT_EQ(sb.get_size(), Stress_ball_sizes::small);
    }

    {
        Stress_ball sb = Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium);

        EXPECT_EQ(sb.get_size(), Stress_ball_sizes::medium);
    }

    {
        Stress_ball *sb = new Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::large);

        EXPECT_EQ(sb->get_size(), Stress_ball_sizes::large);

        delete sb;
    }

    {
        Jeans rs(Jeans_colors::white, Jeans_sizes::small);
        Jeans rs1(Jeans_colors::white, Jeans_sizes::small);

        Jeans *bs = new Jeans(Jeans_colors::blue, Jeans_sizes::small);

        Jeans bl = Jeans(Jeans_colors::blue, Jeans_sizes::large);
        Jeans bl1 = Jeans(Jeans_colors::blue, Jeans_sizes::large);

        EXPECT_TRUE(rs == rs1) << "Two (white, small) jeans are equal";
        EXPECT_TRUE(bl == bl1) << "Two (blue, large) jeans are equal";
        EXPECT_FALSE(rs == *bs) << "A (white, small) jeans differs from a (blue, small)";
        EXPECT_FALSE(*bs == rs) << "A (blue, small) != (white, small)";
        EXPECT_FALSE(*bs == bl) << "A (blue, small) stressball is not equal to a (blue, large) stressball";

        delete bs;
    }

    {
        Jeans sb(Jeans_colors::grey, Jeans_sizes::small);

        EXPECT_EQ(sb.get_color(), Jeans_colors::grey);
    }

    {
        Jeans sb = Jeans(Jeans_colors::blue, Jeans_sizes::medium);

        EXPECT_EQ(sb.get_color(), Jeans_colors::blue);
    }

    {
        Jeans *sb = new Jeans(Jeans_colors::black, Jeans_sizes::large);

        EXPECT_EQ(sb->get_color(), Jeans_colors::black);

        delete sb;
    }

    {
        Jeans sb(Jeans_colors::white, Jeans_sizes::small);

        EXPECT_EQ(sb.get_size(), Jeans_sizes::small);
    }

    {
        Jeans sb = Jeans(Jeans_colors::blue, Jeans_sizes::medium);

        EXPECT_EQ(sb.get_size(), Jeans_sizes::medium);
    }

    {
        Jeans *sb = new Jeans(Jeans_colors::white, Jeans_sizes::large);

        EXPECT_EQ(sb->get_size(), Jeans_sizes::large);

        delete sb;
    }

    {
        std::stringstream ss;
        const char *const c = "red small\nblue large\ngreen medium\nwhite medium\ngrey medium\nblack small";

        ss << c;

        Stress_ball sb;
        ss >> sb;
        if (!ss)
        {
            std::cout << "You somehow corrupted the stream?\nAre your reading more than one in operator>>(is, stressball)?";
            ASSERT_TRUE(false);
        }
        ASSERT_TRUE(sb.get_color() == Stress_ball_colors::red);
        ASSERT_TRUE(sb.get_size() == Stress_ball_sizes::small);
        ss >> sb;
        ASSERT_TRUE(sb.get_color() == Stress_ball_colors::blue);
        ASSERT_TRUE(sb.get_size() == Stress_ball_sizes::large);
        ss >> sb;
        ASSERT_TRUE(sb.get_color() == Stress_ball_colors::green);
        ASSERT_TRUE(sb.get_size() == Stress_ball_sizes::medium);

        Jeans j;
        ss >> j;
        if (!ss)
        {
            std::cout << "You somehow corrupted the stream?\nAre your reading more than one in operator>>(is, jeans)?";
            ASSERT_TRUE(false);
        }
        ASSERT_TRUE(j.get_color() == Jeans_colors::white);
        ASSERT_TRUE(j.get_size() == Jeans_sizes::medium);
        ss >> j;
        ASSERT_TRUE(j.get_color() == Jeans_colors::grey);
        ASSERT_TRUE(j.get_size() == Jeans_sizes::medium);
        ss >> j;
        ASSERT_TRUE(j.get_color() == Jeans_colors::black);
        ASSERT_TRUE(j.get_size() == Jeans_sizes::small);
    }
}