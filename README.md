# Task #Task: Templates de Clases  
**course:** Programación III  
**unit:** 2  
**cmake project:** prog3_unit2_template_clases_v2026_01

## Indicaciones Específicas
El tiempo límite para la evaluación es 2 horas.

Cada pregunta deberá ser respondida en un archivo fuente (.cpp) y un archivo cabecera (.h) correspondiente:

- `array_wrapper.h`
- `tuple_printer.h`
- `static_matrix.h`
- `type_list.h`
- `serializer.h`
- `fixed_point.h`
- `logger.h`
- `polynomial.h`
- `smart_array.h`
- `unit.h`

Deberás subir estos archivos directamente a www.gradescope.com o se puede crear un .zip que contenga todos ellos y subirlo.

---

## Question #1 - ArrayWrapper templates (2 points)

**Enunciado:**  
Implementa `ArrayWrapper<T, N>` que encapsula un arreglo estático de `N` elementos con acceso seguro. Debe proveer `size()`, `at(i)` (lanza excepción si $i∉\left[0,N\right)$) y constructor por defecto. **Especialización total** para `N=0`: no almacena datos y `at(...)` siempre lanza.

### Use cases

**Use Case #1**: int con acceso válido
```cpp
ArrayWrapper<int, 5> a;
for (std::size_t i = 0; i < a.size(); ++i) a.at(i) = (int)(i*10);
std::cout << "size=" << a.size() << ", a[2]=" << a.at(2) << "\n"; // size=5, a[2]=20
```
**Use Case #2**: strings
```cpp
ArrayWrapper<std::string, 3> s;
s.at(0)="UTEC"; s.at(1)="Templates"; s.at(2)="C++";
std::cout << s.at(0) << " - " << s.at(1) << " - " << s.at(2) << "\n"; // UTEC - Templates - C++
```
**Use Case #3**: caso N=0
```cpp
ArrayWrapper<double, 0> z;
std::cout << "size=" << z.size() << "\n"; // size=0
try { z.at(0); } catch(const std::out_of_range& e){ std::cout << "Excepcion esperada\n"; }
```
**Use Case #4**: índice fuera de rango
```cpp
ArrayWrapper<char, 1> c; c.at(0)='X';
try { c.at(1); } catch(const std::out_of_range& e){ std::cout << "OK\n"; }
```
---
## Question #2 - TuplePrinter templates (2 points)

**Enunciado:**  
Implementa `TuplePrinter<Ts...>` (variadic) con `print(tuple)`. Debe manejar tuple vacía y **especializar** el caso de un solo elemento.

### Use cases

// **Use Case #1**: 3 elementos
```cpp
auto t1 = std::make_tuple(42,3.14,std::string("UTEC"));
TuplePrinter<int,double,std::string>::print(t1); // 42, 3.14, UTEC
```
// **Use Case #2**: un solo elemento
```cpp
auto t2 = std::make_tuple('A');
TuplePrinter<char>::print(t2); // A
```
// **Use Case #3**: tuple vacía
```cpp
auto t3 = std::tuple<>();
TuplePrinter<>::print(t3); // (sin salida)
```
// **Use Case #4**: dos ints
```cpp
auto t4 = std::make_tuple(10,20);
TuplePrinter<int,int>::print(t4); // 10, 20
```

---

## Question #3 - StaticMatrix templates (2 points)

**Enunciado:**  
Implementa `StaticMatrix<T, Rows, Cols>` con `at(r,c)`, suma `+` y multiplicación `*`. **Especialización parcial** para matrices cuadradas con `determinant()`.

### Use cases

// **Use Case #1**: suma 2x3
```cpp
StaticMatrix<int,2,3> A,B;
auto C = A+B; // resultado 2x3
```
// **Use Case #2**: multiplicación 2x3 * 3x2
```cpp
StaticMatrix<int,2,3> M1;
StaticMatrix<int,3,2> M2;
auto M3 = M1*M2; // resultado 2x2
```
// **Use Case #3**: determinante 3x3
```cpp
StaticMatrix<double,3,3> S;
// set valores...
double d = S.determinant(); // det calculado
```
// **Use Case #4**: determinante 1x1
```cpp
StaticMatrix<double,1,1> S1;
S1.at(0,0)=7.5;
std::cout << S1.determinant(); // 7.5
```

---

## Question #4 - TypeList templates (2 points)

**Enunciado:**  
Define `TypeList<Ts...>` con utilidades de metaprogramming (`size`, `Front`, `PopFront`, `PushFront`). **Especializa** lista vacía.

### Use cases

// **Use Case #1**: size
```cpp
using L = TypeList<int,double,char>;
static_assert(L::size==3);
```
// **Use Case #2**: front
```cpp
using F = typename L::Front;
static_assert(std::is_same_v<F,int>);
```
// **Use Case #3**: pop front
```cpp
using L2 = typename L::PopFront;
static_assert(L2::size==2);
```
// **Use Case #4**: lista vacía
```cpp
using E = TypeList<>;
static_assert(E::size==0);
```

---

## Question #5 - Serializer templates (2 points)

**Enunciado:**  
`Serializer<T>` con método `to_string`. **Especialización total** para `int,double,string`. Variadic `Serializer<Ts...>` concatena objetos.

### Use cases

// **Use Case #1**: int
```cpp
std::string s1 = Serializer<int>::to_string(42); // "42"
```
// **Use Case #2**: double y string
```cpp
auto s2 = Serializer<double>::to_string(3.14);   // "3.14"
auto s3 = Serializer<std::string>::to_string("UTEC"); // "UTEC"
```
// **Use Case #3**: variadic
```cpp
auto s4 = Serializer<int,double,std::string>::to_string(1,2.5,"x"); // "1|2.5|x"
```
// **Use Case #4**: tipo no especializado
```cpp
struct X{int v;};
X x{7};
auto s5 = Serializer<X>::to_string(x); // "[X:7]" o similar
```

---

## Question #6 - FixedPoint templates (2 points)

**Enunciado:**  
`FixedPoint<Bits,Fraction>` con representación entera y operadores básicos. **Especializa** `Fraction=0` como entero puro.

### Use cases

// **Use Case #1**: suma
```cpp
FixedPoint<16,8> a=1.5,b=2.25;
auto c=a+b; // ~3.75
```
// **Use Case #2**: multiplicación
```cpp
FixedPoint<16,8> x=3.0,y=0.5;
auto z=x*y; // ~1.5
```
// **Use Case #3**: fraction=0
```cpp
FixedPoint<16,0> i=10,j=5;
auto k=i+j; // 15
```
// **Use Case #4**: conversión a double
```cpp
FixedPoint<16,8> q=2.75;
double d=(double)q; // 2.75
```

---

## Question #7 - Logger templates (2 points)

**Enunciado:**  
`Logger<Level,Ts...>` imprime mensajes con prefijo según enum `Level`. **Especializa** `ERROR` para anteponer `"ERROR:"`.

### Use cases

// **Use Case #1**: info
```cpp
Logger<Level::INFO,const char*,int>::log("count",3); // INFO: count 3
```
// **Use Case #2**: warning
```cpp
Logger<Level::WARNING,std::string>::log("low memory"); // WARNING: low memory
```
// **Use Case #3**: error
```cpp
Logger<Level::ERROR,int>::log(404); // ERROR: 404
```
// **Use Case #4**: mezcla
```cpp
Logger<Level::INFO,int,double,const char*>::log(1,2.5,"ok"); // INFO: 1 2.5 ok
```

---

## Question #8 - Polynomial templates (2 points)

**Enunciado:**  
`Polynomial<Coeffs...>` con parámetros no-tipo enteros. Método `evaluate(x)`. **Especializa total** `Polynomial<>` → 0.

### Use cases

// **Use Case #1**
```cpp
Polynomial<1,2,3> P;
std::cout << P.evaluate(2); // 17
```
// **Use Case #2**
```cpp
Polynomial<5> C;
std::cout << C.evaluate(100); // 5
```
// **Use Case #3**
```cpp
Polynomial<> Z;
std::cout << Z.evaluate(123); // 0
```
// **Use Case #4**
```cpp
Polynomial<-1,0,1> Q;
std::cout << Q.evaluate(3); // 8
```

---

## Question #9 - SmartArray templates (2 points)

**Enunciado:**  
`SmartArray<T,Alloc>` con `push_back`, `[]`, `size`. **Especializa** `T=bool` para almacenamiento bit-packed.

### Use cases

// **Use Case #1**: enteros
```cpp
SmartArray<int> a;
for(int i=0;i<5;++i) a.push_back(i);
std::cout << a[2]; // 2
```
// **Use Case #2**: allocator custom
```cpp
struct MyAlloc: std::allocator<int>{};
SmartArray<int,MyAlloc> b;
b.push_back(10); // agrega 10
```
// **Use Case #3**: bool especializado
```cpp
SmartArray<bool> f;
f.push_back(true); f.push_back(false);
std::cout << f[0] << f[1]; // 1 0
```
// **Use Case #4**: strings
```cpp
SmartArray<std::string> s;
for(int i=0;i<100;++i) s.push_back("x");
std::cout << s.size(); // 100
```

---

## Question #10 - Unit templates (2 points)

**Enunciado:**  
`Unit<T,Tag>` representa magnitudes fisicas usando un `Tag` para identificar la unidad. Soporta `+`, `-`, `*` y `/`. **Especializa total** `Unit<int,seconds_tag>` para tiempo con helpers.

### Use cases

// **Use Case #1**: metros
```cpp
struct meter_tag {
    static constexpr const char* symbol() { return "m"; }
};

Unit<double,meter_tag> d1{3.5}, d2{2.0};
auto d3=d1+d2; // 5.5 m
```
// **Use Case #2**: segundos especializado
```cpp
Unit<int,seconds_tag> t1{10},t2{5};
auto t3=t1+t2; // 15 s
t3.minutes();  // 0.25
```
// **Use Case #3**: multiplicación de unidades
```cpp
Unit<double,meter_tag> m{3.0};
Unit<double,seconds_tag> s{2.0};
auto ms=m*s; // m*s
```
// **Use Case #4**: división
```cpp
Unit<double,meter_tag> m{3.0};
Unit<double,seconds_tag> s{2.0};
auto v=m/s; // m/s
```
