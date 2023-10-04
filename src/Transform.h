#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Module.h"
#include "Vector.h"

namespace VNGin {
    class Entity;
    class Transform : public Module {
    public: 
        Transform(Entity* owner, Vector position = Vector::zero, double rotation = 0.0, Vector scale = Vector::one) 
            : Module(owner), position{position}, rotation{rotation}, scale{scale} {} 

        void Move(Vector amount); 
        void Rotate(double amount);

        void SetPosition(double x, double y); 
        void SetPosition(Vector newPosition); 
        void SetRotation(double angle); 
        void SetScale(double widthMultiplier, double heightMultiplier); 
        void SetScale(Vector newScale); 

        Vector GetPosition(void); 
        double GetRotation(void);
        Vector GetScale(void);

        const char* GetType() { return "Transform"; }
    private: 
        void Start() {} 
        void Update() {} 
        void Destroy() {} 

        Vector position;
        double rotation;
        Vector scale;
    }; 
}

#endif