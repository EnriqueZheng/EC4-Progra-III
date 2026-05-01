#ifndef PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_FIXED_POINT_H
#define PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_FIXED_POINT_H

#include <cstdint>
#include <cmath>
#include <concepts>
#include <type_traits>

template <int Bits, int Fraction>
concept ValidFixedParams = (Bits > 0) && (Fraction >= 0) && (Fraction < Bits);

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <int Bits>
using StorageFor_t =
    std::conditional_t<Bits <= 8,  std::int8_t,
    std::conditional_t<Bits <= 16, std::int16_t,
    std::conditional_t<Bits <= 32, std::int32_t,
                                   std::int64_t>>>;

template <int Bits, int Fraction>
    requires ValidFixedParams<Bits, Fraction>
class FixedPoint {
    using Storage = StorageFor_t<Bits>;
    Storage raw{};
    static constexpr Storage SCALE = Storage(1) << Fraction;

public:
    FixedPoint() = default;

    template <Numeric V>
    FixedPoint(V v)
        : raw(static_cast<Storage>(std::llround(static_cast<double>(v) * SCALE))) {}

    static FixedPoint from_raw(Storage r) { FixedPoint f; f.raw = r; return f; }
    Storage get_raw() const { return raw; }

    explicit operator double() const { return double(raw) / double(SCALE); }

    FixedPoint operator+(const FixedPoint& o) const { return from_raw(raw + o.raw); }
    FixedPoint operator-(const FixedPoint& o) const { return from_raw(raw - o.raw); }
    FixedPoint operator*(const FixedPoint& o) const {
        return from_raw(static_cast<Storage>((std::int64_t(raw) * o.raw) >> Fraction));
    }
    FixedPoint operator/(const FixedPoint& o) const {
        return from_raw(static_cast<Storage>((std::int64_t(raw) << Fraction) / o.raw));
    }
};

template <int Bits>
    requires (Bits > 0)
class FixedPoint<Bits, 0> {
    using Storage = StorageFor_t<Bits>;
    Storage raw{};
public:
    FixedPoint() = default;

    template <std::integral V>
    FixedPoint(V v) : raw(static_cast<Storage>(v)) {}

    explicit operator int()    const { return int(raw); }
    explicit operator double() const { return double(raw); }

    FixedPoint operator+(const FixedPoint& o) const { FixedPoint r; r.raw = raw + o.raw; return r; }
    FixedPoint operator-(const FixedPoint& o) const { FixedPoint r; r.raw = raw - o.raw; return r; }
    FixedPoint operator*(const FixedPoint& o) const { FixedPoint r; r.raw = raw * o.raw; return r; }
    FixedPoint operator/(const FixedPoint& o) const { FixedPoint r; r.raw = raw / o.raw; return r; }
};


#endif //PROG3_UNIT2_TEMPLATE_CLASES_V2026_01_FIXED_POINT_H