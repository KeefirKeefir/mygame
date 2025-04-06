#include "Raycast.hpp"



void Raycast::calcGridcells() {

    f32 stepSize = 32;
    vec stepVec = Vector2Normalize(vec{p2.x - p1.x, p2.y - p1.y}) * stepSize;

    f32 fullDistance = Vector2Distance(p1, p2);
    f32 distance = 0.0;

    vec prevPos = p1;
    vec currPos = p1;

    gridCells.clear();
    gridCells.push_back(Grid::calcGridPos(p1));

    if (Vector2Equals(p1, p2)) {
        //return GridCells;
        return;
    }
    //gridCells.push_back(Grid::calcGridPos(p2));

    while (true) {
        prevPos = currPos;
        currPos = Vector2Add(currPos, stepVec);
        distance += stepSize;

        GridPos prevGridPos = Grid::calcGridPos(prevPos);
        GridPos currGridPos = Grid::calcGridPos(currPos);

        if (prevGridPos.x == currGridPos.x && prevGridPos.y == currGridPos.y) {
            continue;
        }
        
        gridCells.push_back(GridPos{currGridPos.x, currGridPos.y});

        if (distance >= fullDistance) {
            break;
        }
    }
    GridPos p2GridPos = Grid::calcGridPos(p2);
    if (gridCells.back().x != p2GridPos.x && gridCells.back().y != p2GridPos.y) {
        gridCells.push_back(p2GridPos);
    }
}

Line Raycast::makeLine() {
    return Line{p1, p2};
}

bool Raycast::check(CircleHB& circle) {
    if (circle.check(makeLine())) {

    }
}

bool Raycast::check(RectHB& rect) {
    if (rect.check(makeLine())) {

    }
}

void Raycast::init(vec origin, vec end) {
    p1 = origin;
    p2 = end;
    dir = Vector2Normalize(Vector2Subtract(p2, p1));
    length = Vector2Distance(p1, p2);
}

void Raycast::init(vec origin, vec direction,  f32 _length) {
    p1 = origin;
    length = _length;
    dir = Vector2Normalize(direction);
    p2 = Vector2Add(p1, Vector2Scale(dir, length));
}

void Raycast::checkCollisions() {
    for (auto& _gridPos : gridCells) {
        for (Gent* gent : grid[_gridPos.x][_gridPos.y]) {
            if (auto* circle = get<CircleHB>(gent)) {
                if (circle->check(makeLine())) {

                }
            }
            else if (auto* rect = get<RectHB>(gent)) {
                if (rect->check(makeLine())) {

                }
            }
        }
    }
}

void Raycast::GentUpdate() {
    if (!process) return;
}
void Raycast::update() {
    if (!process) return;
}
void Raycast::draw() {
    if (!visible) return;
    DrawLineEx(p1, p2, thickness, color);
    //DrawCircle(p2.x, p2.y, 50, color);
}

Raycast::~Raycast() = default;