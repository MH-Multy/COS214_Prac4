#ifndef SAFETYDECORATOR_H
#define SAFETYDECORATOR_H

#include "ShotDecorator.h"
#include <iostream>
using namespace std;

// Concrete Decorator
class SafetyDecorator : public ShotDecorator {
    public:
        SafetyDecorator(ProductionComponent* component);
        void process();
        string getName() const;
};

#endif //SAFETYDECORATOR_H