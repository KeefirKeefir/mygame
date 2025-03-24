#pragma once
#include "raylib.h"
#include "typedefs.hpp"
#include "bfECS.hpp"
#include "GEnt.hpp"
#include "globals.hpp"
#include "Click.hpp"

struct Button : GEnt {
    Rectangle shape;
    vec pos;
    vec dims;
    str Text;
    Color color;
    Color BaseColor;
    Color HoverCol;
    Color TextCol;
    Click<Button> click;
    
    Button(vec _pos, vec _dims, str _text, void (*fnEvent)(), Color _baseCol = LIGHTGRAY, Color _textCol = BLACK, Color _hoverCol = DARKGRAY);
    virtual ~Button();

    void onClick();
    void onHover();
    void onUnHover();

    void clickUpdate();

    void update() override;

    void draw() override;
};