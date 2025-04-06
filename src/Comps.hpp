#pragma once

#include "raylib.h"
#include "raymath.h"
#include "typedefs.hpp"
#include "4becs.hpp"
#include "Gent.hpp"
#include "globals.hpp"
#include "Arena.hpp"


struct Hp : Comp {
    COMP;
    f64 maxhp;
    f64 hp;
    void takeDmg(f64 amount);
};