#pragma once

#include <SFML/Graphics.hpp>

namespace breakout
{

class Brick
{
  public:
    Brick(float positionX, float positionY);

    void render(sf::RenderWindow &window);
    sf::FloatRect getBounds() const;

  private:
    sf::RectangleShape m_brick;
};

} // namespace breakout
