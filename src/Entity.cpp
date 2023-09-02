#include "Entity.h"
#include "Scene.h"

VNGin::Entity::Entity(Scene* scene, std::string name) : scene{scene}, name{name} {
    scene->AddEntity(this);
}

VNGin::Entity::~Entity() {} 

void VNGin::Entity::UpdateModules() {
    for(int i = 0; i < modules.size(); i++) 
        modules[i]->Update();
}