#pragma once

#include <SFML/Graphics.hpp>

#include "Background.h"
#include "Ball.h"
#include "Brick.h"
#include "Paddle.h"

#include <list>

namespace breakout
{

class BreakoutGame
{
  public:
    BreakoutGame();
    void run();

  private:
    void processEvents();
    void update();
    void render();
    void reset();

    void renderBricks();

  private:
    sf::RenderWindow m_window;
    Paddle m_paddle;
    Ball m_ball;
    Background m_background;
    std::list<Brick> m_bricks;
};

} // namespace breakout
