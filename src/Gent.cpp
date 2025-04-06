#include "Gent.hpp"
#include "mapGrid.hpp"

u64 generateGentId() {
    static u64 id = 0;
    return id++;
}

Gent::Gent() {
    id = generateGentId();
}

void Gent::updateGridPos() {
    gridPos = Grid::calcGridPos(pos);
    gridIdx = Grid::add(this, gridPos.x, gridPos.y);
}

void Gent::processAdjacents() {
    for (const auto& offset : offsets) {
        i32 nx = gridPos.x + offset[0];
        i32 ny = gridPos.y + offset[1];
        if (nx < 0 || ny < 0 || nx >= GRID_SIZE || ny >= GRID_SIZE) {
            continue;
        }

        for (Gent* gent : grid[nx][ny]) {
            if ((gent == this) || !gent) continue;

            // CHECK COLLISIONS HERE
        }
    }
}

void Gent::GentUpdate() {
    if (!process) return;
    updateGridPos();
    processAdjacents();
}

void Gent::queueFree() {
    toFree = true;
    Grid::remove(gridPos.x, gridPos.y, gridIdx);
    if (owner) {
        owner->markItemFree(this);
    }
}