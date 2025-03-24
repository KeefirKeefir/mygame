#include "Button.hpp"

Button::Button(vec _pos, vec _dims, str _text, void (*fnEvent)(), 
               Color _baseCol, Color _textCol, Color _hoverCol)
    : pos(_pos), dims(_dims), Text(_text), BaseColor(_baseCol), TextCol(_textCol), HoverCol(_hoverCol), click(this) {
    color = BaseColor;
    click.event = fnEvent;
    shape = Rectangle{pos.x, pos.y, dims.x, dims.y};
}

void Button::onClick() {
    
}

void Button::onHover() {
    color = HoverCol;
}

void Button::onUnHover() {
    color = BaseColor;
}

void Button::clickUpdate() {
    click.update();
    if (click.hovered) {
        onHover();
        if (click.clicked) { onClick(); }
    }
    else { onUnHover(); }
}

void Button::update() {
    clickUpdate();
    shape.x = pos.x;
    shape.y = pos.y;
}

void Button::draw() {
    DrawRectangleRec(Rectangle{pos.x, pos.y, dims.x, dims.y}, color);
    DrawText(Text.c_str(), pos.x, pos.y, FontSizeM, TextCol);
}

Button::~Button() {
    // Destructor logic if necessary (e.g., cleanup)
}