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

    for(auto& vec : renderingMatrix) {
        auto iter = std::find(vec.begin(), vec.end(), renderer);        
        if(iter != vec.end()) return; 
    }

    renderingMatrix[renderer->GetSortingOrder()].push_back(renderer);
}

void VNGin::Scene::RemoveFromRenderingMatrix(TextureRenderer* renderer) {
    int order = renderer->GetSortingOrder();

    auto iter = std::find(renderingMatrix[order].begin(), renderingMatrix[order].end(), renderer); 
    if(iter != renderingMatrix[order].end())   
        renderingMatrix[order].erase(iter);
}

void VNGin::Scene::Update(SDL_Renderer* renderer) {   
    for(auto entity : entities) 
        entity->UpdateModules();
    
    for(int i = 0; i < renderingMatrix.size(); i++) {
        for(int j = 0; j < renderingMatrix[i].size(); j++) {
            if(renderingMatrix[i][j]->isVisible) 
                renderingMatrix[i][j]->Render(renderer);
        }
    }
}