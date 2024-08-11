#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <filesystem>

namespace breakout
{

class Background
{
  public:
    Background();

    void render(sf::RenderWindow &window) const;

  private:
    void setTexture(const std::filesystem::path &filepath);

  private:
    sf::Texture m_texture;
    sf::Sprite m_background;
};

} // namespace breakout
