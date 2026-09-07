#ifndef INSURANCEDECORATOR_H
#define INSURANCEDECORATOR_H

#include "ShotDecorator.h"
#include <iostream>
using namespace std;

//Concrete Decorator
class InsuranceDecorator : public ShotDecorator {
    public:
        InsuranceDecorator(ProductionComponent* component);
        void process();
        string getName() const;
};

#endif //INSURANCEDECORATOR_H