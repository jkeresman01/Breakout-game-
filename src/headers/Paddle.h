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

        private:
            float m_height;
    };

}

