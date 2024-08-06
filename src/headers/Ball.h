#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Brick.h"
#include "Paddle.h"

#include <filesystem>
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
    void loadSound(const std::filesystem::path &path);

  private:
    sf::CircleShape m_ball;
    sf::Vector2f m_velocity;
    sf::SoundBuffer m_soundBuffer;
    sf::Sound m_brickHitSoundEffect;
};

} // namespace breakout
