#pragma once
#include <ostream>

class CCanvas {
    private:
        int height;
        int width;
    public:
        std::string** cv;
        const static char vertical;
        const static char horizontal;
        const static char corner;
        const static char blank;
        const static char border;
        const static char circleCenter;
        const static char circleOut;
        const static char fill;

        CCanvas(int height, int width);
        ~CCanvas();
        void render(std::ostream &out) const;
        void clear();

        int getHeight() const;
        int getWidth() const;
};



