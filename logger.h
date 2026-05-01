#ifndef PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_LOGGER_H
#define PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_LOGGER_H
#include <iostream>

enum class Level {ERROR,WARNING,INFO};

template<Level level, typename... Ts>
struct Logger{
    static void log(const Ts&... args) {
        if constexpr (level == Level::INFO) {
            std::cout<<"INFO: ";
        }
        else if constexpr (level == Level::WARNING) {
            std::cout<<"WARNING: ";
        }
        ((std::cout << args << " "), ...);
        std::cout << std::endl;
    }
};
template<typename... Ts>
struct Logger<Level::ERROR,Ts...> {
    static void log(const Ts&... args) {
        std::cout<<"ERROR: ";
        ((std::cout << args << " "), ...);
        std::cout << std::endl;
    }
};


#endif //PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_LOGGER_H