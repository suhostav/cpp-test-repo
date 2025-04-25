#pragma once
#include "tv.h"

class TVControl {
public:
    TVControl(TV& tv): tv_(tv){}
    // Метод ReadAndApplyCommand больше не статический.
    bool ReadAndApplyCommand() const;

private:
    // Объявите здесь поле класса (ссылку на телевизор).
    TV& tv_;
private:
    // Приватные методы класса не должны быть статическими и не должны принимать ссылку на tv.*/
    void Info() const;
    void TurnOn() const;
    void TurnOff() const;
    void SelectChannel(int N) const;
};