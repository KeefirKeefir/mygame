#include "mapGrid.hpp"

using std::vector;

#define GRIDCELL_SIZE 128
#define GRID_SIZE 64

// min coords are (0, 0), max coords are (MapSize, Mapsize)
// constexpr f32 MapSize = (GRIDCELL_SIZE * GRID_SIZE) - 1; // in the header

extern vector<Gent*> grid[GRID_SIZE][GRID_SIZE];

vector<Gent*> grid[GRID_SIZE][GRID_SIZE] = {};

// TODO:
// track reusable indeces of the Gent* vector with a stack

namespace Grid {
    u64 add(Gent* gent, u32 x, u32 y) {
        grid[x][y].push_back(gent);
        return grid[x][y].size() - 1;
    }

    void remove(u32 x, u32 y, u64 idx) {
        grid[x][y][idx] = nullptr;
    }

    GridPos calcGridPos(const vec& pos) {
        u32 x = static_cast<u32>(pos.x) >> Gridcell_Pwr;
        u32 y = static_cast<u32>(pos.y) >> Gridcell_Pwr;
        return GridPos{x, y};
    }
}