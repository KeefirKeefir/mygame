#pragma once

#include <chrono>
#include <thread>
#include "typedefs.hpp"
using namespace std;
using namespace chrono;

struct FrameTimer {
    high_resolution_clock::time_point startTime;
    void start() { startTime = high_resolution_clock::now(); }

    f64 stop(const f64 &targetFps) {
        auto endTime = high_resolution_clock::now();
        auto frameTime = endTime - startTime;
        auto targetFrameTime = duration<f64>(1.0 / targetFps);
        auto remainingTime = targetFrameTime - frameTime;
        f64 delta = 1 / targetFps;
        if (remainingTime > duration<f64>(0.0)) {
            this_thread::sleep_for(remainingTime);
        }
        else {
            delta = duration<f64>(frameTime).count();
        }   
        return delta;
    }
}; 