#ifndef COLLISION_BOX_H
#define COLLISION_BOX_H

#include "Module.h"
#include "Vector.h"

#include <SDL2/SDL_rect.h>

namespace VNGin {
    class BoxCollider : public Module {
    public: 
        BoxCollider(Entity* owner, int width, int height, Vector pivot = Vector::pivotCenter);
        const char* GetType() { return "BoxCollider"; }
    private: 
        void Update(void);

        SDL_Rect rect;
        Vector pivot; 
    };
}

#endif