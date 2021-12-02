#pragma once

#include <ostream>

class CPoint2D {
    private:
        float x;
        float y;
    public:
        friend std::ostream &operator<<(std::ostream &os, const CPoint2D &d);
        CPoint2D(float x = 0, float y = 0);
        void add(const CPoint2D &vec);

        float getX() const;
        void setX(float x);
        float getY() const;
        void setY(float y);
};



