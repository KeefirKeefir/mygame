#pragma once

#include <vector>
#include <cstdlib>
#include "Gent.hpp"
#include "typedefs.hpp"
#include <iostream>
using std::cout;
using std::vector;

template <typename T> struct ArenaStack;
template <typename T> struct SubArena;
template <typename T> struct Arena;

struct Gent;

// holds reusable arenas
// increases in size if needed, but doesn't decrease
template <typename T>
struct ArenaStack {
    vector<SubArena<T>*> stack;
    u64 stackptr = 0;
    ArenaStack() {
        // inital size must be 2 or higher for the growth factor to affect it
        stack.resize(2);
    }
    void push(SubArena<T>* arena) {
        if (stack.size() <= stackptr) {
            stack.resize(static_cast<size_t>(stack.size() * 1.618));
        }
        stack[stackptr] = arena;
        stackptr ++;
    }
    SubArena<T>* pop() {
        if (stackptr == 0) return nullptr;
        stackptr--;
        SubArena<T>* temp = stack[stackptr];
        stack[stackptr] = nullptr;
        return temp;
    }
};

// the actual arenas
// buffer capacity is defined at runtime through Arena(cap)
template <typename T>
struct SubArena {
    T* buffer;
    // index where new items will be assigned
    u64 counter;
    // maximum number of items
    const u64 Capacity;
    // current number of items, equal to counter
    u64 length;
    // the owner/creator of this subarena
    Arena<T>* owner;
    // decrements when an item tells this subarena that its queued to free
    // once this reaches 0, the arena becomes reusable
    u64 itemCount;

    void free_items() {
        for (u64 i = 0; i < length; i++) {
            Gent* item = static_cast<Gent*>((T*)buffer + i);
            item->~Gent();
        }
        markReusable();
    }

    void updateAll() {
        for (u64 i = 0; i < length; i++) {
            Gent* item = static_cast<Gent*>((T*)buffer + i);
            item->update();

        }
    }
    void drawAll() {
        for (u64 i = 0; i < length; i++) {
            Gent* item = static_cast<Gent*>((T*)buffer + i);
            item->draw();
        }
    }
    // a Gent will call this when it is all but freed
    // Gent has a function which calls this, markFree(), a Gent inheritor's destructor should include markFree()
    // marks the arena as reusable if every item is queued to be freed
    void markItemFree(T* item) {
        if (!item) return;
        itemCount--;
        if (itemCount == 0) {
            free_items();
        }
    }
    // tells the main Arena that this subarena is free to be reused
    void markReusable() {
        // for standalone subArena use
        if (!owner || (owner->currentSubArena != this)) {
            return;
        }
        counter = 0;
        length = 0;
        itemCount = Capacity;
        owner->arenaStack.push(this);
    }

    SubArena(u64 cap, Arena<T>* _owner) : counter(0), Capacity(cap), owner(_owner), itemCount(Capacity) {
            buffer = reinterpret_cast<T*>((T*)malloc(sizeof(T) * Capacity)); 
        }
    
    ~SubArena() {
        free_items();
        free(buffer);
    }
};


// manages arenas of one type
// create it when you need arenas which will dynamically expand
// note that the lower the ItemsPerArena, the higher will memory fragmentation be
// delete Arena() to free all of its and its arenas' contents
template <typename T>
struct Arena {
    // all of the subarenas
    vector<SubArena<T>*> subArenas;
    const u64 ItemsPerArena; 
    // the subarena currently taking new items through add()
    SubArena<T>* currentSubArena;
    // stack of reusable arenas
    ArenaStack<T> arenaStack;

    void updateAll() {
        for (SubArena<T>* subArena : subArenas) {
            subArena->updateAll();
        }
    }
    void drawAll() {
        for (SubArena<T>* subArena : subArenas) {
            subArena->drawAll();
        }
    }

    Arena(u64 _itemsPerArena) : ItemsPerArena(_itemsPerArena) {
        currentSubArena = nullptr;
    }
    // frees all contents
    ~Arena() {
        release();
    }
    // frees all contents
    void release() {
        for ( SubArena<T>* subArena : subArenas) delete subArena;
    }
    // takes in a type and constructor arguments
    // adds to the currently used arena
    T* add() {
        if (!currentSubArena) {
            currentSubArena = update_CurrentArena();
        }
        else if (currentSubArena->Capacity <= currentSubArena->length) {
            currentSubArena = update_CurrentArena();
        }
        T* temp = new (((T*)currentSubArena->buffer) + currentSubArena->counter) T();
        currentSubArena->counter++;
        currentSubArena->length = currentSubArena->counter;
        return temp;
    }
    // finds or creates a usable arena
    // DO NOT CALL THIS FROM THE CONSTRUCTOR
    SubArena<T>* update_CurrentArena() {
        if (arenaStack.stackptr > 0) return arenaStack.pop();
        else return expand();
    }

    // creates a new arena
    SubArena<T>* expand() {
        SubArena<T>* newSubArena = new SubArena<T>(ItemsPerArena, this);
        subArenas.push_back(newSubArena);
        return newSubArena;
    }
};