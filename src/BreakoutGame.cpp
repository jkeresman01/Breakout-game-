#include "headers/BreakoutGame.h"

#include "headers/GameConstants.h"

namespace breakout
{

BreakoutGame::BreakoutGame()
    : m_window(sf::VideoMode(screen::WIDTH, screen::HEIGHT), "Breakout BreakoutGame"), m_paddle(),
      m_ball(), m_background()

{
    reset();
}

void BreakoutGame::run()
{
    while (m_window.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void BreakoutGame::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }
}

void BreakoutGame::update()
{
    m_paddle.update();
    m_ball.update(m_paddle, m_bricks);
}

void BreakoutGame::render()
{
    m_window.clear(sf::Color(13, 12, 3));
    m_background.render(m_window);
    m_paddle.render(m_window);
    m_ball.render(m_window);
    renderBricks();
    m_window.display();
}

void BreakoutGame::renderBricks()
{
    std::for_each(m_bricks.begin(), m_bricks.end(), [this](Brick &b) { b.render(m_window); });
}

void BreakoutGame::reset()
{
    m_bricks.clear();

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            float positionX = brick::START_POSTION_X + j * (brick::WIDTH + brick::SPACING_X);
            float positionY = brick::START_POSTION_Y + i * (brick::HEIGHT + brick::SPACING_Y);

            m_bricks.emplace_back(positionX, positionY);
        }
    }

    m_ball.reset();
}

} // namespace breakout
