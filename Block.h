//
// Created by rukati on 21.02.2025.
//

#ifndef INC_2048_BLOCK_H
#define INC_2048_BLOCK_H

#include "string"

enum class Direction {
    Up, Down, Left, Right
};

class Block {
    int value;
    std::string color;
    void setColor();
public:
    explicit Block(int value = 0);

    Block(const Block&) = delete;
    int getValue();
    void setValue(int value);
    void print();
};


#endif //INC_2048_BLOCK_H
