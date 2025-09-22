// #include <iostream>
// #include <bitset>
// #include <climits>
// #include <string>
// #include <algorithm>

// std::string toBinaryWithSpaces(int num){
//     if (num == 0) return "0000";

//     std::string binary;
//     int count = 0;

//     unsigned int unum = num;
//     while (unum > 0){
//         binary += (unum & 1) ? '1' : '0';
//         count ++;
//     }

//     int remainder = count % 4;
//     if (remainder != 0){
//         for (int i=0; i< 4-remainder; i++){
//             binary += '0';
//         }
//     }

//     std::reverse(binary.begin(), binary.end());

//     std::string result;
//     for (size_t i=0; i<binary.length(); i++){
//         if (i>0 && i%4==0){
//             result += " ";
//         }
//         result += binary[i];
//     }
//     return result;
// }

// int main(){
//     while(true){
//         int num1, num2;
//         std::cout << "Please enter first number (base-10): ";
//         std::cin >> num1;
//         std::cout << "Please enter second number (base-10): ";
//         std::cin >> num2;

//         int sum = num1 + num2;

//         // // We use bitset<32> because we assume the integers are in 32-bit range. We don't care a shit of overflowing because that is NOT OUR PROBLEM
//         // std::bitset<sizeof(int) * CHAR_BIT> binary(sum);

//         std::cout << "Their sum (base-10): " << sum << std::endl;
//         std::cout << "In binary: " << toBinaryWithSpaces(sum) << std::endl;
//     }
// }

// terminate called after throwing an instance of 'std::bad_alloc'
//   what():  std::bad_alloc

#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>

std::string formatBinaryPretty(int num){
    if (num == 0) return "0000";

    std::bitset<32> binary(num);
    std::string binaryStr = binary.to_string();

    size_t firstOne = binaryStr.find('1');
    if (firstOne != std::string::npos){
        binaryStr = binaryStr.substr(firstOne);
    }

    int remainder = binaryStr.length() % 4;
    if (remainder != 0) {
        binaryStr = std::string(4 - remainder, '0') + binaryStr;
    }

    std::string result;
    for (size_t i=0; i < binaryStr.length(); i++){
        if (i > 0 && i % 4 == 0){
            result += " ";
        }
        result += binaryStr[i];
    }

    return result;
}

int main(){
    while(true){
        int num1, num2;
        std::cout << "Please enter first number (base-10): ";
        std::cin >> num1;
        std::cout << "Please enter second number (base-10): ";
        std::cin >> num2;

        int sum = num1 + num2;

        std::cout << "Their sum (base-10): " << sum << std::endl;
        std::cout << "In binary: " << formatBinaryPretty(sum) << std::endl;
        std::cout << "Press Ctrl+C to exit or continue to add more numbers." << std::endl;
    }
}