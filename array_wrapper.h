#ifndef PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_ARRAY_WRAPPER_H
#define PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_ARRAY_WRAPPER_H
#include <stdexcept>


template<typename T, int N>
class ArrayWrapper {
    T array[N];
public:
    ArrayWrapper(){
        for (int i = 0; i < N; i++) {
            array[i] = T();
        }
    }

    int size(){
        return N;
    }
    T& at(int i) {
        if (i < 0 || i >= N) {
            throw std::out_of_range("Índice fuera de los límites del template N");
        }
        return array[i];
    }
};


#endif //PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_ARRAY_WRAPPER_H