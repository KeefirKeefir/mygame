#pragma once
#include "typedefs.hpp"

extern i32 FontSizeS;    // Declaration only
extern i32 FontSizeM;
extern i32 FontSizeL;
extern i32 FontSizeXL;

extern u16 targetFps;

extern f64 delta;

const int offsets[9][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    { 0, -1}, { 0, 0}, { 0, 1},
    { 1, -1}, { 1, 0}, { 1, 1}
};