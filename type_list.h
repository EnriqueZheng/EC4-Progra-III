#ifndef PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_TYPE_LIST_H
#define PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_TYPE_LIST_H
#include <cstddef>
#include <type_traits>

template<typename... types>
struct TypeList;

template<typename type, typename... types>
struct TypeList<type, types...> {
    static constexpr size_t size = 1 + sizeof...(types);
    using Front = type;
    using PopFront = TypeList<types...>;
    template<typename T>
    using PushFront = TypeList<T, type, types...>;

};

template<>
struct TypeList<> {
    static constexpr std::size_t size = 0;
    template<typename T>
    using PushFront = TypeList<T>;
};


#endif //PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_TYPE_LIST_H