#include <iostream>
#include <math.h>

float discriminant(float a, float b, float c) {
    return pow(b, 2) - 4*a*c;
}

void quadraticFor(float a, float b, float c, float d) {
    if(d > 0) {
        std::cout << "There are 2 solutions." << std::endl
        << "The solutions are: " << (-b + sqrt(pow(b, 2) - 4*a*c))/(2*a) << " and " << (-b - sqrt(pow(b, 2) - 4*a*c))/(2*a);
    } else if(d == 0) {
        std::cout << "There is 1 solution." << std::endl
        << "The solution is: " << -b/(2*a);
    } else {      
        std::cout << "There is no solution.";
    }
}

int main() {
    float a;
    float b;
    float c;

    std::cout << "Please enter the values of a, b, and c: " << std::endl;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    quadraticFor(a, b, c, discriminant(a, b, c));

    return 0;
}