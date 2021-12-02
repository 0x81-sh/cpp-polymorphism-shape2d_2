#pragma once

#include "CShape2D.h"
#include "CPoint2D.h"
#include <iostream>

class CRectangle : public CShape2D {
    private:
        CPoint2D bottomLeftCorner;
        float width;
        float height;

        void cornerCheck(const CPoint2D &a, int height, int width, std::string** cv) const;
    public:
        CRectangle(float x, float y, float width, float height, const CColor &col, int lt, bool isFilled);
        std::ostream& print(std::ostream &os) const override;
        void scale(float factor) override;
        float area() const override;
        void move(const CPoint2D &loc) override;
        void render(const CCanvas &ref) const override;

        const CPoint2D &getBottomLeftCorner() const;
        void setBottomLeftCorner(const CPoint2D &bottomLeftCorner);
        float getWidth() const;
        void setWidth(float width);
        float getHeight() const;
        void setHeight(float height);
};



