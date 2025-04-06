#pragma once
#include <vector>
#include "Gent.hpp"
#include "typedefs.hpp"
using std::vector;


extern std::vector<Gent*> ents;

void addEnt(Gent* ent);
void drawEnts();
void updateEnts();
void freeEnts();

