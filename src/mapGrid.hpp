#pragma once

#include "4becs.hpp"
#include "typedefs.hpp"
#include "globals.hpp"
#include "raylib.h"
#include "Gent.hpp"
#include <cmath>

using std::vector;

struct Gent;

// Gent::updateGridPos is based on GRIDCELL_SIZE, make sure to update both when changing one
#define GRIDCELL_SIZE 128
#define GRID_SIZE 64

// min coords are (0, 0), max coords are (MapSize, Mapsize)
constexpr f32 MapSize = (GRIDCELL_SIZE * GRID_SIZE) - 1;

const u32 Gridcell_Pwr = static_cast<u32>(std::log2(GRIDCELL_SIZE));

extern vector<Gent*> grid[GRID_SIZE][GRID_SIZE];

// TODO:
// track reusable indeces of the Gent* vector with a stack

namespace Grid {
    u64 add(Gent* gent, u32 x, u32 y);

    void remove(u32 x, u32 y, u64 idx);

    GridPos calcGridPos(const vec& pos);
}