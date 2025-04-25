#pragma once

#include <cstdlib>
#include <numeric>

class Rational {
public:
    Rational(int mumerator = 0, int denominator = 1)
        : numerator_(mumerator)
        , denominator_(denominator){
        if(denominator == 0) std::abort();
        to_normal();
    }
    int GetNumerator() const {return numerator_;}
    int GetDenominator() const {return denominator_;}
    double AsDouble() const { return static_cast<double>(numerator_) / static_cast<double>(denominator_); }
private:
    void to_normal(){
        int gcd = std::gcd(numerator_, denominator_);
        if(gcd != 1){
            numerator_ /= gcd;
            denominator_ /= gcd;
        }
        if(denominator_ < 0){
            numerator_ *= -1;
            denominator_ *= -1;
        }
    }
    int numerator_ = 0;   // Числитель дроби.
    int denominator_ = 1; // Знаменатель дроби.
};

// Функция сложения дробей.
// Возвращает обыкновенную дробь, равную сумме дробей r1 и r2.
Rational Add(Rational r1, Rational r2);

// Функция вычитания дробей.
// Возвращает обыкновенную дробь, равную разности дробей r1 и r2.
Rational Sub(Rational r1, Rational r2);