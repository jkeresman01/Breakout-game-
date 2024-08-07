#include <gtest/gtest.h>

#include <iostream>

#include "../src/headers/Logger.h"

class LoggerTest : public ::testing::Test
{
  protected:
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

TEST_F(LoggerTest, AfterLOG_DEBUGisInvoked_WillLogInformationContatinDebugSeverity)
{
    LOG_DEBUG("test logging | severity debug");
    std::string logDebugOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logDebugOutput.find("[DEBUG]") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_DEBUGisInvoked_WillLogInformationContainCorrectFileInformation)
{
    LOG_DEBUG("test logging | severity debug");
    std::string logDebugOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logDebugOutput.find("LoggerTest.cpp") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_DEBUGisInvoked_WillLogInformationContainCorrectLineNumber)
{
    LOG_DEBUG("test logging | severity debug");

    int32_t excpectedLineNumber = __LINE__ - 2;

    std::stringstream ss;
    ss << "line: " << excpectedLineNumber;

    std::string logDebugOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logDebugOutput.find(ss.str()) != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_DEBUGisInvoked_WillLogInformationContainLineNumber)
{
    LOG_DEBUG("test logging | severity debug");
    std::string logDebugOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logDebugOutput.find("test logging | severity debug") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_INFOisInvoked_WillLogInformationContatinInfoSeverity)
{
    LOG_INFO("test logging | severity info");
    std::string logInfoOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logInfoOutput.find("[INFO]") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_INFOisInvoked_WillLogInformationContainCorrectFileInformation)
{
    LOG_INFO("test logging | severity info");
    std::string logInfoOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logInfoOutput.find("LoggerTest.cpp") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_INFOisInvoked_WillLogInformationContainCorrectLineNumber)
{
    LOG_INFO("test logging | severity info");

    int32_t excpectedLineNumber = __LINE__ - 2;

    std::stringstream ss;
    ss << "line: " << excpectedLineNumber;

    std::string logInfoOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logInfoOutput.find(ss.str()) != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_INFOisInvoked_WillLogInformationContainLineNumber)
{
    LOG_INFO("test logging | severity info");
    std::string logInfoOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logInfoOutput.find("test logging | severity info") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_WARNisInvoked_WillLogInformationContatinWarnSeverity)
{
    LOG_WARN("test logging | severity warn");
    std::string logWarnOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logWarnOutput.find("[WARN]") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_WARNisInvoked_WillLogInformationContainCorrectFileInformation)
{
    LOG_WARN("test logging | severity warn");
    std::string logWarnOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logWarnOutput.find("LoggerTest.cpp") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_WARNisInvoked_WillLogInformationContainCorrectLineNumber)
{
    LOG_WARN("test logging | severity warn");

    int32_t excpectedLineNumber = __LINE__ - 2;

    std::stringstream ss;
    ss << "line: " << excpectedLineNumber;

    std::string logWarnOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logWarnOutput.find(ss.str()) != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_WARNisInvoked_WillLogInformationContainLineNumber)
{
    LOG_WARN("test logging | severity warn");
    std::string logWarnOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logWarnOutput.find("test logging | severity warn") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_ERRORisInvoked_WillLogInformationContatinErrorSeverity)
{
    LOG_ERROR("test logging | severity error");
    std::string logErrorOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logErrorOutput.find("[ERROR]") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_ERRORisInvoked_WillLogInformationContainCorrectFileInformation)
{
    LOG_ERROR("test logging | severity error");
    std::string logErrorOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logErrorOutput.find("LoggerTest.cpp") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_ERRORisInvoked_WillLogInformationContainCorrectLineNumber)
{
    LOG_ERROR("test logging | severity error");

    int32_t excpectedLineNumber = __LINE__ - 2;

    std::stringstream ss;
    ss << "line: " << excpectedLineNumber;

    std::string logErrorOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logErrorOutput.find(ss.str()) != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_ERRORisInvoked_WillLogInformationContainLineNumber)
{
    LOG_ERROR("test logging | severity error");
    std::string logErrorOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logErrorOutput.find("test logging | severity error") != std::string::npos);
}
