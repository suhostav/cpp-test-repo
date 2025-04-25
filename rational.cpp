#include "rational.h"

Rational Add(Rational r1, Rational r2){
    return Rational{
        r1.GetNumerator()*r2.GetDenominator() + r1.GetDenominator()*r2.GetNumerator(),
        r1.GetDenominator()*r2.GetDenominator()
    };
}

Rational Sub(Rational r1, Rational r2){
    return Rational{
        r1.GetNumerator()*r2.GetDenominator() - r1.GetDenominator()*r2.GetNumerator(),
        r1.GetDenominator()*r2.GetDenominator()
    };

}