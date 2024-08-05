#pragma once

namespace breakout
{

namespace screen
{
constexpr float HEIGHT = 600.0f;
constexpr float WIDTH = 800.0f;
} // namespace screen

namespace paddle
{
constexpr float HEIGHT = 20.0f;
constexpr float WIDTH = 80.0f;

constexpr float SPEED = 2.0f;

constexpr float POSITION_X = 350.0f;
constexpr float POSITION_Y = 550.0f;

} // namespace paddle

namespace brick
{
constexpr float HEIGHT = 30.0f;
constexpr float WIDTH = 80.0f;

constexpr float SPACING_X = 10.0f;
constexpr float SPACING_Y = 5.0f;
} // namespace brick

namespace ball
{
constexpr float VELOCITY = 0.8;
constexpr float RADIUS = 10.0f;
} // namespace ball

} // namespace breakout
