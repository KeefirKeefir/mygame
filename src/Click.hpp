#pragma once

#include "bfECS.hpp"
#include "GEnt.hpp"
#include "raylib.h"

template <typename T>
struct Click : Comp {
    T* owner;

    void (*event)();

    bool hovered;
    bool clicked;

    Click(T* _owner);

    void update();

    void hover();
    void unhover();

    bool checkMouseHover(Rectangle &shape);

    void checkMouse();
};


template <typename T>
Click<T>::Click(T* _owner) : owner(_owner), hovered(false), clicked(false), event(nullptr) {
    //assert(owner->shape);
};

template <typename T>
void Click<T>::update() {
    checkMouse();
}

template <typename T>
void Click<T>::hover() {
    hovered = true;
}
template <typename T>
void Click<T>::unhover() {
    hovered = false;
}

template <typename T>
bool Click<T>::checkMouseHover(Rectangle &shape) {
    return CheckCollisionPointRec(GetMousePosition(), shape);
}

template <typename T>
void Click<T>::checkMouse() {
    if (!checkMouseHover(owner->shape)) {
        unhover();
        return;
    }
    hover();
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (event) {
            event();
        }
    }
}