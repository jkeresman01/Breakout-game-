#include <gtest/gtest.h>

#include "../src/headers/GameConstants.h"
#include "../src/headers/Paddle.h"

using namespace breakout;

class PaddleTest : public ::testing::Test
{
  protected:
    Paddle paddle;
};

TEST_F(PaddleTest, AfterPaddleIsCreated_WillHeightBe20)
{
    EXPECT_EQ(paddle.getHeight(), paddle::HEIGHT);
}

TEST_F(PaddleTest, AfterPaddleIsCreated_WillWidthBe80)
{
    EXPECT_EQ(paddle.getWidth(), paddle::WIDTH);
}

TEST_F(PaddleTest, AfterHeightIsSetTo100_WillHeightBe100)
{
    paddle.setHeight(100.0f);
    EXPECT_EQ(paddle.getHeight(), 100.0f);
}
