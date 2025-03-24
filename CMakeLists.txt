cmake_minimum_required(VERSION 3.10)
project(mygame)

# Set C++20 and add compile flags
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1 -Wall")

# Specify include and lib directories
include_directories(${CMAKE_SOURCE_DIR}/include)
link_directories(${CMAKE_SOURCE_DIR}/lib)

file(GLOB SOURCES "src/*.cpp")

# Create the executable from source files
add_executable(mygame ${SOURCES})

# Link raylib and Windows-specific libraries (for Windows builds)
if(WIN32)
    target_link_libraries(mygame raylib opengl32 gdi32 winmm)
else()
    # For non-Windows systems, adjust as necessary (e.g., Linux might need -lm -lpthread, etc.)
    target_link_libraries(mygame raylib)
endif()
