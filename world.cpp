#include "world.h"
#include <iostream>

using namespace std;

World::World(const string &name):
    _name(name){
    cout << "World " << this->name() << " created!"   << endl;
}


World::~World(){
    for(auto &s : _systems)
        delete s.second;
    cout << "World " << this->name() << " destroyed!" << endl;
}

