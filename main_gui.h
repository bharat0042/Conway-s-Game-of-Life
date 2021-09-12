#ifndef MAINGUI_H
#define MAINGUI_H

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <vector>

#include "game_of_life.h"

#pragma warning (disable : 4244)

class MainGui
{
private:
    using grid  = std::vector<std::vector<sf::RectangleShape>>;
    using arr2d = std::vector<std::vector<int>>;

    sf::RenderWindow m_Window;
    arr2d m_GridStatus;
    grid m_Grid;
    int m_Rows{100};
    int m_Cols{200};
    GameOfLife gol;
public:
    MainGui();
    void drawGrid(sf::RenderWindow& win);
    void initGrid();
};

#endif
