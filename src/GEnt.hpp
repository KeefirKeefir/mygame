#pragma once
#include "bfECS.hpp"
#include "typedefs.hpp"

// GENT capitalised for ease of writing
struct GEnt : Ent{
    vec pos;
    vec dims;
    virtual void update() = 0;
    virtual void draw() = 0;
};