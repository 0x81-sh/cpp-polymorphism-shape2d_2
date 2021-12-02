#include "CCanvas.h"

const char CCanvas::vertical = '|';
const char CCanvas::horizontal = '-';
const char CCanvas::corner = '+';
const char CCanvas::blank = ' ';
const char CCanvas::border = '~';
const char CCanvas::circleCenter = 'X';
const char CCanvas::circleOut = '*';
const char CCanvas::fill = '#';

int CCanvas::getHeight() const {
    return height;
}

int CCanvas::getWidth() const {
    return width;
}

CCanvas::CCanvas(int height, int width) : height(height), width(width) {
    cv = new std::string*[height];
    for (int i = 0; i < height; i++) {
        cv[i] = new std::string[width];

        for (int j = 0; j < width; j++) {
            cv[i][j] = CCanvas::blank;
        }
    }
}

CCanvas::~CCanvas() {
    for (int i = 0; i < height; i++) {
        delete[] cv[i];
    }
    delete[] cv;
}

void CCanvas::render(std::ostream &out) const {
    for (int y = 0; y < height; y++) {
        out << CCanvas::border;

        for (int x = 0; x < width; x++) {
            out << cv[y][x];
        }

        out << CCanvas::border << '\n';
    }

    out << std::endl;
}

void CCanvas::clear() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cv[y][x] = CCanvas::blank;
        }
    }
}

