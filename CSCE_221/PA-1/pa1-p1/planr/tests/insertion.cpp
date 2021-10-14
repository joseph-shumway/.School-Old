#include "gtest/gtest.h"
#include <string>
#include "../../src/Stress_ball.h"
#include "util/testutils.h"

void serialization_eq(Stress_ball & sb, std::string serialized) {
  std::stringstream ss;
  ss << sb;

  auto stripped = copy_remove_all(ss.str(), " ");

  EXPECT_NE(stripped[stripped.size() - 1], '\n') 
    << "Output should not end with a new line";

  EXPECT_STREQ(stripped.c_str(), serialized.c_str());
}

TEST(SB, OPERATOR_INSERTION) {
  {
    Stress_ball sb(Stress_ball_colors::red, Stress_ball_sizes::small);

    serialization_eq(sb, "(red,small)");
  }

  {
    Stress_ball sb = Stress_ball(Stress_ball_colors::blue, Stress_ball_sizes::medium);

    serialization_eq(sb, "(blue,medium)");
  }

  {
    Stress_ball *sb = new Stress_ball(Stress_ball_colors::green, Stress_ball_sizes::large);

    serialization_eq(*sb, "(green,large)");
  }
}
