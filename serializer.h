#ifndef PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_SERIALIZER_H
#define PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_SERIALIZER_H
#include <string>
#include <sstream>

template <typename... Ts>
struct Serializer;

template <typename T>
struct Serializer<T> {
    static std::string to_string(const T& x) {
        std::ostringstream oss;
        oss << x;
        return oss.str();
    }
};

template <>
struct Serializer<int> {
    static std::string to_string(int x) {
        return std::to_string(x);
    }
};

template <>
struct Serializer<double> {
    static std::string to_string(double x) {
        std::ostringstream oss;
        oss << x;
        return oss.str();
    }
};

template <>
struct Serializer<std::string> {
    static std::string to_string(const std::string& x) {
        return x;
    }
};

template <typename T, typename U, typename... Rest>
struct Serializer<T, U, Rest...> {
    static std::string to_string(const T& first, const U& second, const Rest&... rest) {
        return Serializer<T>::to_string(first) + "|" + Serializer<U, Rest...>::to_string(second, rest...);
    }
};
#endif //PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_SERIALIZER_H