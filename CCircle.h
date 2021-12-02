#pragma once

#include <ostream>
#include "CShape2D.h"
#include "CPoint2D.h"

class CCircle : public CShape2D  {
    private:
        CPoint2D center;
        float radius;
    public:
        CCircle(float x, float y, float radius, const CColor &col, int lt, bool isFilled);
        std::ostream& print(std::ostream &os) const override;
        void scale(float factor) override;
        float area() const override;
        void move(const CPoint2D &loc) override;
        void render(const CCanvas &ref) const override;

        const CPoint2D &getCenter() const;
        void setCenter(const CPoint2D &center);
        float getRadius() const;
        void setRadius(float radius);
};



