#pragma once

#include <SFML/Graphics.hpp>

#include "Brick.h"
#include "Paddle.h"

#include <list>

namespace breakout
{

class Ball
{
  public:
    Ball();

    void update(Paddle &paddle, std::list<Brick> &bricks);
    void render(sf::RenderWindow &window);
    void reset();
    void start();

  private:
    sf::CircleShape m_ball;
    sf::Vector2f m_velocity;
};

} // namespace breakout
