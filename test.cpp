#include <iostream>
#include <thread>
#include <vector>
#include "logger.h"

// Функция для записи сообщений в журнал в отдельном потоке
void logMessage(Logger& logger, const std::string& message, LogLevel level) {
    logger.log(message, level);
}

// Функция для преобразования строки в число
int StringToInt(const std::string& str, int minValue, int maxValue) {
    try {
        int value = std::stoi(str);
        if (value >= minValue && value <= maxValue) {
            return value;
        } 
        else {
            std::cerr << "Ошибка: Введите число от " << minValue << " до " << maxValue << "!\n";
        }
        } 
        catch (const std::invalid_argument& e) {
            std::cerr << "Ошибка: Введите число!\n";
        } 
}

int main(int argc, char* argv[]) {
    // Проверка количества аргументов терминала
    if (argc != 3) {
        std::cerr << "Использование: " << argv[0] << " <файл_лога> <уровень_по_умолчанию>\n";
        std::cerr << "Уровни: 0 - ERROR, 1 - WARNING, 2 - INFO\n";
        return 1;
    }

    // Получение параметров из терминала
    std::string logFileName = argv[1];
    int logLevelInt = StringToInt(argv[2], 0, 2);

    // Создание журнала
    Logger logger(logFileName, static_cast<LogLevel>(logLevelInt));

    std::vector<std::thread> threads; // Вектор для хранения потоков

    while (true) {
        std::string num;
        int numInt;

        std::cout << "Выберите:\n 1 - записать сообщение\n 2 - сменить уровень важности сообщения по умолчанию\n 3 - для выхода\n ";
        std::getline(std::cin, num);

        numInt = StringToInt(num, 1, 3);

        if (numInt == 1) {
            std::string message;
            int levelInt = logLevelInt;  // Уровень по умолчанию

            // Запрос ввода сообщения
            std::cout << "Введите сообщение для лога: ";
            std::getline(std::cin, message);

            // Запрос уровня важности
            std::cout << "Введите уровень важности (0 - ERROR, 1 - WARNING, 2 - INFO, ENTER - по умолчанию): ";
            std::string levelInput;
            std::getline(std::cin, levelInput);

            if (!levelInput.empty()) {
                levelInt = StringToInt(levelInput, 0, 2);
            }

            // Создание и запись потока для записи в журнал
            threads.emplace_back(logMessage, std::ref(logger), message, static_cast<LogLevel>(levelInt));
        } 
        // Смена уровня важности
        else if (numInt == 2) {
            std::cout << "Введите новый уровень важности по умолчанию: ";
            std::string defLevel;
            std::getline(std::cin, defLevel);

            if (!defLevel.empty()) {
                int defLevelInt = StringToInt(defLevel, 0, 2);
                logger.setLogLevel(static_cast<LogLevel>(defLevelInt));
                logLevelInt = defLevelInt;
            }
        } 
        else if (numInt == 3){
            break;
        }
    }

    // Завершение всех потоков
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }

    std::cout << "Завершение программы...\n";
    return 0;
}