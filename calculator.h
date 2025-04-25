#pragma once
#include <cmath>
#include <functional>
#include <map>
#include <string>

using Number = double;
using Func = std::function<double(double, double)>;
using Funcs = std::map<std::string, Func>;

class Calculator{
public:
    void Set(Number number){number_ = number;}
    Number GetNumber() const { return number_;}
    void Add(Number n) {number_ += n;}
    void Sub(Number n) {number_ -= n;}
    void Mul(Number n) {number_ *= n;}
    void Div(Number n) {number_ /= n;}
    void Pow(Number n) {std::pow(number_, n);}
    void Save() {mem_ = number_; has_mem_ = true;}
    void Load() {number_ = mem_;}
    bool HasMem() const { return has_mem_;}
    std::string GetNumberRepr() const { return std::to_string(number_);}
private:
    Number number_ = 0;
    Number mem_ = 0;
    bool has_mem_ = false;
};

bool ReadNumber(Number& result);
bool RunCalculatorCycle(); 