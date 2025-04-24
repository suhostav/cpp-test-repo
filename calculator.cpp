#include <cmath>
#include <iostream>

#include "calculator.h"

using namespace std::literals;

bool ReadNumber(Number& result){
    if (!(std::cin >> result)) {
        std::cerr << "Error: Numeric operand expected\n";
        return false;
    }
    return true;
}

Funcs CreateFuncs(){
    Funcs binary_opers{
        {"+"s, [](double a, double b){return a + b;}},
        {"-"s, [](double a, double b){return a - b;}},
        {"*"s, [](double a, double b){return a * b;}},
        {"/"s, [](double a, double b){return a / b;}},
        {"**"s, [](double a, double b){return std::pow(a,b);}},
        {":"s, [](double , double b){return b;}}};
        return binary_opers;
}

bool RunCalculatorCycle() {
    //операции
    Funcs binary_opers = CreateFuncs();
    // Число калькулятора.
    Number number;
    bool saved = false;
    Number mem = 0;
    std::string oper;
    
    if (!ReadNumber(number)) {
        return false;
    } else {
        while(std::cin >> oper){
            if(binary_opers.contains(oper)){
                Number number2;
                if (!ReadNumber(number2)) return false; 
                number = binary_opers[oper](number, number2);
            } else if(oper == "="s){
                std::cout << number << std::endl;
            } else if(oper == "q"s){
                break;
            } else if(oper == "c"s){
                number = 0.0;
            } else if(oper == "s"s){
                mem = number;
                saved = true;
            } else if(oper == "l"s){
                if(!saved){
                    std::cerr << "Error: Memory is empty\n";
                    return false;
                }
                number = mem;
            } else {
                std::cerr << "Error: Unknown token " << oper << std::endl;
                return false;
            }
        }
    }
    return true;
}
