#include <iostream>
#include <string>

int main() {
    std::string myString = "Hello, World!";
    std::cout << "Str: " << myString << std::endl;
    std::cout << "Len str: " << myString.length() << " symb" << std::endl;
    
    if (!myString.empty()) {
        std::cout << "First: " << myString[0] << std::endl;
        std::cout << "Last: " << myString[myString.length() - 1] << std::endl;
    } else {
        std::cout << "Is empty" << std::endl;
    }
    
    return 0;
}