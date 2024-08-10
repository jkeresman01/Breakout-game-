#include <gtest/gtest.h>

#include <SFML/System/Vector2.hpp>

#include "../src/headers/Ball.h"
#include "../src/headers/GameConstants.h"

using namespace breakout;

class BallTest : public ::testing::Test
{
  protected:
    Ball ball;
};

TEST_F(BallTest, afterBallIsCreatedWillItsRadiusBe10)
{
    EXPECT_EQ(ball.getRadius(), 10.0f);
}

TEST_F(BallTest, afterBallIsCreatedWillItsPostionBeInTheMiddleOfTheScreen)
{
    EXPECT_EQ(ball.getPosition().x, screen::WIDTH / 2 - ball.getRadius());
    EXPECT_EQ(ball.getPosition().y, screen::HEIGHT / 2 - ball.getRadius());
}

TEST_F(BallTest, afterBallIsCreatedWillItsVelocityBeZero)
{
    EXPECT_EQ(ball.getVelocity().x, 0.0f);
    EXPECT_EQ(ball.getVelocity().y, 0.0f);
}

TEST_F(BallTest, afterBallStartIsInvoked_WillBallStartMovingDown)
{
    ball.start();

    EXPECT_EQ(ball.getVelocity().x, 0);
    EXPECT_EQ(ball.getVelocity().y, ball::VELOCITY_Y_COMPONENT);
}
