#include "Block.h"
#include "array"
#include "iostream"
#include "termios.h"
#include "unistd.h"
#include "random"

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
        moveBlocks(getKeyPress());
        spawnBlock();
        system("clear");
    }


    void moveBlocks(Direction dir)
    {
        for (int i = 0; i < Board.size(); ++i) {
            for (int j = 1; j < Board.size(); ++j) {
                bool moved;
                Block* a;
                Block* b;
                do {
                    moved = false;
                    for (int k = Board.size() - 1; k > 0; --k) {
                        if (dir == Direction::Right) {
                            a = &Board[i][k - 1];
                            b = &Board[i][k];
                        }
                        else if (dir == Direction::Left) {
                            a = &Board[i][k];
                            b = &Board[i][k - 1];
                        }
                        else if (dir == Direction::Up) {
                            a = &Board[k][i];
                            b = &Board[k - 1][i];
                        }
                        else if (dir == Direction::Down) {
                            a = &Board[k - 1][i];
                            b = &Board[k][i];
                        }


                        if (b->getValue() == 0 && a->getValue() != 0) {
                            b->setValue(a->getValue());
                            a->setValue(0);
                            moved = true;
                        }
                    }
                } while (moved);
            }
        }
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
    void spawnBlock()
    {
        static std::random_device rnd;
        static std::mt19937 mt(rnd());
        static std::uniform_int_distribution<int> distribution (0, Board.size() - 1);

        int x = distribution(mt);
        int y = distribution(mt);

        while (Board[y][x].getValue() != 0)
        {
            x = distribution(mt);
            y = distribution(mt);
        }

        Board[y][x] = Block(2);
    }
public:

    Game() { spawnBlock(); };
    Game(const Game&) = delete;
    Game (Game &&) = delete;


    void play()
    {
        while (true)
            update();
    }
};

int main()
{

    Game game;
    game.play();
    return 0;
}
