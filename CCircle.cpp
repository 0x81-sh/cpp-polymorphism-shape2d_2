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

void CCircle::render(CCanvas &ref) const {
    int r = radius;
    int cX = center.getX();
    int cY = center.getY();
    double ratio = 6/3;
    int width = ref.getWidth();
    int height = ref.getHeight();
    std::string **cv = ref.cv;

    std::string stroke = colorString + CCanvas::circleOut + COLOR_RESET;
    std::string fill = colorString + CCanvas::fill + COLOR_RESET;

    for (int x = 0; x < r * ratio / M_SQRT2; x++) {
        int y = (int)round(sqrt(pow(r, 2) - pow(x / ratio, 2)));
        ref.writeChecked(cX - x, cY - y, stroke);
        ref.writeChecked(cX - x, cY + y, stroke);
        ref.writeChecked(cX + x, cY - y, stroke);
        ref.writeChecked(cX + x, cY + y, stroke);
        if (!isFilled) continue;
        while (y-- > 0) {
            ref.writeChecked(cX - x, cY - y, fill);
            ref.writeChecked(cX - x, cY + y, fill);
            ref.writeChecked(cX + x, cY - y, fill);
            ref.writeChecked(cX + x, cY + y, fill);
        }
    }

    for (int y = 0; y < r / M_SQRT2; y++) {
        int x = ratio * (int)round(sqrt(pow(r, 2) - pow(y, 2)));
        ref.writeChecked(cX - x, cY - y, stroke);
        ref.writeChecked(cX - x, cY + y, stroke);
        ref.writeChecked(cX + x, cY - y, stroke);
        ref.writeChecked(cX + x, cY + y, stroke);
        if (!isFilled) continue;
        while (x-- > 0) {
            ref.writeChecked(cX - x, cY - y, fill);
            ref.writeChecked(cX - x, cY + y, fill);
            ref.writeChecked(cX + x, cY - y, fill);
            ref.writeChecked(cX + x, cY + y, fill);
        }
    }

    //center
    if (cX < width - 1 && cY < height && cX >= 0 && cY >= 0) {
        cv[cY][cX] = colorString + CCanvas::circleCenter + COLOR_RESET;
    }
}

std::istream &CCircle::read(std::istream &is) {
     CShape2D::read(is);

     std::cout << "Radius: ";
     std::cin >> radius;

     std::cout << "Center point:\n";
     std::cin >> center;

     return is;
}
