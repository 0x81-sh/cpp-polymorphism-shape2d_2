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
        CRectangle(float x = 0, float y = 0, float width = 0, float height = 0, const CColor &col = {0, 0, 0}, int lt = 0, bool isFilled = false);
        std::ostream& print(std::ostream &os) const override;
        std::istream &read(std::istream &is) override;
        void scale(float factor) override;
        float area() const override;
        void move(const CPoint2D &loc) override;
        void render(CCanvas &ref) const override;

        const CPoint2D &getBottomLeftCorner() const;
        void setBottomLeftCorner(const CPoint2D &bottomLeftCorner);
        float getWidth() const;
        void setWidth(float width);
        float getHeight() const;
        void setHeight(float height);
};



