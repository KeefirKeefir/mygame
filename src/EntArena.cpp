#include "EntArena.hpp"

vector<GEnt*> ents;

void addEnt(GEnt* ent) {
    ents.push_back(ent);
}

void drawEnts() {
    for ( auto& ent : ents) {
        if (ent) {
            ent->draw();
        }
    }
}
void updateEnts() {
    for ( auto& ent : ents) {
        if (ent) {
            ent->update();
        }
    }
}
void freeEnts() {
    for ( auto& ent : ents) {
        if (ent) {
            delete ent;
        }
    }
}