#pragma once

#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "typedefs.hpp"
#include "4becs.hpp"
#include "Gent.hpp"
#include "globals.hpp"
#include "Arena.hpp"


struct Player : Gent {
    vec pos;
    vec dims;
    vec movdir;
    f32 speed;


    Player();
    void init();

    void update() override;
    void draw() override;

    void checkMoveKeys();
    void move();
};

