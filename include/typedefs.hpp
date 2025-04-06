#pragma once

#include <cstdint>
#include <cstdbool>
#include <vector>
#include <string>
#include "raylib.h"

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;


using f32 = float;
using f64 = double;

template <typename T>
using darr = std::vector<T>;

using str = std::string;

using vec = Vector2;

struct GridPos {
    u32 x;
    u32 y;
};

struct Circle {
    vec pos;
    f32 r;
};

struct Line {
    vec p1;
    vec p2;
};

struct Rect {
    vec pos;
    vec dims;
    Rectangle makeRect() {
        return Rectangle{pos.x, pos.y, dims.x, dims.y};
    }
};


enum Shapes {_point, _line, _circle, _rect};

struct Shape {
    Shapes type;
    union {
        vec point;
        Line line;
        Circle circle;
        Rect rect;
    };
};