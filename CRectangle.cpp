#include "CRectangle.h"

CRectangle::CRectangle(float x, float y, float width, float height, const CColor &col, int lt, bool isFilled) :
    CShape2D(col, lt, isFilled), bottomLeftCorner(x, y), width(width), height(height) {}

std::ostream &CRectangle::print(std::ostream &os) const {
    CShape2D::print(os);
    std::cout << "bottomLeftCorner: [" << bottomLeftCorner << "]; width: " << width << "; height: " << height << "; ";

    return os;
}

const CPoint2D &CRectangle::getBottomLeftCorner() const {
    return bottomLeftCorner;
}

void CRectangle::setBottomLeftCorner(const CPoint2D &bottomLeftCorner) {
    CRectangle::bottomLeftCorner = bottomLeftCorner;
}

float CRectangle::getWidth() const {
    return width;
}

void CRectangle::setWidth(float width) {
    CRectangle::width = width;
}

float CRectangle::getHeight() const {
    return height;
}

void CRectangle::setHeight(float height) {
    CRectangle::height = height;
}

void CRectangle::scale(float factor) {
    height *= factor;
    width *= factor;
}

void CRectangle::move(const CPoint2D &loc) {
    bottomLeftCorner.add(loc);
}

float CRectangle::area() const {
    return width * height;
}

void CRectangle::render(CCanvas &ref) const {
    const CPoint2D &bottomLeft = bottomLeftCorner;
    const CPoint2D topRight(bottomLeft.getX() + width - 1, bottomLeft.getY() + height - 1);
    const CPoint2D topLeft(topRight.getX() - (topRight.getX() - bottomLeft.getX()), topRight.getY());
    const CPoint2D bottomRight(topRight.getX(), topRight.getY() - (topRight.getY() - bottomLeft.getY()));

    int x = bottomLeft.getX();
    int y = bottomLeft.getY();
    int w = width - 1;
    int h = height - 1;

    for (int i = 0; i < w; i++) {
        ref.writeChecked(x + i, y, colorString + CCanvas::horizontal + COLOR_RESET);
        ref.writeChecked(x + w - i, y + h, colorString + CCanvas::horizontal + COLOR_RESET);
    }
    for (int i = 0; i < h; i++) {
        ref.writeChecked(x, y + i, colorString + CCanvas::vertical + COLOR_RESET);
        ref.writeChecked(x + w, y + h - i, colorString + CCanvas::vertical + COLOR_RESET);
    }
    if (isFilled) {
        for (int yL = 1; yL < h; yL++) {
            for (int xL = 1; xL < w; xL++) {
                ref.writeChecked(x + xL, y + yL, colorString + CCanvas::fill + COLOR_RESET);
            }
        }
    }

    ref.writeChecked(bottomLeft.getX(), bottomLeft.getY(), colorString + CCanvas::corner + COLOR_RESET);
    ref.writeChecked(bottomRight.getX(), bottomRight.getY(), colorString + CCanvas::corner + COLOR_RESET);
    ref.writeChecked(topLeft.getX(), topLeft.getY(), colorString + CCanvas::corner + COLOR_RESET);
    ref.writeChecked(topRight.getX(), topRight.getY(), colorString + CCanvas::corner + COLOR_RESET);
}

std::istream &CRectangle::read(std::istream &is) {
    CShape2D::read(is);

    std::cout << "Bottom left corner:\n";
    std::cin >> bottomLeftCorner;

    std::cout << "Width: ";
    std::cin >> width;

    std::cout << "Height: ";
    std::cin >> height;

    return is;
}
