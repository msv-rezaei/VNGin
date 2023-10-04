#ifndef SCENE_H
#define SCENE_H

#include "Entity.h"
#include "TextureRenderer.h"

#include <vector> 

namespace VNGin {
    class Game;
    class Scene {
        friend class Game;
        friend class TextureRenderer;
    public:
        Scene() {
            renderingMatrix = std::vector<std::vector<TextureRenderer*>>(10);
        }

        Scene(const Scene&) = delete;
        Scene(Scene&&) = delete;
        ~Scene();

        void AddEntity(Entity* entity);
        void RemoveEntity(Entity* entity);
    private: 
        void AddToRenderingMatrix(TextureRenderer* renderer); 
        void RemoveFromRenderingMatrix(TextureRenderer* renderer);

        void Update(SDL_Renderer* renderer);
        std::vector<Entity*> entities;
        std::vector<std::vector<TextureRenderer*>> renderingMatrix;
    };
}

#endif