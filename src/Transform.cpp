#include "Transform.h"

void VNGin::Transform::Move(Vector move) {
    position.x += move.x; 
    position.y += move.y;
}

void VNGin::Transform::Rotate(double angle) {
    rotation += angle;
    
}

void VNGin::Transform::SetPosition(double x, double y) {
    position.x = x; 
    position.y = y; 
}

void VNGin::Transform::SetPosition(Vector newPosition) {
    position = newPosition; 
}

void VNGin::Transform::SetRotation(double angle) {
    rotation = angle; 
}

void VNGin::Transform::SetScale(double wm, double hm) {
    scale.x = wm; 
    scale.y = hm; 
}

void VNGin::Transform::SetScale(Vector newScale) {
    scale = newScale;
}

VNGin::Vector VNGin::Transform::GetPosition() {
    return {position.x, position.y};
}

double VNGin::Transform::GetRotation() {
    return rotation;
}

VNGin::Vector VNGin::Transform::GetScale() {
    return {scale.x, scale.y};
}
