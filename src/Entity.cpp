#include "Entity.h"
#include "Scene.h"

VNGin::Entity::Entity(Scene* scene, std::string name, Vector position, double rotation, Vector scale) : scene{scene}, name{name} {
    transform = this->AddModule<Transform>(position, rotation, scale);
    scene->AddEntity(this);
}

VNGin::Entity::~Entity() {} 

void VNGin::Entity::UpdateModules() {
    for(int i = 0; i < modules.size(); i++) 
        modules[i]->Update();
}