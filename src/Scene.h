#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"

#include <vector> 

namespace VNGin {
    class Scene {
        friend class Game;
    public:
        Scene(void);
        Scene(const Scene&) = delete;
        Scene(Scene&&) = delete;

        void AddEntity(Entity* entity);
        void RemoveEntity(Entity* entity);
    private: 
        void Update(void);
        std::vector<Entity*> entities;
    };
}

#endif