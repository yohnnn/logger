CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Цели сборки
all: liblogger.so test

# Сборка библиотеки
liblogger.so: logger.cpp
	$(CXX) $(CXXFLAGS) -fPIC -shared -o $@ $^

# Сборка тестового приложения
test: test.cpp liblogger.so
	$(CXX) $(CXXFLAGS) -o $@ $< -L. -llogger -pthread -Wl,-rpath,.

# Очистка
clean:
	rm -f *.o *.so test