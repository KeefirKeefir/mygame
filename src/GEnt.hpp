#pragma once
#include "4becs.hpp"
#include "typedefs.hpp"
#include "globals.hpp"
#include "Arena.hpp"
#include "mapGrid.hpp"

template <typename T> struct SubArena;


struct Gent : Ent {
    u64 id;
    vec pos{0, 0};
    //Shapes shapeType;

    GridPos gridPos;
    u64 gridIdx;
    Shape shape;
    vec dimensions;
    bool visible = true;
    bool process = true;
    bool toFree = false;
    // custom constructor
    //virtual void make() = 0;
    SubArena<Gent>* owner;

    void processAdjacents();

    void updateGridPos();
    // base updates
    virtual void GentUpdate();

    virtual void update() = 0;
    virtual void draw() = 0;

    void queueFree();

        //arena->markItemFree(this, toFree);
    Gent();
    virtual ~Gent() = default;
        //markFree();
};