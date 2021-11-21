#include "gtest/gtest.h"
#include "../../src/Stress_ball.h"

TEST(SB, OPERATOR_EQUALITY) {
  Stress_ball rs (Stress_ball_colors::red, Stress_ball_sizes::small);
  Stress_ball rs1 (Stress_ball_colors::red, Stress_ball_sizes::small);
  
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
