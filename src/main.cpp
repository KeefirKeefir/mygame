#include "raylib.h"
#include "typedefs.hpp"
#include <chrono>
#include <thread>
#include "frameTimer.hpp"
#include "GEnt.hpp"
#include "globals.hpp"
#include "Button.hpp"
#include "EntArena.hpp"
#include <iostream>

using namespace std;

Color bgCol = SKYBLUE;
bool bgFlip = false;
void flipBgCol() {
    if (bgFlip == true) {
        bgCol = SKYBLUE;
    }
    else {
        bgCol = WHITE;
    }
    bgFlip = !bgFlip;
}

i32 main() {
    const i32 ScreenWidth = 800;
    const i32 ScreenHeight = 450;
    
    InitWindow(ScreenWidth, ScreenHeight, "mygame");

    addEnt(new Button(vec{350, 250}, vec{100, 50}, "YOOOO", &flipBgCol));
    addEnt(new Button(vec{200, 200}, vec{200, 30}, "second button", nullptr));
    addEnt(new Button(vec{500, 200}, vec{200, 150}, "3333 YO", nullptr));
    //auto prevTime = std::chrono::high_resolution_clock::now();
    FrameTimer frameTimer;
    f64 delta;
    while (!WindowShouldClose()) {
        frameTimer.start();
        updateEnts();

        BeginDrawing();

        ClearBackground(bgCol);

        drawEnts();

        EndDrawing();

        delta = frameTimer.stop(targetFps);
    }

    // de-init stuff
    // unload stuff

    CloseWindow();
}