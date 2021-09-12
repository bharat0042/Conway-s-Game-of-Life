#include "game_of_life.h"

GameOfLife::GameOfLife()
{
    auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    for(int i = 0; i < m_Rows; i++)
    {
        std::vector<int> row;
        for(int j = 0; j < m_Cols; j++)
        {
            row.push_back(gen());
        }
        m_grid.push_back(row);
    }
}

GameOfLife::arr2d GameOfLife::getFirstGen()
{
    return m_grid;
}

GameOfLife::arr2d GameOfLife::getNextGenCONSTSPACE()
{
    int u[] = { 1, -1, 0, 1, -1, 0, 1, -1 };
    int v[] = { 0, 0, -1, -1, -1, 1, 1, 1 };

    for (int i = 0; i < m_Rows; i++)
    {
        for (int j = 0; j < m_Cols; j++)
        {
            if (m_grid[i][j] > 0)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (save(m_grid, i + u[k], j + v[k]) && m_grid[i + u[k]][j + v[k]] > 0)
                    {
                        m_grid[i][j]++;
                    }
                }
            }
            else
            {
                for (int k = 0; k < 8; k++)
                {
                    if (save(m_grid, i + u[k], j + v[k]) && m_grid[i + u[k]][j + v[k]] > 0)
                    {
                        m_grid[i][j]--;
                    }
                }
            }
        }
   }

    for(int i = 0; i < m_Rows; i++)
    {
        for(int j = 0; j < m_Cols; j++)
        {
            if(m_grid[i][j] > 0)
            {
                if(m_grid[i][j] < 3)
                {
                    m_grid[i][j] = 0;
                }

                else if(m_grid[i][j] <= 4)
                {
                    m_grid[i][j] = 1;
                }

                else if(m_grid[i][j] > 4)
                {
                    m_grid[i][j] = 0;
                }
            }
           else
            {
                if (m_grid[i][j] == -3)
                {
                    m_grid[i][j] = 1;
                }
                 else
                {
                    m_grid[i][j] = 0;
                }
             }
         }
    }
    return m_grid;
}

bool GameOfLife::save(GameOfLife::arr2d m_grid,int row, int col)
{
    return (m_grid.size() > row && m_grid[0].size() > col && row >= 0 && col >= 0);
}

GameOfLife::arr2d GameOfLife::getNextGen()
{
    GameOfLife::arr2d original = m_grid;
    for (int row = 0; row < m_Rows; row++)
    {
        for (int col = 0; col < m_Cols; col++)
        {
            m_grid.at(row).at(col) = tick(original, row, col);
        }
    }
    return m_grid;
}

int GameOfLife::tick(GameOfLife::arr2d& board, int row, int col)
{
    int count = getCount(row, col, board);
    bool birth = !board.at(row).at(col) && count == 3;
    bool survive = board.at(row).at(col) && (count == 2 || count == 3);
    return birth || survive;
}

int GameOfLife::getCount(int row, int col, GameOfLife::arr2d& board)
{
    int count = 0;
    std::vector<int> deltas {-1, 0, 1};
    for (int dc : deltas) {
        for (int dr : deltas)
        {
            if (dr || dc)
            {
                count += getNeighbor(row + dr, col + dc, board);
            }
        }
    }
    return count;
}

int GameOfLife::getNeighbor(int row, int col, GameOfLife::arr2d& board)
{
    return board.at((row + m_Rows) % m_Rows).at((col + m_Cols) % m_Cols);
}
