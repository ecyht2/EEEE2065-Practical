#ifndef PRACTICAL8_H_
#define PRACTICAL8_H_

#include <string>

class Polymorphism {
public:
    Polymorphism(float x = 0, float y = 0, float z = 0);
    virtual void print(void);
    virtual void print(std::string name);
    float dist(float x0);
    float dist(float x0, float y0);
    float dist(float x0, float y0, float z0);
    Polymorphism operator + (Polymorphism input);
    Polymorphism operator - (Polymorphism input);
    float operator * (Polymorphism input);
protected:
    float x, y, z;
};

class Complex: public Polymorphism {
    public:
    using Polymorphism::Polymorphism;
    virtual void print(void) override;
};


#endif // PRACTICAL8_H_
