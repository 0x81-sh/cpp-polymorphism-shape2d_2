#pragma once

#include "CShape2D.h"
#include <iostream>
#include <limits>
#include "CCircle.h"
#include "CRectangle.h"

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #defiine CLEAR "clear"
#endif

class CLI {
    private:
        CShape2D **storage;
        CCanvas canvas;
        int size;
        void expandStorage();

        void uiSwitch();
        void mainMenu();
        template <typename T> void addShape();
        void scale();
        void move();
        void list();
        void totalArea();
        CShape2D* grabFromIO();
        void clear();
        void unit_tests();
        char mod_getchar();
        void mod_flush();

        //don't allow copying / assigning
        CLI(const CShape2D &ref);
        CShape2D& operator=(const CShape2D &ref);
    public:
        CLI();
        ~CLI();

        void start();
};



