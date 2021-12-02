#include "CColor.h"

const CColor CColor::RED(255, 0, 0);
const CColor CColor::GREEN(0, 255, 0);
const CColor CColor::BLUE(0, 0, 255);
const CColor CColor::WHITE(255, 255, 255);
const CColor CColor::BLACK(0, 0, 0);

std::ostream &operator<<(std::ostream &os, const CColor &color) {
    os << "red: " << color.red << "; blue: " << color.blue << "; green: " << color.green << "; ";
    return os;
}

CColor::CColor(int r, int g, int b) : red(r), green(g), blue(b) {}

int CColor::getRed() const {
    return red;
}

void CColor::setRed(int red) {
    CColor::red = red;
}

int CColor::getGreen() const {
    return green;
}

void CColor::setGreen(int green) {
    CColor::green = green;
}

int CColor::getBlue() const {
    return blue;
}

void CColor::setBlue(int blue) {
    CColor::blue = blue;
}
