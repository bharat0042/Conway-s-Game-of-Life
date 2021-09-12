#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <vector>
#include <random>
#include <functional>

class GameOfLife
{
private:
    using arr2d = std::vector<std::vector<int>>;

    arr2d m_grid;
    int m_Rows{100};
    int m_Cols{200};
public:
    GameOfLife();
    arr2d getFirstGen();
    arr2d getNextGenCONSTSPACE();
    bool save(GameOfLife::arr2d grid,int row, int col);
    arr2d getNextGen();
    int tick(GameOfLife::arr2d& board, int row, int col);
    int getCount(int row, int col, GameOfLife::arr2d& board);
    int getNeighbor(int row, int col, GameOfLife::arr2d& board);

};

#endif
