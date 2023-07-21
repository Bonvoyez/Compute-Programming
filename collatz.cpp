#include <iostream>
#include <string>

int main() {
    int number;
    std::cout << "Enter the first number of the sequence: ";
    std::cin >> number;
    std::cout << number << std::string(" ");
    int count = 0;
    if(number == 1){
        count += 1;
    }

    while(count != 3){
        if (number % 2 == 0){
            number = number / 2;
            
        } else if(number % 2 == 1){
            number = 3 * number + 1;
        }
        std::cout << number << std::string(" ");
        if(number == 1){
            count++;
        }
    }
    std::cout << std::string("...");
}