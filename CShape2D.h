#pragma once

#include <ostream>
#include <sstream>
#include <iostream>
#include "CColor.h"
#include "CPoint2D.h"
#include "ICShapeRenderable.h"

class CShape2D : public ICShapeRenderable {
    protected:
        bool isFilled;
        CColor color;
        int lineType;
        std::string colorString;

        void recalculateColor();
    public:
        static int SOLID;
        static int DASHED;
        static int DOTTED;

        CShape2D(const CColor &col, int lType, bool isFilled);
        friend std::ostream& operator<<(std::ostream &os, const CShape2D &d);
        friend std::istream& operator>>(std::istream &is, CShape2D &d);
        virtual std::ostream& print(std::ostream &os) const;
        virtual std::istream& read(std::istream &is);
        virtual void scale(float factor) = 0;
        virtual void move(const CPoint2D &loc) = 0;
        virtual float area() const = 0;

        bool getIsFilled() const;
        void setIsFilled(bool isFilled);
        const CColor &getColor() const;
        void setColor(const CColor &color);
        int getLineType() const;
        void setLineType(int lineType);
};
