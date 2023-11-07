#include "BoxCollider.h"
#include "Game.h"
#include "Entity.h" 
#include "Utility.h"

VNGin::BoxCollider::BoxCollider(Entity* owner, int width, int height, Vector pivot) : Module(owner), pivot{pivot} {
    rect.w = width; 
    rect.h = height;
    rect.x = owner->transform->GetPosition().x - (pivot.x * width);
    rect.y = owner->transform->GetPosition().y - (pivot.y * height);
} 

void VNGin::BoxCollider::Update() {
    rect.x = owner->transform->GetPosition().x - (pivot.x * rect.w);
    rect.y = owner->transform->GetPosition().y - (pivot.y * rect.h);

    SDL_SetRenderDrawColor(Game::renderer, ColorRGBA::green.r, ColorRGBA::green.g, ColorRGBA::green.b, 255);
    SDL_RenderDrawRect(Game::renderer, &rect);
}

