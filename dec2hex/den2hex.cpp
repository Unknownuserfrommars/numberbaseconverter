#include <iostream>
#include <iomanip> // Required for std::hex

int main() {
    while(true){
        int decimal_number;
        std::cout << "Decimal: ";
        std::cin >> decimal_number;
        if (decimal_number < 0) break; // Exit on negative input
        std::cout << "Hexadecimal: " << std::hex << decimal_number << std::endl; // Output in hex    
    }
    return 0;
}