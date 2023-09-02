#include "Entity.h"

VNGin::Entity::Entity(Scene* scene, std::string name) : scene{scene}, name{name} {}

VNGin::Entity::~Entity() {} 

void VNGin::Entity::UpdateModules() {
    for(int i = 0; i < modules.size(); i++) 
        modules[i]->Update();
}