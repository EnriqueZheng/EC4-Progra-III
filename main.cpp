#include <iostream>
using namespace std;

#include "type_list.h"

int main() {
    using L = TypeList<int,double,char>;
    static_assert(L::size==3);
    using F = typename L::Front;
    static_assert(std::is_same_v<F,int>);
    return 0;
}
