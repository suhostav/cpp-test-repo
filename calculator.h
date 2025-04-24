#pragma once
#include <functional>
#include <map>
#include <string>

using Number = double;
using Func = std::function<double(double, double)>;
using Funcs = std::map<std::string, Func>;

bool ReadNumber(Number& result);
bool RunCalculatorCycle(); 