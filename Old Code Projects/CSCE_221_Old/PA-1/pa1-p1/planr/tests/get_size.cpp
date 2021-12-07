#include "gtest/gtest.h"
#include "../../src/Stress_ball.h"

bool is_valid_size(Stress_ball *sb) {
  return (
      sb->get_size() == Stress_ball_sizes::large  ||
      sb->get_size() == Stress_ball_sizes::medium ||
      sb->get_size() == Stress_ball_sizes::small
  );
}

TEST(SB, GET_SIZE) {
  {
    Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);

    EXPECT_EQ(sb.get_size(), Stress_ball_sizes::small);
  }

  {
    Stress_ball sb = Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium);

    EXPECT_EQ(sb.get_size(), Stress_ball_sizes::medium);
  }
  
  {
    Stress_ball * sb = new Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::large);

    EXPECT_EQ(sb->get_size(), Stress_ball_sizes::large);

    delete sb;
  }

  {
    Stress_ball sb;

    EXPECT_TRUE(is_valid_size(&sb));
  }
}
