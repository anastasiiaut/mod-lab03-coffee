// Copyright 2024 <anastasiiaut>
#include <iostream>
#include "Automata.h"

int main() {
setlocale(LC_ALL, "Russian");
Automata CoffeMachine;
CoffeMachine.on();
CoffeMachine.getMenu();
int input;
std::cout << "Введите сумму (в рублях): ";
std::cin >> input;
CoffeMachine.coin(input);

std::cout << "Выберите напиток из меню (введите номер): ";
std::cin >> input;
CoffeMachine.choice(input);

std::cout << std::endl;

std::cout << "Введите сумму (в рублях): ";
std::cin >> input;
CoffeMachine.coin(input);

std::cout << "Выберите напиток из меню (введите номер): ";
std::cin >> input;
CoffeMachine.choice(input);

std::cout << std::endl;

CoffeMachine.cancel();
std::cout << CoffeMachine.getState() << std::endl;
CoffeMachine.off();
return 0;
}
