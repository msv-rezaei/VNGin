#include "Game.h"
#include "TextureRenderer.h"
#include "Scene.h"
#include "Entity.h"

VNGin::TextureRenderer::TextureRenderer(Entity* owner, const char* path, int sortingOrder, Vector pivot)
    : Module(owner), isVisible{true}, texture{Game::LoadTexture(path)}, pivot{pivot}, flip{SDL_FLIP_NONE} {
    ValidateSortingOrder(sortingOrder); 
    this->sortingOrder = sortingOrder;
    owner->GetScene()->AddToRenderingMatrix(this);
}

VNGin::Vector VNGin::TextureRenderer::GetTextureSize() {
    int w, h;  
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    w *= owner->transform->GetScale().x; 
    h *= owner->transform->GetScale().y;
    return Vector(w, h);
}

void VNGin::TextureRenderer::SetSortingOrder(int sortingOrder) {
    ValidateSortingOrder(sortingOrder);

    owner->GetScene()->RemoveFromRenderingMatrix(this); 
    this->sortingOrder = sortingOrder; 
    owner->GetScene()->AddToRenderingMatrix(this);
}

void VNGin::TextureRenderer::ValidateSortingOrder(int& sortingOrder) {
    if(sortingOrder < 0 || sortingOrder > 9) {
        SDL_Log("Sorting order must be in (0..10) range, value will be changed to nearest valid value."); 
        if(sortingOrder < 0) sortingOrder = 0; 
        else sortingOrder = 9;
    }
}

void VNGin::TextureRenderer::SetFlip(bool flipX, bool flipY) {
    if(flipX && flipY) 
        flip = static_cast<SDL_RendererFlip>(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
    else if(flipX) 
        flip = SDL_FLIP_HORIZONTAL; 
    else if(flipY) 
        flip = SDL_FLIP_VERTICAL; 
    else 
        flip = SDL_FLIP_NONE;
}

void VNGin::TextureRenderer::Render(SDL_Renderer* renderer) {
    SDL_Rect dest;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
    dest.w *= owner->transform->GetScale().x;
    dest.h *= owner->transform->GetScale().y;
    dest.x = owner->transform->GetPosition().x - (pivot.x * dest.w); 
    dest.y = owner->transform->GetPosition().y - (pivot.y * dest.h);

    SDL_RenderCopyEx(renderer, texture, NULL, &dest, owner->transform->GetRotation(), NULL, flip);
}

void VNGin::TextureRenderer::Destroy() {
    owner->GetScene()->RemoveFromRenderingMatrix(this);
    owner->RemoveModule<TextureRenderer>();
    SDL_DestroyTexture(texture);
}