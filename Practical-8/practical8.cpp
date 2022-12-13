#include "practical8.h"

#include <iostream>
#include <cmath>
#include <string>

///////////////
// Polymorphism

Polymorphism::Polymorphism(float x, float y, float z): x(x), y(y), z(z) {

}

void Polymorphism::print(void) {
    std::cout << "(x, y, z) = ("
              << this->x << ", "
              << this->y << ", "
              << this->z << ")"
              << std::endl;
}

void Polymorphism::print(std::string name) {
    std::cout << name << ": "
              << "(x, y, z) = ("
              << this->x << ", "
              << this->y << ", "
              << this->z << ")"
              << std::endl;
}

float Polymorphism::dist(float x0) {
    float dist = this->x - x0;
    if (dist < 0) {
        dist *= -1;
    }
    return dist;
}

float Polymorphism::dist(float x0, float y0) {
    float dist = sqrt((this->x - x0) * (this->x - x0) +
                      (this->y - y0) * (this->y - y0));
    return dist;
}

float Polymorphism::dist(float x0, float y0, float z0) {
    float dist = sqrt((this->x - x0) * (this->x - x0) +
                      (this->y - y0) * (this->y - y0) +
                      (this->z - z0) * (this->z - z0));
    return dist;
}

Polymorphism Polymorphism::operator+(Polymorphism input) {
    Polymorphism output;
    output.x = this->x + input.x;
    output.y = this->y + input.y;
    output.z = this->z + input.z;
    return output;
}

Polymorphism Polymorphism::operator-(Polymorphism input) {
    Polymorphism output;
    output.x = this->x - input.x;
    output.y = this->y - input.y;
    output.z = this->z - input.z;
    return output;
}

float Polymorphism::operator*(Polymorphism input) {
    float output;
    output = this->x * input.x + this->y * input.y + this->x * input.z;
    return output;
}

//////////
// Complex
void Complex::print(void) {
    std::cout << this->x << " + j" << this->y << std::endl;
}
