#include "arena.hpp"

vector<Gent*> ents;

void addEnt(Gent* ent) {
    ents.push_back(ent);
}

void drawEnts() {
    for ( auto& ent : ents) {
        if (ent && ent->visible) {
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