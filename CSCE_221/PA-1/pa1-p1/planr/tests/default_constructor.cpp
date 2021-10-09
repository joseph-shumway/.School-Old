#include "gtest/gtest.h"
#include "../../src/Stress_ball.h"

TEST(SB, DEFAULT_CONSTRUCTOR) {
  Stress_ball sb;
  Stress_ball sb1 = Stress_ball();
  Stress_ball sb2;
  Stress_ball *sb3 = new Stress_ball();

  // Test compilation & linking
  ASSERT_TRUE(true);
}
