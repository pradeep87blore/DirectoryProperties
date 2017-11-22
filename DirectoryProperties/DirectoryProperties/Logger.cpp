#include "Logger.h"
#include <string>

using std::string;


Logger Logger::instance;


Logger::Logger()
{
    currentLogLevel = LL_INFO;
    latestLogLineNumber = 1;
    printedLogsTill = 0;
    
}


Logger::~Logger()
{

}



int Logger::LogMessage(string sLogMsg, string sFileName, string sFunctionName, int iLineNumber, LogLevel ll)
{    

    // If the current log level is not high enough to print this log, ignore
    // For e.g., if the log is of level LL_INFO and the current log level is set to LL_CRITICAL, that means
    // that we should not print this log, since the LL_INFO is higher than LL_CRITICAL
    if (ll > instance.currentLogLevel) 
        return 0;

    string sLog = "Log Number:  + " + std::to_string(instance.latestLogLineNumber) + "\n" +
        "File: " + sFileName + "\n" + "Function: " + sFunctionName + " @Line: " + std::to_string(iLineNumber) + "\n" +
        "Log Message: " + sLogMsg;
    
    instance.logMessages.insert(std::make_pair(instance.latestLogLineNumber++, sLog));
    return sLogMsg.length();
}

Logger& Logger::GetLogger() // Note: Using the reference as the return since this is a unique pointer and doesnt allow duplication of instance
{
    return instance;
} 

void Logger::PrintAllLogs()
{

}