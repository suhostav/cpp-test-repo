#pragma once

class TV {
public:
    inline static const int MIN_CHANNEL = 1;
    inline static const int MAX_CHANNEL = 99;

    // Включает телевизор.
    void TurnOn();

    // Выключает телевизор.
    void TurnOff();

    // Возвращает true, если телевизор включён, и
    // false, если телевизор выключен.
    bool IsTurnedOn() const;

    // Возвращает номер текущего канала
    // либо 0, если телевизор выключен.
    // Телевизор при выключении запоминает номер текущего канала,
    // а при включении — восстанавливает его.
    // При первом включении телевизор показывает канал №1.
    int GetCurrentChannel() const;

    // Выбирает канал с указанным номером. Номер канала
    // должен быть в диапазоне [1..99].
    // Если указан недопустимый номер канала
    // либо телевизор выключен, возвращает false и не меняет
    // текущий канал. В противном случае возвращает true.
    bool SelectChannel(int channel);

private:
    bool is_turned_on_ = false;
    int current_channel_ = 1;
};