#include <iostream>
#include "polynomial.h"
using namespace std;

int main() {
    Polynomial<1,2,3> P;
    std::cout << P.evaluate(2); // 17
    return 0;
}
