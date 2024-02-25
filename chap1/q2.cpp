#include <chrono>
#include <cstdint>
#include <gtest/gtest.h>
#include <random>

int64_t solve_q2(int64_t a, int64_t b) {
  if (a == 0) return b;
  return solve_q2(b % a, a);
}

TEST(q2_test, basic_chk) {
  std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 0; i < 100; i++) {
    int64_t u = std::uniform_int_distribution<int64_t>(1, 500)(rng);
    int64_t v = std::uniform_int_distribution<int64_t>(501, 1000)(rng);

    EXPECT_EQ(solve_q2(u, v), std::__gcd(u, v));
  }
}