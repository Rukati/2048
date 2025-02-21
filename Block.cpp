//
// Created by rukati on 21.02.2025.
//

#include "Block.h"
#include "iostream"
#include "string"

Block::Block(int value) {
    this->value = value;
    setColor();
}

void Block::print() {
    int size = std::to_string(value).size();
    std::cout << color;
    std::cout << std::string(7 - size, ' ') << value << std::string(7 - size, ' ');
    std::cout << "\x1b[0m ";
}

void Block::setColor() {
    if (value == 0)
        color = "\x1b[47m\0";
    else if (value < 10)
        color = "\x1b[43m\0";
    else if (value < 100)
        color = "\x1b[44m\0";
    else if (value < 600)
        color = "\x1b[45m\0";
    else if (value < 1200)
        color = "\x1b[46m\0";
    else if (value < 5000)
        color = "\x1b[41m\0";
    else
        color = "\x1b[42m\0";
}
