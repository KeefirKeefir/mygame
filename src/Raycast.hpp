#pragma once

#include "typedefs.hpp"
#include "raylib.h"
#include "raymath.h"
#include "mapGrid.hpp"
#include "hitboxes.hpp"
#include "globals.hpp"

struct Raycast : Gent {
    vec p1;
    vec p2;
    vec dir;
    f32 length;

    Color color = PINK;
    f32 thickness = 10.0;

    std::vector<GridPos> gridCells;

    Line makeLine();

    void init(vec origin, vec end);
    void init(vec origin, vec direction, f32 _length);

    void calcGridcells();

    bool check(CircleHB& circle);
    bool check(RectHB& rect);

    void checkCollisions();

    void GentUpdate() override;
    void update() override;
    void draw() override;

    ~Raycast();
};

