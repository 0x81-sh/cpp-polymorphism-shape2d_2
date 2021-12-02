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
    int r = radius;
    int cX = center.getX();
    int cY = center.getY();
    double ratio = 6/3;
    int width = ref.getWidth();
    int height = ref.getHeight();
    std::string **cv = ref.cv;

    for (int x = floor(cX - r * ratio); x < ceil(cX + r * ratio); x++) {
        for (int y = cY - r; y < cY + r; y++) {
            if (x < width - 1 && y < height && x >= 0 && y >= 0) {
                double dist = sqrt(pow((cX - x) / ratio, 2) + pow(cY - y, 2));
                if (dist < r - 1 / ratio && r - 1 <= dist) {
                    cv[y][x] = colorString + CCanvas::circleOut + COLOR_RESET;
                }
            }
        }
    }

    //center
    if (cX < width - 1 && cY < height && cX >= 0 && cY >= 0) {
        cv[cY][cX] = colorString + CCanvas::circleCenter + COLOR_RESET;
    }
}
