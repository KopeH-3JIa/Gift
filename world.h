#ifndef WORLD_H
#define WORLD_H

#include <string>
#include "system/system.hpp"

class World
{
public:
    World(const std::string &name = "main");
    ~World();

    inline std::string name() const noexcept;

    template<typename T>
    void createSystem() noexcept{
        T* s = new T{};
        s->initialize();
        _systems[getSystemTypeId<T>()] = s;
    }

    template<typename T, typename... Args>
    void createSystem(Args&& ...args) noexcept{
        T* s = new T{};
        s->initialize(args...);
        _systems[getSystemTypeId<T>()] = s;
    }

    template<typename T>
    bool hasSystem() const noexcept{
        return _systems.count(getSystemTypeId<T>()) != 0;
    }

    template<typename T>
    T*  system() noexcept{
        return reinterpret_cast<T*>(_systems.at(getSystemTypeId<T>()));
    }

private:
    std::string _name;
    SystemMap   _systems;


private:
    World(const World&) = delete;
    void operator =(const World&) = delete;
    World(const World&&) = delete;
    void operator =(const World&&) = delete;
};

inline std::string World::name() const noexcept{
    return _name;
}

#endif // WORLD_H
