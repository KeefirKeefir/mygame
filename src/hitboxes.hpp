#pragma once

#include "4becs.hpp"
#include "raylib.h"
#include "Gent.hpp"
#include "typedefs.hpp"
#include "raymath.h"

struct RectHB;
struct CircleHB;

/* struct CollInfo {
    vec normal;
}; */

bool checkCollisionRectHBLine(RectHB& rect, const Line& line);

struct CircleHB : Comp {
    COMP;
    vec pos;
    f32 r;
    vec offset;
    
    bool check(CircleHB& circle);
    bool check(RectHB& rect);
    bool check(const Line& line);
    bool check(vec& point);
};

struct RectHB : Comp {
    COMP;
    vec pos;
    vec dims;
    vec offset;

    Rectangle makeRect();

    bool check(CircleHB& circle);
    bool check(RectHB& rect);
    bool check(const Line& line);
    bool check(vec& point);
};