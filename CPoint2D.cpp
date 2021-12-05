#include "CPoint2D.h"

CPoint2D::CPoint2D(float x, float y) : x(x), y(y) {}

std::ostream &operator<<(std::ostream &os, const CPoint2D &d) {
    os << "x: " << d.x << "; y: " << d.y << "; ";
    return os;
}

float CPoint2D::getX() const {
    return x;
}

void CPoint2D::setX(float x) {
    CPoint2D::x = x;
}

float CPoint2D::getY() const {
    return y;
}

void CPoint2D::setY(float y) {
    CPoint2D::y = y;
}

void CPoint2D::add(const CPoint2D &vec) {
    y += vec.y;
    x += vec.x;
}

std::istream &operator>>(std::istream &is, CPoint2D &d) {
    std::cout << "X: ";
    std::cin >> d.x;

    std::cout << "Y: ";
    std::cin >> d.y;

    return is;
}
