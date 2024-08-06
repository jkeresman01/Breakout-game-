#pragma once

#include <SFML/Graphics.hpp>

namespace breakout
{

class Paddle
{
  public:
    Paddle();

    void processInput();
    void update();
    void render(sf::RenderWindow &window);

    sf::FloatRect getBounds() const;

  private:
    void moveLeft();
    void moveRight();

  private:
    sf::RectangleShape m_paddle;
    float m_speed;
};

} // namespace breakout
