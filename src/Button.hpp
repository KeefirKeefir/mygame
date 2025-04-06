#pragma once
#include "raylib.h"
#include "typedefs.hpp"
#include "4becs.hpp"
#include "Gent.hpp"
#include "globals.hpp"
#include "Click.hpp"
#include "Arena.hpp"

struct Button : Gent {
    Rectangle shape;
    vec pos;
    vec dims;
    str Text;
    Color color;
    Color BaseColor;
    Color HoverCol;
    Color TextCol;
    Click<Button> click {this};
    
    void init(vec _pos, vec _dims, str _text, void (*fnEvent)(), 
    Color _baseCol = LIGHTGRAY, Color _textCol = BLACK, Color _hoverCol = DARKGRAY);

    Button();
    virtual ~Button();

    void onClick();
    void onHover();
    void onUnHover();

    void clickUpdate();

    void update() override;

    void draw() override;


};