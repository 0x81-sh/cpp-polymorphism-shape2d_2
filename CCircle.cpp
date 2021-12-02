#include "CCircle.h"
#include <cmath>

CCircle::CCircle(float x, float y, float radius, const CColor &col, int lt, bool isFilled) :
    CShape2D(col, lt, isFilled), center(x, y), radius(radius) {}

const CPoint2D &CCircle::getCenter() const {
    return center;
}

void CCircle::setCenter(const CPoint2D &center) {
    CCircle::center = center;
}

float CCircle::getRadius() const {
    return radius;
}

void CCircle::setRadius(float radius) {
    CCircle::radius = radius;
}

std::ostream &CCircle::print(std::ostream &os) const {
    CShape2D::print(os);
    os << "center: [" << center << "]; radius: " << radius << "; ";

    return os;
}

void CCircle::scale(float factor) {
    radius *= factor;
}

void CCircle::move(const CPoint2D &loc) {
    center.add(loc);
}

float CCircle::area() const {
    return pow(radius, 2) * M_PI;
}

void CCircle::render(const CCanvas &ref) const {

}
