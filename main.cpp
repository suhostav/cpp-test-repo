#include <cassert>
#include <iostream>
#include "calculator.h"
#include "rational.h"
#include "tv_control.h"

int main() {
    TV tv;
    const TVControl control{tv};

    while (control.ReadAndApplyCommand()) {
    }

}
