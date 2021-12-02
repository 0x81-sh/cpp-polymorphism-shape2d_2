#include "CShape2D.h"

int CShape2D::SOLID = 0;
int CShape2D::DASHED = 1;
int CShape2D::DOTTED = 2;

CShape2D::CShape2D(const CColor &col, int lType, bool isFilled) :
    isFilled(isFilled), color (col), lineType(lType) {
    std::stringstream ss;
    ss << "\x1b[38;2;" << color.getRed() << ";" << color.getGreen() << ";" << color.getBlue() << "m";
    colorString = !USE_COLOR ? "" : ss.str();
}

std::ostream &operator<<(std::ostream &os, const CShape2D &d) {
    return d.print(os);
}

bool CShape2D::getIsFilled() const {
    return isFilled;
}

void CShape2D::setIsFilled(bool isFilled) {
    CShape2D::isFilled = isFilled;
}

const CColor &CShape2D::getColor() const {
    return color;
}

void CShape2D::setColor(const CColor &color) {
    CShape2D::color = color;
}

int CShape2D::getLineType() const {
    return lineType;
}

void CShape2D::setLineType(int lineType) {
    CShape2D::lineType = lineType;
}

std::ostream &CShape2D::print(std::ostream &os) const {
    os << "isFilled: " << isFilled << "; color: [" << color << "]; lineType: ";
    switch (lineType) {
        case 0:
            os << "SOLID";
            break;
        case 1:
            os << "DASHED";
            break;
        case 2:
            os << "DOTTED";
            break;
        default:
            os << "INVALID";
            break;
    }
    os << "; ";

    return os;
}
