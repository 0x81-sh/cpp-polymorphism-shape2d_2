#include "CRectangle.h"

CRectangle::CRectangle(float x, float y, float width, float height, const CColor &col, int lt, bool isFilled) :
    CShape2D(col, lt, isFilled), bottomLeftCorner(x, y), width(width), height(height) {}

std::ostream &CRectangle::print(std::ostream &os) const {
    return CShape2D::print(os);
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

void CRectangle::render(const CCanvas &ref) const {
    const CPoint2D &bottomLeft = bottomLeftCorner;
    const CPoint2D topRight(bottomLeft.getX() + width - 1, bottomLeft.getY() + height - 1);
    const CPoint2D topLeft(topRight.getX() - (topRight.getX() - bottomLeft.getX()), topRight.getY());
    const CPoint2D bottomRight(topRight.getX(), topRight.getY() - (topRight.getY() - bottomLeft.getY()));

    std::cout << topLeft << " | " << topRight << "\n" << bottomLeft << " | " << bottomRight << "\n";

    int x = bottomLeft.getX();
    int y = bottomLeft.getY();
    int w = width - 1;
    int h = height - 1;
    int width = ref.getWidth();
    int height = ref.getHeight();
    std::string** cv = ref.cv;

    //ported from old C code
    for (int i = 0; i < w; i++) {
        if (x < width - i && y < height && x >= -i && y >= 0) {
            cv[y][x + i] = colorString + CCanvas::horizontal + COLOR_RESET;
        }
        if (x < width - w + i && y < height - h && x >= i - w && y >= -h) {
            cv[y + h][x + w - i] = colorString + CCanvas::horizontal + COLOR_RESET;
        }
    }
    for (int i = 0; i < h; i++) {
        if (x < width - 1 && y < height - i && x >= 0 && y >= -i) {
            cv[y + i][x] = colorString + CCanvas::vertical + COLOR_RESET;
        }
        if (x < width - w - 1 && y < height + i - h && x >= - w && y >= i - h) {
            cv[y + h - i][x + w] = colorString + CCanvas::vertical + COLOR_RESET;
        }
    }
    if (isFilled) {
        for (int yL = 1; yL < h; yL++) {
            for (int xL = 1; xL < w; xL++) {
                if (x < width - xL && y < height - yL && xL >= 0 && yL >= 0) {
                    cv[y + yL][x + xL] = colorString + CCanvas::fill + COLOR_RESET;
                }
            }
        }
    }

    cornerCheck(bottomLeft, height, width, cv);
    cornerCheck(bottomRight, height, width, cv);
    cornerCheck(topLeft, height, width, cv);
    cornerCheck(topRight, height, width, cv);
}

void CRectangle::cornerCheck(const CPoint2D &a, int height, int width, std::string **cv) const {
    if (a.getX() < width - 1 && a.getY() < height && a.getY() >= 0 && a.getX() >= 0) {
        cv[(int) a.getY()][(int) a.getX()] = colorString + CCanvas::corner + COLOR_RESET;
    }
}
