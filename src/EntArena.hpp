#pragma once
#include <vector>
#include "GEnt.hpp"
using std::vector;


extern std::vector<GEnt*> ents;

void addEnt(GEnt* ent);
void drawEnts();
void updateEnts();
void freeEnts();