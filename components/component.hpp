#ifndef ___COMPONENT___
#define ___COMPONENT___


#include <map>

using ComponentId = std::size_t;
class Entity{};

struct BaseComponent{
    virtual ~BaseComponent(){}
    static inline ComponentId getUniqueId() noexcept{
        static ComponentId id{static_cast<ComponentId>(-1)};
        return ++id;
    }
};

template<typename T>
struct Component: public BaseComponent{
    Component(Entity *entity):entity(entity){}
    void initialize(){static_cast<T*>(this)->initialize();}
    static ComponentId id();
    Entity *entity;
};


template<typename T>
inline ComponentId getComponentTypeId() noexcept{
    static_assert(std::is_base_of<Component<T>,T>::value,"T must inherit from Component<T>");
    static ComponentId id = BaseComponent::getUniqueId();
    return id;
}

template<typename T>
ComponentId Component<T>::id(){return getComponentTypeId<T>();}


using ComponentMap = std::map<ComponentId, BaseComponent*>;

#endif // COMPONENT




