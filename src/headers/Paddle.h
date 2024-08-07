#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

namespace breakout
{

class Paddle
{
  public:
    Paddle();

    void update();
    void render(sf::RenderWindow &window);

    void moveLeft();
    void moveRight();

    void setPosition(float positionX, float positionY);

    sf::FloatRect getBounds() const;
    sf::Vector2f getPosition() const;

  private:
    sf::RectangleShape m_paddle;
    float m_speed;
};

} // namespace breakout
