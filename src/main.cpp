#include "adlib.hpp" // Accurate Decimal Library

int main(void) {
    Dec d1 = Dec(1.2); // 12e-1
    Dec d2 = Dec(12);  // 12e0
    Dec d3 = Dec(120); // 12e1
    Dec d4 = DecLR(123, 449); // 123.449 = 123449e-3
    Dec d5 = Dec(1268, -2); // 12.68 = 1268e-2

    d1.print();
    d2.print();
    d3.print();
    d4.print();
    d5.print();
}