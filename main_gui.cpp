#include "main_gui.h"

MainGui::MainGui()
{
    m_GridStatus = gol.getFirstGen();
    m_Window.create(sf::VideoMode(1220, 620, 32), "Conways Game of Life");
    m_Window.setFramerateLimit(60);
    initGrid();
    while (m_Window.isOpen())
    {
       sf::Event event;
       while (m_Window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               m_Window.close();
       }
       m_Window.clear();
       drawGrid(m_Window);
       m_Window.display();
       m_GridStatus = gol.getNextGen();
       //sf::sleep(sf::milliseconds(50));
    }
}


void MainGui::drawGrid(sf::RenderWindow& win)
{
    for(int i = 0; i < m_Rows; i++)
    {
        for(int j = 0; j < m_Cols; j++)
        {
            auto rect = m_Grid.at(i).at(j);
            if(m_GridStatus[i][j] == 1)
            {
                rect.setFillColor(sf::Color::Green);
            }
            win.draw(rect);
        }
    }
}

void MainGui::initGrid()
{
    for(int i = 0; i < m_Rows; i++)
    {
        std::vector<sf::RectangleShape> row;
        for(int j = 0; j < m_Cols; j++)
        {
            sf::RectangleShape rectangle{{6, 6}};
            rectangle.setFillColor(sf::Color::Red);
            rectangle.setPosition(6*j + 10, 6*i + 10);
            rectangle.setOutlineColor(sf::Color::White);
            rectangle.setOutlineThickness(-0.5);
            row.emplace_back(rectangle);
        }
        m_Grid.push_back(row);
    }
}
