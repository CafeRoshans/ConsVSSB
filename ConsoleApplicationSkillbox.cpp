#include <iostream>
#include <string>

void PrintEvenOrOddNumbers(int maxNumber, bool IsOdd) {
    std::cout << "Numbers from 0 to " << maxNumber;
    std::cout << (IsOdd ? " (Even): " : " (Odd): ");

    for (int i = (IsOdd ? 0 : 1); i <= maxNumber; i += 2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int N = 20;

    PrintEvenOrOddNumbers(N, true);
    PrintEvenOrOddNumbers(N, false);
    
    return 0;
}