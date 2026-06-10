#include <iostream>


int main (){
    double num1, num2;
    char operation;

    std::cout << "Enter the first #: "; //First number ask
    std::cin >> num1;

    std::cout << "Enter the second#: "; //Second number ask
    std::cin >> num2;

    std::cout << "Choose an operation (+, -, *, /, %): "; //Operation ask
    std::cin >> operation;

    if (operation =='+') //Addition result
        std::cout << "Result: " << num1 + num2;
    else if (operation == '-') std::cout << "Result: " << num1 - num2; //Subtraction result
    else if (operation == '*') std::cout << "Result: " << num1 * num2; //Multiplcation result
    else if (operation == '/') { //Division result no remainder
        if (num2 == 0 || num1 == 0) std::cout << "You cannot divide by zero, silly!";
        else std::cout << "Result: " << num1 / num2;
    }
    else if (operation == '%') std::cout << "Result: " << (int)num1 % (int)num2; //Module result with remainder
        else std::cout << "Invalid operation";

    return 0;
}