#include "logger.h"
#include <iostream>

Logger::Logger(const std::string& filename, LogLevel level) : currentLevel(level) {
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open()) {
        throw std::runtime_error("Не удалось открыть файл журнала.");
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::log(const std::string& message, LogLevel level) {
    if (level > currentLevel) return;

    std::lock_guard<std::mutex> lock(logMutex);
    logFile << getCurrentTime() << " [" << logLevelToString(level) << "] " << message << std::endl;
}

void Logger::setLogLevel(LogLevel level) {
    std::lock_guard<std::mutex> lock(logMutex);
    currentLevel = level;
}

std::string Logger::getCurrentTime() {
    std::time_t now = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    return buf;
}

std::string Logger::logLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::INFO: return "INFO";
        default: return "UNKNOWN";
    }
}
