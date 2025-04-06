#pragma once


#include "raylib.h"
#include "globals.hpp"
#include "typedefs.hpp"
#include "string"
#include <cstdio>

namespace fps {
    i64 fps = 0;

    void calcFps() {
        if (delta <= 0.0) return;
        fps = (i64)(1.0 / delta);
    }

    void drawFps() {
        calcFps();
        DrawRectangle(0.0 , 0.0, 32, 19, DARKGRAY);
        DrawText(std::to_string(fps).c_str(), 3.0, 2.0, 16, GREEN);
    }
}