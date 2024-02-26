#include <chrono>
#include <cstdint>
#include <gtest/gtest.h>
#include <numeric>
#include <random>

int64_t solve_q3(int64_t a, int64_t b) {
  if (!a || !b) {
    return 0;
  }
  int64_t start = std::max(a, b), end = a * b;
  for (auto i = start; i <= end; i++) {
    if (i % a == 0 && i % b == 0) {
      return i;
    }
  }
  return end;
}

TEST(q3_test, temp_test) {
  std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 0; i < 100; i++) {
    auto u = std::uniform_int_distribution<int64_t>(1, 500)(rng);
    auto v = std::uniform_int_distribution<int64_t>(501, 1000)(rng);
    EXPECT_EQ(solve_q3(u, v), std::lcm(u, v));
  }
}