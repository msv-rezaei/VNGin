#include "TextureRenderer.h"
#include "Scene.h"
#include "Entity.h"

VNGin::TextureRenderer::TextureRenderer(Entity* owner, SDL_Texture* texture, int sortingOrder, Vector pivot)
    : Module(owner), isVisible{true}, texture{texture}, pivot{pivot}, flip{SDL_FLIP_NONE} {
    ValidateSortingOrder(sortingOrder); 
    this->sortingOrder = sortingOrder;
    owner->GetScene()->AddToRenderingMatrix(this);
}

VNGin::TextureRenderer::~TextureRenderer() {
    SDL_DestroyTexture(texture);
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

const VNGin::Vector VNGin::TextureRenderer::pivotUpLeft    = {0, 0};
const VNGin::Vector VNGin::TextureRenderer::pivotUp        = {0.5, 0};
const VNGin::Vector VNGin::TextureRenderer::pivotUpRight   = {1, 0};
const VNGin::Vector VNGin::TextureRenderer::pivotLeft      = {0, 0.5};
const VNGin::Vector VNGin::TextureRenderer::pivotCenter    = {0.5, 0.5};
const VNGin::Vector VNGin::TextureRenderer::pivotRight     = {1, 0.5};
const VNGin::Vector VNGin::TextureRenderer::pivotDownLeft  = {0, 1};
const VNGin::Vector VNGin::TextureRenderer::pivotDown      = {0.5, 1};   
const VNGin::Vector VNGin::TextureRenderer::pivotDownRight = {1, 1};