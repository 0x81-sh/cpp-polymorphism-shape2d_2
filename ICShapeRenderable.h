#pragma once
#include "CCanvas.h"

const bool USE_COLOR = true;
const std::string COLOR_RESET = !USE_COLOR ? "" : "\x1b[0m";

class ICShapeRenderable {
    public:
        virtual ~ICShapeRenderable() {};
        virtual void render(CCanvas &ref) const = 0;
};



