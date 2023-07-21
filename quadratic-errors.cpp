#include <iostream>
#include <math.h>

double checkIfRightInput() 
{
    double input;
    if(std::cin >> input) 
    {
        return input;
    } 
    else 
    {
        throw(std::runtime_error("An error occurred: Malformed user input"));
    }
}

double discriminant(double a, double b, double c) 
{
    return pow(b, 2) - 4*a*c;
}

void quadraticFor(double a, double b, double c, double d) 
{
    if(d > 0) 
    {
        std::cout << "There are 2 solutions." << std::endl
        << "The solutions are: " << (-b + sqrt(pow(b, 2) - 4*a*c))/(2*a) << " and " << (-b - sqrt(pow(b, 2) - 4*a*c))/(2*a);
    } 
    else if(d == 0) 
    {
        std::cout << "There is 1 solution." << std::endl
        << "The solution is: " << -b/(2*a);
    } 
    else 
    {
        std::cout << "There is no solution.";
    }
}

int main() 
{
    double a;
    double b;
    double c;

    std::cout << "Please enter the values of a, b, and c: " << std::endl;

    try 
        {
            a = checkIfRightInput();
            if(a == 0) 
            {
                throw(std::runtime_error("An error occurred: a must not be zero"));
            }
            else
            {
                b = checkIfRightInput();
                c = checkIfRightInput();
            }
        } 
        catch(std::runtime_error& type) 
        {
            std::cout << type.what();
            return 0;
        }

    quadraticFor(a, b, c, discriminant(a, b, c));

    return 0;
}