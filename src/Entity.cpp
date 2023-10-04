#include "Entity.h"
#include "Scene.h"

VNGin::Entity::Entity(Scene* scene, std::string name, Vector position, double rotation, Vector scale) : scene{scene}, name{name} {
    transform = this->AddModule<Transform>(position, rotation, scale);
    scene->AddEntity(this);
}

void VNGin::Entity::UpdateModules() {
    for(int i = 0; i < modules.size(); i++) 
        modules[i]->Update();
}

void VNGin::Entity::Destroy() {
    for(int i = modules.size()-1; i >= 0; i--) 
        modules[i]->Destroy();
    scene->RemoveEntity(this);
}

void VNGin::Entity::SwitchScene(Scene* newScene) {
    scene->RemoveEntity(this);
    newScene->AddEntity(this);
    scene = newScene;
}

template<>
void VNGin::Entity::RemoveModule<VNGin::Transform>() { SDL_Log("Can't remove Transform component"); }