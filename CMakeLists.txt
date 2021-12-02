cmake_minimum_required(VERSION 3.21)
project(shape2d2)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall)

add_executable(shape2d2 main.cpp CCircle.cpp CCircle.h CColor.cpp CColor.h CPoint2D.cpp CPoint2D.h CShape2D.cpp CShape2D.h CRectangle.cpp CRectangle.h ICShapeRenderable.h CCanvas.cpp CCanvas.h StringConcat.h)
