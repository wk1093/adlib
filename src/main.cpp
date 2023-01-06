#include "adlib.hpp" // Accurate Decimal Library

int main(void) {
    Dec d1 = Dec(1.2); // 12e-1
    Dec d2 = Dec(12);  // 12e0
    Dec d3 = Dec(120); // 12e1

    d1.print();
    d2.print();
    d3.print();
}