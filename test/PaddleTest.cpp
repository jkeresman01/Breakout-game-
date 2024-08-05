#include <gtest/gtest.h>

#include "../src/headers/GameConstants.h"
#include "../src/headers/Paddle.h"

using namespace breakout;

class PaddleTest : public ::testing::Test
{
  protected:
    Paddle paddle;

    std::streambuf *originalCerrStreamBuf;
    std::ostringstream capturedCerrStream;

    void SetUp() override
    {
        originalCerrStreamBuf = std::cerr.rdbuf();
        std::cerr.rdbuf(capturedCerrStream.rdbuf());
    }

    void TearDown() override
    {
        std::cerr.rdbuf(originalCerrStreamBuf);
    }

    std::string getCapturedCerrOutput()
    {
        return capturedCerrStream.str();
    }
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

TEST_F(PaddleTest, AfterWitdthIsSetTo50WillWidthBe50)
{
    paddle.setWidth(50.0f);
    EXPECT_EQ(paddle.getWidth(), 50.0f);
}

TEST_F(PaddleTest, AfterWitdthIsSetYoNegativeNumber_WillErrorBeLogged)
{
    paddle.setWidth(-50.0f);
    std::string capturedCerrOutput = getCapturedCerrOutput();

    EXPECT_TRUE(capturedCerrOutput.find("Failed to set width, width can't be negative number!") !=
                std::string::npos);
}

TEST_F(PaddleTest, AfterHeightIsSetToNegativeNumber_WillErrorBeLogged)
{
    paddle.setHeight(-50.0f);
    std::string capturedCerrOutput = getCapturedCerrOutput();

    EXPECT_TRUE(capturedCerrOutput.find("Failed to set height, height can't be negative number!") !=
                std::string::npos);
}
