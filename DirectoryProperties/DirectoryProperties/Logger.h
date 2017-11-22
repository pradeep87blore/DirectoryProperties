#ifndef LOGGER_H
#define LOGGER_H

#include <memory> // For smart pointers
#include <string>
//#include <vector>
#include <map>

using std::string;
//using std::vector;
using std::map;

#define ADDLOG(a, b) Logger::LogMessage(a, __FILE__, __FUNCTION__, __LINE__, b)

enum LogLevel
{
    LL_NONE = 0,
    LL_CRITICAL,
    LL_ERROR,
    LL_EXCEPTIONS,
    LL_WARNING,
    LL_INFO
};

/* This class shall be used to prints all the logs. The logs should be collected either on a file or displayed to the default terminal*/
class Logger
{
    static Logger instance;
    // Hide the public constructor to prevent the class initialization
    Logger();

    LogLevel currentLogLevel;

    int latestLogLineNumber; // The log line number for the next log
    int printedLogsTill; // This shall indicate till what log line the logs were dumped to any output, by calling PrintAllLogs

    map<int,std::string> logMessages; // The key is the log line number

public:
    ~Logger();
    static Logger& GetLogger();

    // Call this function to print the logs
    static int LogMessage(string sLogMsg, string sFileName, string sFunctionName, int iLineNumber, LogLevel ll = LL_CRITICAL);

    static void PrintAllLogs();
};

#endif // LOGGER_H