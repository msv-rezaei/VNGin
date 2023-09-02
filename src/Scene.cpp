#include "Scene.h" 

#include <algorithm>

VNGin::Scene::Scene() {} 

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

void VNGin::Scene::Update() {
    for(int i = 0; i < entities.size(); i++) 
        entities[i]->UpdateModules();
}