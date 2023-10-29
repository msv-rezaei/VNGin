#include "Scene.h" 

#include <algorithm>

VNGin::Scene::~Scene() {
    for(auto iter = entities.begin(); iter != entities.end(); iter++) 
        (*iter)->Destroy();
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
        *iter = nullptr;
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
            if(*iter != nullptr)
                if((*iter)->isVisible) 
                    (*iter)->Render(renderer);
        }
    }

    SDL_Log("-----");
    for(auto entity : entities) 
        if(entity != nullptr) 
            SDL_Log("%s\n", entity->name.c_str());

    for(auto entity : entities) 
        if(entity != nullptr)
            entity->UpdateModules();

    // Cleanup
    auto iter = std::remove_if(entities.begin(), entities.end(), [](auto e){ return e == nullptr; });
    while(iter != entities.end()) 
        entities.erase(iter++);
}