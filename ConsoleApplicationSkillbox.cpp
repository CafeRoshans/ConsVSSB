#include <iostream>
#include <string>

int main() {
    std::string myString = "";
    std::cout << "Str: " << myString << std::endl;
    std::cout << "Len str: " << myString.length() << " symb" << std::endl;
    
    if (!myString.empty()) {
        std::cout << "First: " << myString.front() << std::endl;
        std::cout << "Last: " << myString.back() << std::endl;
    } else {
        std::cout << "Is empty" << std::endl;
    }
    
    return 0;
}