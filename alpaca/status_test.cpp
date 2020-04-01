#include <thread>

#include "gtest/gtest.h"

#include "alpaca/status.h"

class StatusTest : public ::testing::Test {};

TEST_F(StatusTest, testStatusConstructor) {
  auto defaultStatus = alpaca::Status();
  EXPECT_EQ(defaultStatus.getMessage(), "OK");
  EXPECT_EQ(defaultStatus.getCode(), 0);
}
