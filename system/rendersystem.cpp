#include "rendersystem.h"
#include <iostream>
#include <thread>

#include "world.h"


RenderSystem::RenderSystem(){
    std::cout << "Render system created!" << std::endl;
}

RenderSystem::~RenderSystem(){
    std::cout << "Render system destroyed!" << std::endl;
}

void RenderSystem::initialize(World *world){
    this->world = world;
    std::cout << "Render system initialize in world " << world->name() << std::endl;
}




void RenderSystem::tick(){
    std::cout << "Render system tick! thread: " << std::this_thread::get_id() << std::endl;
}
