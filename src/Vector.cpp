#include "Vector.h"

const VNGin::Vector VNGin::Vector::up             = {0, -1}; 
const VNGin::Vector VNGin::Vector::down           = {0, 1}; 
const VNGin::Vector VNGin::Vector::left           = {-1, 0}; 
const VNGin::Vector VNGin::Vector::right          = {1, 0}; 
const VNGin::Vector VNGin::Vector::one            = {1, 1}; 
const VNGin::Vector VNGin::Vector::zero           = {0, 0}; 
const VNGin::Vector VNGin::Vector::pivotUpLeft    = {0, 0};
const VNGin::Vector VNGin::Vector::pivotUp        = {0.5, 0};
const VNGin::Vector VNGin::Vector::pivotUpRight   = {1, 0};
const VNGin::Vector VNGin::Vector::pivotLeft      = {0, 0.5};
const VNGin::Vector VNGin::Vector::pivotCenter    = {0.5, 0.5};
const VNGin::Vector VNGin::Vector::pivotRight     = {1, 0.5};
const VNGin::Vector VNGin::Vector::pivotDownLeft  = {0, 1};
const VNGin::Vector VNGin::Vector::pivotDown      = {0.5, 1};   
const VNGin::Vector VNGin::Vector::pivotDownRight = {1, 1};

void VNGin::Vector::Normalize() {
    double mag = magnitude(); 
    x /= mag; 
    y /= mag;
}

VNGin::Vector VNGin::Vector::operator-(const Vector& other) const {
    return VNGin::Vector(this->x - other.x, this->y - other.y); 
} 

VNGin::Vector VNGin::Vector::operator+(const Vector& other) const {
    return VNGin::Vector(this->x + other.x, this->y + other.y); 
} 

VNGin::Vector VNGin::Vector::operator*(double value) const {
    return VNGin::Vector(this->x * value, this->y * value); 
} 

VNGin::Vector VNGin::Vector::operator/(double value) const {
    return VNGin::Vector(this->x / value, this->y / value); 
}

VNGin::Vector& VNGin::Vector::operator-=(const Vector& other) {
    *this = *this - other;
    return *this;
}

VNGin::Vector& VNGin::Vector::operator+=(const Vector& other) {
    *this = *this + other;
    return *this;
}

VNGin::Vector& VNGin::Vector::operator*=(double value) {
    *this = *this * value;
    return *this;
}

VNGin::Vector& VNGin::Vector::operator/=(double value) {
    *this = *this / value;
    return *this;
}

bool VNGin::Vector::operator==(const Vector& other) const {
    return (this->x == other.x) && (this->y == other.y);
}