#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <map>

using SystemId = std::size_t;

struct BaseSystem{
    BaseSystem(){}
    virtual ~BaseSystem(){}
    static inline SystemId getUniqueId() noexcept{
        static SystemId id{static_cast<SystemId>(-1)};
        return ++id;
    }

private:
    BaseSystem(const BaseSystem&) = delete;
    void operator =(const BaseSystem&) = delete;
    BaseSystem(const BaseSystem&&) = delete;
    void operator =(const BaseSystem&&) = delete;
};

class World;

template<typename T>
struct System: public BaseSystem{
    void tick()         {static_cast<T*>(this)->tick();}
    static SystemId id();

};


template<typename T>
inline SystemId getSystemTypeId() noexcept{
    static_assert(std::is_base_of<System<T>,T>::value,"T must inherit from System<T>");
    static SystemId id = BaseSystem::getUniqueId();
    return id;
}

template<typename T>
SystemId System<T>::id(){return getSystemTypeId<T>();}


using SystemMap = std::map<SystemId, BaseSystem*>;


#endif // SYSTEM_HPP

