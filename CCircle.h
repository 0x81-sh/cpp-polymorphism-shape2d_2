#pragma once

#include <ostream>
#include "CShape2D.h"
#include "CPoint2D.h"

class CCircle : public CShape2D  {
    private:
        CPoint2D center;
        float radius;
    public:
        CCircle(float x = 0, float y = 0, float radius = 0, const CColor &col = {0, 0, 0}, int lt = 0, bool isFilled = false);
        std::ostream& print(std::ostream &os) const override;
        std::istream& read(std::istream &is) override;
        void scale(float factor) override;
        float area() const override;
        void move(const CPoint2D &loc) override;
        void render(CCanvas &ref) const override;

        const CPoint2D &getCenter() const;
        void setCenter(const CPoint2D &center);
        float getRadius() const;
        void setRadius(float radius);
};



