#include "Player.hpp"
#include <iostream>

Player::Player() : pos(Vector2Zero()), dims(Vector2Zero()), speed(0) {}

void Player::init() {
    pos = vec{400.0f, 200.0f};
    dims = vec{50.0f, 50.0f};
    speed = 500;
}

void Player::update() {
    checkMoveKeys();
    move();
}

void Player::draw() {
    DrawRectangleRec(Rectangle{pos.x, pos.y, dims.x, dims.y}, RED);
}

void Player::checkMoveKeys() {
    movdir = Vector2Zero();
    if (IsKeyDown(KEY_W)) {
        movdir.y -= 1.0f;
    }
    if (IsKeyDown(KEY_S)) {
        movdir.y += 1.0f;
    }
    if (IsKeyDown(KEY_A)) {
        movdir.x -= 1.0f;
    }
    if (IsKeyDown(KEY_D)) {
        movdir.x += 1.0f;
    }
    movdir = Vector2Normalize(movdir);
}

void Player::move() {
    pos.x += movdir.x * speed * delta;
    pos.y += movdir.y * speed * delta;
}