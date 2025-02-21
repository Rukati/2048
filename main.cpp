#include "Block.h"
#include "array"
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstdio>

// 2048
class Game {
    std::array<std::array<Block, 4>, 4> Board;

    Direction getKeyPress() {
        struct termios oldt, newt;
        char ch;
        while (true) {
            tcgetattr(STDIN_FILENO, &oldt);
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);

            ch = getchar();

            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

            switch (ch) {
                case 'w':
                    return Direction::Up;
                case 's':
                    return Direction::Down;
                case 'a':
                    return Direction::Left;
                case 'd':
                    return Direction::Right;
            }
        }
    }

    void update()
    {
        printBoard();
    }

    void printBoard()
    {
        for (int i = 0; i < Board.size(); ++i) {
            for (int j = 0; j < Board.size(); ++j) {
                Board[i][j].print();
            }
            std::cout << std::endl;
            std::cout << std::endl;
        }
    }
public:

    Game() = default;
    Game(const Game&) = delete;
    Game (Game &&) = delete;


    void play()
    {
            update();
    }
};

int main()
{

    Game game;
    game.play();
    return 0;
}
