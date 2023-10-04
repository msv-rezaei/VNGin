#include "Entity.h"
#include "Scene.h"

VNGin::Entity::Entity(Scene* scene, std::string name, Vector position, double rotation, Vector scale) : scene{scene}, name{name} {
    transform = this->AddModule<Transform>(position, rotation, scale);
    scene->AddEntity(this);
}

VNGin::Entity::~Entity() {
    scene->RemoveEntity(this);
    for(int i = 0; i < modules.size(); i++) 
        delete modules[i]; 
} 

void VNGin::Entity::UpdateModules() {
    for(int i = 0; i < modules.size(); i++) 
        modules[i]->Update();
}

void VNGin::Entity::SwitchScene(Scene* newScene) {
    scene->RemoveEntity(this);
    newScene->AddEntity(this);
    scene = newScene;
}

template<>
void VNGin::Entity::RemoveModule<VNGin::Transform>() { SDL_Log("Can't remove Transform component"); }