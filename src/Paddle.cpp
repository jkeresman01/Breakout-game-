#include "headers/Paddle.h"

#include "headers/GameConstants.h"
#include "headers/Logger.h"

namespace breakout
{

Paddle::Paddle()
{
    setHeight(paddle::HEIGHT);
    setWidth(paddle::WIDTH);
}

float Paddle::getHeight() const
{
    return m_height;
}

float Paddle::getWidth() const
{
    return m_width;
}

void Paddle::setHeight(float height)
{
    if (height < 0)
    {
        LOG_ERROR("Failed to set height, height can't be negative number!");
        return;
    }

    m_height = height;
}

void Paddle::setWidth(float width)
{
    if (width < 0)
    {
        LOG_ERROR("Failed to set width, width can't be negative number!");
        return;
    }

    m_width = width;
}

} // namespace breakout
