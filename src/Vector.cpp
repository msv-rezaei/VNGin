#include "Vector.h"

const VNGin::Vector VNGin::Vector::up = VNGin::Vector(0, -1); 
const VNGin::Vector VNGin::Vector::down = VNGin::Vector(0, 1); 
const VNGin::Vector VNGin::Vector::left = VNGin::Vector(-1, 0); 
const VNGin::Vector VNGin::Vector::right = VNGin::Vector(1, 0); 
const VNGin::Vector VNGin::Vector::one = VNGin::Vector(1, 1); 
const VNGin::Vector VNGin::Vector::zero = VNGin::Vector(0, 0); 

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