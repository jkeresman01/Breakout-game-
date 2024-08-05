#pragma once

namespace breakout
{
class Paddle
{
  public:
    Paddle();

    float getHeight() const;
    float getWidth() const;

    void setHeight(float height);
    void setWidth(float width);

  private:
    float m_height;
    float m_width;
};

} // namespace breakout
