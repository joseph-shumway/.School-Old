#include "gtest/gtest.h"
#include "../../src/Stress_ball.h"

bool is_valid_size(Stress_ball *sb) {
  auto color = sb->get_color();

  return (
      color == Stress_ball_colors::red ||
      color == Stress_ball_colors::blue ||
      color == Stress_ball_colors::green ||
      color == Stress_ball_colors::yellow
  );
}

TEST(SB, GET_COLOR) {
  {
    Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);

    EXPECT_EQ(sb.get_color(), Stress_ball_colors::red);
  }

  {
    Stress_ball sb = Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium);
  
    EXPECT_EQ(sb.get_color(), Stress_ball_colors::blue);
  }

  {
    Stress_ball * sb = new Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::large);
  
    EXPECT_EQ(sb->get_color(), Stress_ball_colors::green);
    
    delete sb;
  }

  {
    Stress_ball sb;

    EXPECT_TRUE(is_valid_size(&sb));
  }
}
