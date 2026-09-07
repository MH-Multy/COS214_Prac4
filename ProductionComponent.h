#ifndef PRODUCTIONCOMPONENT_H
#define PRODUCTIONCOMPONENT_H

#include <string>

class ProductionComponent
{
public:
    virtual ~ProductionComponent() {}

    virtual void process() = 0;
    virtual std::string getName() const = 0;
};

#endif //PRODUCTIONCOMPONENT_H