#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <mutex>
#include <ctime>

enum class LogLevel {
    ERROR = 0,
    WARNING = 1,
    INFO = 2
};

class Logger {
public:
    Logger(const std::string& filename, LogLevel level);
    ~Logger();

    void log(const std::string& message, LogLevel level);
    void setLogLevel(LogLevel level);

private:
    std::ofstream logFile;
    LogLevel currentLevel;
    std::mutex logMutex;

    std::string getCurrentTime();
    std::string logLevelToString(LogLevel level);
};

#endif // LOGGER_H
