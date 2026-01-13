// main.cpp
#include <iostream>
#include "Helpers.h"

int main() {
    int num1 = 5;
    int num2 = 3;

    // Вызов функции из Helpers.h
    int result = squareOfSum(num1, num2);

    std::cout << "Numm 1: " << num1 << std::endl;
    std::cout << "Numm 2: " << num2 << std::endl;
    std::cout << "Summ**2: " << result << std::endl;

    return 0;
}