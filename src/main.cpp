#include "raylib.h"
#include "typedefs.hpp"
#include <chrono>
#include <thread>
#include "frameTimer.hpp"
#include "Gent.hpp"
#include "globals.hpp"
#include "Button.hpp"
#include "Arena.hpp"
#include <iostream>
#include "raymath.h"
#include "Player.hpp"
#include "FpsCounter.hpp"
#include "Raycast.hpp"

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

/*     addEnt(new Button(vec{350, 250}, vec{100, 50}, "YOOOO", &flipBgCol));
    addEnt(new Button(vec{200, 200}, vec{200, 30}, "second button", nullptr));
    addEnt(new Button(vec{500, 200}, vec{200, 150}, "3333 YO", nullptr));
    addEnt(new Player()); */

    Arena<Player>* players = new Arena<Player>(1);
    players->add()->init();

    Arena<Button>* buttons = new Arena<Button>(2);
    buttons->add()->init(vec{350, 250}, vec{100, 50}, "YOOOO", &flipBgCol);
    buttons->add()->init(vec{200, 200}, vec{200, 30}, "second button", nullptr);
    buttons->add()->init(vec{500, 200}, vec{200, 150}, "3333 YO", nullptr);

    Arena<Raycast>* rays = new Arena<Raycast>(4);
    rays->add()->init(vec{0.0f, 0.0f}, vec{200.0f, 200.0f});

    FrameTimer frameTimer;
    while (!WindowShouldClose()) {
        frameTimer.start();

        players->updateAll();
        buttons->updateAll();
        rays->updateAll();

        BeginDrawing();
        
            ClearBackground(bgCol);

            players->drawAll();
            buttons->drawAll();
            rays->drawAll();

            fps::drawFps();
        EndDrawing();

        delta = frameTimer.stop(targetFps);
    }

    // de-init stuff
    // unload stuff

    CloseWindow();
}