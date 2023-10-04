#ifndef TEXTURE_RENDERER_H
#define TEXTURE_RENDERER_H

#include <SDL2/SDL.h> 

#include "Module.h"
#include "Vector.h"

namespace VNGin {
    class TextureRenderer : public Module {
        friend class Game; 
        friend class Scene; 
    public: 
        TextureRenderer(Entity* owner, SDL_Texture* texture, int sortingOrder = 0, Vector pivot = pivotCenter);
        TextureRenderer(const TextureRenderer&) = delete;
        TextureRenderer(TextureRenderer&&) = delete;

        int GetSortingOrder() { return sortingOrder; } 
        void SetSortingOrder(int sortingOrder);
        void SetFlip(bool flipX, bool flipY);

        void Show() { isVisible = true; }
        void Hide() { isVisible = false; }


        const char* GetType() { return "TextureRenderer"; }

        const static Vector pivotUpLeft;    
        const static Vector pivotUp;    
        const static Vector pivotUpRight;    
        const static Vector pivotLeft;    
        const static Vector pivotCenter;    
        const static Vector pivotRight;    
        const static Vector pivotDownLeft;    
        const static Vector pivotDown;    
        const static Vector pivotDownRight; 
    private: 
        void Render(SDL_Renderer* renderer);
        void ValidateSortingOrder(int& sortingOrder);

        void Start() {} 
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