#include <iostream>
#include "core/application.h"
#include "world.h"
#include "components/component.hpp"


struct Position: public Component<Position>{};
struct Heal: public Component<Heal>{};
struct Move: public Component<Move>{};


struct MoveSystem: public System<MoveSystem>{
    MoveSystem(){
        std::cout << "Move system created!" << std::endl;
    }

    void initialize(const World &world){
        std::cout << "Move system initialize in world " << world.name() << std::endl;
    }

    void tick(){
        std::cout << "Move system tick!" << std::endl;
    }

    ~MoveSystem(){
        std::cout << "Move system destroyed!" << std::endl;
    }
};

int main(int argc, char **argv){
    Application &a = Application::instance();
    a.setArguments({argv, argv + argc});


    World world;

    world.createSystem<MoveSystem>(world);


    world.system<MoveSystem>().tick();

    return a.run();
}
