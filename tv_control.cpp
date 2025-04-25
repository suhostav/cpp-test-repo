#include "tv_control.h"

#include <iostream>
#include <string>

using namespace std::literals;

// Определите здесь конструктор класса со списком инициализации.

bool TVControl::ReadAndApplyCommand() const {
    std::string action;
    if (!(std::cin >> action)) {
        std::cout << "Invalid command"s << std::endl;
        return false;
    }

    // Реализуйте обработку оставшихся команд.
    if (action == "Exit"s) {
        return false;
    } else if (action == "Info"s) {
        Info();
    } else if (action == "TurnOn"s) {
        TurnOn();
    } else if (action == "TurnOff"s) {
        TurnOff();
    } else if (action == "SelectChannel"s) {
        int channel;
        std::cin >> channel;
        SelectChannel(channel);
    } else {
        std::cout << "Unknown command"s << std::endl;
    }
    return true;
}

void TVControl::Info() const {
    if (!tv_.IsTurnedOn()) {
        std::cout << "TV is turned off"s << std::endl;
        return;
    }
    std::cout << "TV is turned on. Channel is "s << tv_.GetCurrentChannel() << std::endl;
}

void TVControl::TurnOn() const{
    tv_.TurnOn();
    std::cout << "TV is turned off\n";
}
void TVControl::TurnOff() const{
    tv_.TurnOff();
    std::cout << "Turning on\n";
}
void TVControl::SelectChannel(int N) const{
    if(!tv_.IsTurnedOn()){
        std::cout << "TV is not turned on\n";
        return;
    }
    if(tv_.SelectChannel(N)){
        std::cout << "Channel selected\n";
    } else {
        std::cout << "Invalid channel\n";
    }
}