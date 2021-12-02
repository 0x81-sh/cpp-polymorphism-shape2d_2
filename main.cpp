#include <iostream>
#include "CCircle.h"
#include "CRectangle.h"

using namespace std;

int main() {
    CCircle filledRedCir(10.0, 10.0, 7, CColor::RED, CShape2D::SOLID, true);
    CColor col(0, 100, 100);
    CCircle dashedCir(50.0, 50.0, 3, col, CShape2D::DASHED, false);

    CRectangle rec(10, 4, 5, 3, CColor::RED, CShape2D::SOLID, true);
    CRectangle rec2(15, 8, 10, 10, CColor::BLUE, CShape2D::SOLID, true);
    CRectangle rec3(18, 4, 10, 10, CColor::GREEN, CShape2D::SOLID, false);

    //cout << "Filled red solid: " << endl << filledRedCir << endl;
    //cout << "Unfilled cyan dashed: " << endl << dashedCir << endl;

    CCanvas c(20, 100);
    //rec.render(c);
    rec2.render(c);
    rec3.render(c);
    filledRedCir.render(c);

    c.render(std::cout);
}
