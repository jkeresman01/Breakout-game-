#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

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

TEST_F(LoggerTest, AfterLOG_DEBUGisInvokedWillLogInformationContatinDebugSeverity)
{
    LOG_DEBUG("test logging | severity debug");
    std::string logDebugOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logDebugOutput.find("[DEBUG]") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_DEBUGisInvokedWillLogInformationContainCorrectFileInformation)
{
    LOG_DEBUG("test logging | severity debug");
    std::string logDebugOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logDebugOutput.find("LoggerTest.cpp") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_DEBUGisInvokedWillLogInformationContainCorrectLineNumber)
{
    LOG_DEBUG("test logging | severity debug");
    std::string logDebugOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logDebugOutput.find("line: 45") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_DEBUGisInvokedWillLogInformationContainLineNumber)
{
    LOG_DEBUG("test logging | severity debug");
    std::string logDebugOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logDebugOutput.find("test logging | severity debug") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_INFOisInvokedWillLogInformationContatinInfoSeverity)
{
    LOG_INFO("test logging | severity info");
    std::string logInfoOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logInfoOutput.find("[INFO]") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_INFOisInvokedWillLogInformationContainCorrectFileInformation)
{
    LOG_INFO("test logging | severity info");
    std::string logInfoOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logInfoOutput.find("LoggerTest.cpp") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_INFOisInvokedWillLogInformationContainCorrectLineNumber)
{
    LOG_INFO("test logging | severity info");
    std::string logInfoOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logInfoOutput.find("line: 77") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_INFOisInvokedWillLogInformationContainLineNumber)
{
    LOG_INFO("test logging | severity info");
    std::string logInfoOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logInfoOutput.find("test logging | severity info") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_WARNisInvokedWillLogInformationContatinWarnSeverity)
{
    LOG_WARN("test logging | severity warn");
    std::string logWarnOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logWarnOutput.find("[WARN]") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_WARNisInvokedWillLogInformationContainCorrectFileInformation)
{
    LOG_WARN("test logging | severity warn");
    std::string logWarnOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logWarnOutput.find("LoggerTest.cpp") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_WARNisInvokedWillLogInformationContainCorrectLineNumber)
{
    LOG_WARN("test logging | severity warn");
    std::string logWarnOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logWarnOutput.find("line: 109") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_WARNisInvokedWillLogInformationContainLineNumber)
{
    LOG_WARN("test logging | severity warn");
    std::string logWarnOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logWarnOutput.find("test logging | severity warn") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_ERRORisInvokedWillLogInformationContatinErrorSeverity)
{
    LOG_ERROR("test logging | severity error");
    std::string logErrorOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logErrorOutput.find("[ERROR]") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_ERRORisInvokedWillLogInformationContainCorrectFileInformation)
{
    LOG_ERROR("test logging | severity error");
    std::string logErrorOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logErrorOutput.find("LoggerTest.cpp") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_ERRORisInvokedWillLogInformationContainCorrectLineNumber)
{
    LOG_ERROR("test logging | severity error");
    std::string logErrorOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logErrorOutput.find("line: 141") != std::string::npos);
}

TEST_F(LoggerTest, AfterLOG_ERRORisInvokedWillLogInformationContainLineNumber)
{
    LOG_ERROR("test logging | severity error");
    std::string logErrorOutput = getCapturedCerrOutput();

    EXPECT_TRUE(logErrorOutput.find("test logging | severity error") != std::string::npos);
}
