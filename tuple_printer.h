#ifndef PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_TUPLE_PRINTER_H
#define PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_TUPLE_PRINTER_H
#include <iostream>
template<typename... Args>
struct TuplePrinter;

template<>
struct TuplePrinter<> {
    static void print(std::tuple<>&) {
    }
};
template<typename T>
struct TuplePrinter<T> {
    static void print(std::tuple<T>& t) {
        std::cout << std::get<0>(t) << std::endl;
    }
};

template<typename T, typename S, typename... Args>
struct TuplePrinter<T,S,Args...> {
    static void print(std::tuple<T,S,Args...>& t) {
        subprint(t,std::index_sequence_for<T,S,Args...>{});
    }
private:
    template<std::size_t... Vals>
    static void subprint(std::tuple<T,S,Args...>& t,std::index_sequence<Vals...>) {
        ((std::cout << (Vals == 0 ? "" : ", ") << std::get<Vals>(t)), ...);
    }

};


#endif //PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_TUPLE_PRINTER_H