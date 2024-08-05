#include "headers/Paddle.h"

#include "headers/GameConstants.h"

namespace breakout
{
Paddle::Paddle()
{
    setHeight(paddle::HEIGHT);
}

float Paddle::getHeight() const
{
    return m_height;
}

float Paddle::getWidth() const
{
    return paddle::WIDTH;
}

void Paddle::setHeight(float height)
{
    m_height = height;
}
} // namespace breakout
