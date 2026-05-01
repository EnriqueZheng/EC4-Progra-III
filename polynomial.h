#ifndef PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_POLYNOMIAL_H
#define PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_POLYNOMIAL_H
#include <cstddef>
#include <utility>

template <int... Coeficientes>
struct Polynomial {
private:
    template <typename X>
    static constexpr X pow_int(X x, std::size_t n) {
        X r = X(1);
        for (std::size_t i = 0; i < n; ++i) r *= x;
        return r;
    }

    template <typename X, std::size_t... Is>
    static constexpr auto eval_impl(X x, std::index_sequence<Is...>) {
        // c_0 * x^0 + c_1 * x^1 + c_2 * x^2 + ...
        return ((Coeficientes * pow_int(x, Is)) + ...);
    }

public:
    template <typename X>
    constexpr auto evaluate(X x) const {
        return eval_impl(x, std::make_index_sequence<sizeof...(Coeficientes)>{});
    }
};


template<>
class Polynomial<> {
    template<typename T>
    constexpr int evaluate(T& x) const {
        return 0;
    }
};
#endif //PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_POLYNOMIAL_H