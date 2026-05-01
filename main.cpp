#include <iostream>
using namespace std;

#include "static_matrix.h"

int main() {
    StaticMatrix<double,1,1> S1;
    S1.at(0,0)=7.5;
    std::cout << S1.determinant(); // 7.5
    return 0;
}
