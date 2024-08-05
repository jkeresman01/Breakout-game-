#pragma once

namespace breakout
{

namespace screen
{
constexpr float HEIGHT = 720.0f;
constexpr float WIDTH = 1280.0f;
} // namespace screen

namespace paddle
{
constexpr float HEIGHT = 20.0f;
constexpr float WIDTH = 100.0f;

constexpr float SPEED = 2.0f;

constexpr float POSITION_X = screen::HEIGHT - 10.0f;
constexpr float POSITION_Y = screen::HEIGHT - 50.0f;

} // namespace paddle

namespace brick
{
constexpr float START_POSTION_X = 10.0f;
constexpr float START_POSTION_Y = 10.0f;

constexpr float HEIGHT = 12.0f;
constexpr float WIDTH = 53.0f;

constexpr float SPACING_X = 10.0f;
constexpr float SPACING_Y = 5.0f;
} // namespace brick

namespace ball
{
constexpr float VELOCITY = 0.8;
constexpr float RADIUS = 10.0f;
} // namespace ball

namespace background
{
constexpr float SCALE_X = 0.3;
constexpr float SCALE_Y = 0.3;
} // namespace background

} // namespace breakout
