#include <gtest/gtest.h>

auto solve_q1(int64_t x) {
  int64_t sum = 0;
  for (int i = 0; i <= x; i++) {
    sum += (i % 3 == 0 || i % 5 == 0) ? i : 0;
  }
  return sum;
}

// param1:test suite; param2: test name
TEST(q1_test, q1_boundchk) {
  EXPECT_EQ(solve_q1(0), 0);
}

TEST(q1_test, q1_basicchk) {
  EXPECT_EQ(solve_q1(3), 3);
  EXPECT_EQ(solve_q1(4), 3);
  EXPECT_EQ(solve_q1(5), 8);
}