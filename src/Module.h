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
        virtual void Start(void) = 0;
        virtual void Update(void) = 0;

        Entity* owner;
    };
}

#endif