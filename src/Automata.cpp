// Copyright 2024 <anastasiiaut>
#include <iostream>
#include "Automata.h"

Automata::Automata() {
    cash = 0;
    state = OFF;
    menu = {
    "Матча",
    "Американо",
    "Раф",
    "Латте",
    "Какао",
    "Капучино",
    "Экспрессо" };
    prices = { 100, 110, 210, 136, 150, 125, 100 };
}
Automata::~Automata() {
}
void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Кофейный аппарат готов к работе" << std::endl;
    } else {
        std::cout << "Кофейный аппарат включен" << std::endl;
    }
}
void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "Кофейный аппарат выключен" << std::endl;
    } else {
        std::cout << "Кофейный аппарат нельзя включить" << std::endl;
    }
}
void Automata::getMenu() {
    if (state == WAIT || state == ACCEPT) {
        for (int i = 0; i < menu.size(); i++) {
            std::cout << i + 1 << ") " << menu[i]
                << " - " << prices[i] << ";" << std::endl;
        }
    } else {
        std::cout << "Данная операция невозможна" << std::endl;
    }
}
void Automata::coin(int money) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += money;
        std::cout << "Внесенная сумма: " << cash << std::endl;
    } else {
        std::cout << "Данная операция невозможна" << std::endl;
    }
}
STATES Automata::getState() {
    return state;
}
void Automata::choice(int choice) {
    if (state == ACCEPT) {
        if (choice < 1 || choice > menu.size()) {
            std::cout << "Неверный номер" << std::endl;
        } else {
            state = CHECK;
            if (check(choice)) {
                cook(choice);
            }
        }
    } else {
        std::cout << "Данная операция невозможна" << std::endl;
    }
}
bool Automata::check(int choice) {
    if (cash >= prices[choice - 1]) {
        return true;
    }
    std::cout << "Внесенной суммы недостаточно" << std::endl;
    state = ACCEPT;
    return false;
}
void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        state = WAIT;
        cash = 0;
        std::cout << "Отменить" << std::endl;
    } else {
        std::cout << "Данная операция невозможна" << std::endl;
    }
}
void Automata::cook(int choice) {
    if (state == CHECK) {
        state = COOK;
        cash -= prices[choice - 1];
        std::cout << "Ваш напиток уже готовится. Ожидайте" << std::endl;
        finish(choice);
    } else {
        std::cout << "Данная операция невозможна" << std::endl;
    }
}
void Automata::finish(int choice) {
    if (state == COOK) {
        std::cout << "Сдача: " << cash << std::endl;
        std::cout << "Ваш напиток готов, вы можете его забрать" << std::endl;
        cash = 0;
        state = WAIT;
    } else {
        std::cout << "Данная операция невозможна" << std::endl;
    }
}
