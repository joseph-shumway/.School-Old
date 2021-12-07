#include "gtest/gtest.h"
#include "../../src/Stress_ball.h"

TEST(SB, PARAMETRIZED_CONSTRUCTOR) {
  Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);
  Stress_ball sb1 = Stress_ball(Stress_ball_colors::yellow, Stress_ball_sizes::small);
  Stress_ball sb2(Stress_ball_colors::green, Stress_ball_sizes::medium);
  Stress_ball *sb3 = new Stress_ball(Stress_ball_colors::red, Stress_ball_sizes::large);

  // Test compilation & linking
  ASSERT_TRUE(true);
}
