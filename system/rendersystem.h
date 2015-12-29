#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H
#include "system/system.hpp"

class World;

class RenderSystem : public System<RenderSystem>
{
public:
    RenderSystem();
    ~RenderSystem();


    void tick();


    void initialize(World *world);

private:
    World *world;
};

#endif // RENDERSYSTEM_H
