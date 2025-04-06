#pragma once

template <typename T>
struct relt {
    T some;
    bool none;
    const char* const err;

    relt(T val) : some(val), none(false), err(nullptr) {}
    relt(const char* e) : some{}, none(true), err(e) {}
};