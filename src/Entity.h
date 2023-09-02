#ifndef ENTITY_H
#define ENTITY_H

#include "Module.h"

#include <vector> 
#include <string> 

namespace VNGin {
    class Scene;
    class Entity {
        friend class Scene;
    public: 
        Entity(Scene* scene = nullptr, std::string name = "New Entity");
        Entity(const Entity&) = delete;
        Entity(Entity&&) = delete;
        ~Entity(void);

        template<typename T> 
        T* GetModule() {
            T* target;
            for(auto& m : modules) {
                if((target == dynamic_cast<T*>(m)) != nullptr) 
                    return target;
            }

            return nullptr;
        }

        template<typename T, typename ...Args> 
        T* AddModule(Args... args) {
            if(GetModule<T>() == nullptr) {
                T* newModule = new T(this, args...);
                modules.push_back(newModule);
                return newModule;
            }
        }
    private: 
        void UpdateModules(void);

        Scene* scene;
        std::string name;
        std::vector<Module*> modules;
    };
}

#endif