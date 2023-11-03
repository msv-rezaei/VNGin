#ifndef TEXTURE_RENDERER_H
#define TEXTURE_RENDERER_H

#include <SDL2/SDL.h> 

#include "Module.h"
#include "Vector.h"

namespace VNGin {
    class TextureRenderer : public Module {
        friend class Game; 
        friend class Scene; 
        friend class Entity;
    public: 
        TextureRenderer(Entity* owner, const char* path, int sortingOrder = 0, Vector pivot = Vector::pivotCenter);
        TextureRenderer(const TextureRenderer&) = delete;
        TextureRenderer(TextureRenderer&&) = delete;

        int GetSortingOrder() { return sortingOrder; } 
        Vector GetTextureSize(void); 
        void SetSortingOrder(int sortingOrder);
        void SetFlip(bool flipX, bool flipY);

        void Show() { isVisible = true; }
        void Hide() { isVisible = false; }


        const char* GetType() { return "TextureRenderer"; }
    private: 
        void Render(SDL_Renderer* renderer);
        void ValidateSortingOrder(int& sortingOrder);

        void Update() {} 
        void Destroy(void);

        bool isVisible;
        SDL_Texture* texture;
        int sortingOrder;
        SDL_RendererFlip flip;
        Vector pivot;
    };
}


#endif