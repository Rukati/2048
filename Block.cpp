//
// Created by rukati on 21.02.2025.
//

#include "Block.h"
#include "iostream"
#include "string"
#include "math.h"

Block::Block(int value) {
    this->value = value;
    setColor();
}

void Block::print() {
    int size = std::to_string(value).size();

    std::cout << color;
    std::cout << std::string((10 - size) / 2, ' ');
    std::cout << value;
    std::cout << std::string(std::ceil(static_cast<float>(10 - size) / 2), ' ');
    std::cout << "\x1b[0m ";
}

void Block::setColor() {
    if (value == 0)
        color = "\x1b[47m";
    else if (value < 10)
        color = "\x1b[43m";
    else if (value < 60)
        color = "\x1b[44m";
    else if (value < 600)
        color = "\x1b[45m";
    else if (value < 1200)
        color = "\x1b[46m";
    else if (value < 5000)
        color = "\x1b[41m";
    else
        color = "\x1b[42m";
}

int Block::getValue() {
    return value;
}

void Block::setValue(int value) {
    this->value += value;
    setColor();
}

void Block::resetValue() {
    this->value = 0;
    setColor();
}
