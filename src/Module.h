#ifndef MODULE_H
#define MODULE_H

namespace VNGin {
    class Entity;
    class Module {
        friend class Entity;
    public: 
        virtual const char* GetType(void) = 0;
    protected: 
        Module(Entity* owner = nullptr) : owner{owner} {} 
        virtual void Update() {}
        virtual void Destroy() {}

        Entity* owner;
    };
}

#endif