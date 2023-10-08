#include "Scene.h" 

#include <algorithm>

VNGin::Scene::~Scene() {
    for(int i = 0; i < entities.size(); i++) 
        delete entities[i];
}

void VNGin::Scene::AddEntity(Entity* entity) {
    if(entity != nullptr) {
        if(std::find(entities.begin(), entities.end(), entity) == entities.end()) 
            entities.push_back(entity);
    }
}

void VNGin::Scene::RemoveEntity(Entity* entity) {
    auto iter = std::find(entities.begin(), entities.end(), entity); 
    if(iter != entities.end()) 
        entities.erase(iter); 
}

void VNGin::Scene::AddToRenderingMatrix(TextureRenderer* renderer) {
    if(renderer == nullptr) 
        return; 

    for(auto& list : renderingMatrix) {
        auto iter = std::find(list.begin(), list.end(), renderer);        
        if(iter != list.end()) return; 
    }

    renderingMatrix[renderer->GetSortingOrder()].push_front(renderer);
}

void VNGin::Scene::RemoveFromRenderingMatrix(TextureRenderer* renderer) {
    int order = renderer->GetSortingOrder();
    renderingMatrix[order].remove(renderer);
}

void VNGin::Scene::Update(SDL_Renderer* renderer) {   
    for(int i = 0; i < renderingMatrix.size(); i++) {
        for(auto iter = renderingMatrix[i].begin(); iter != renderingMatrix[i].end(); iter++) {
            if((*iter)->isVisible) 
                (*iter)->Render(renderer);
        }
    }

    for(auto entity : entities) 
        entity->UpdateModules();
}