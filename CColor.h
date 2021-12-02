#pragma once

#include <ostream>

class CColor {
    private:
        int red;
        int green;
        int blue;
    public:
        CColor(int r = 0, int g = 0, int b = 0);
        friend std::ostream &operator<<(std::ostream &os, const CColor &color);

        int getRed() const;
        void setRed(int red);
        int getGreen() const;
        void setGreen(int green);
        int getBlue() const;
        void setBlue(int blue);

        const static CColor RED;
        const static CColor GREEN;
        const static CColor BLUE;
        const static CColor BLACK;
        const static CColor WHITE;
};

