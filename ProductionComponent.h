#ifndef PRODUCTIONCOMPONENT_H
#define PRODUCTIONCOMPONENT_H

#include <string>
#include "Iterator.h"
#include <vector>

class ProductionComponent
{
public:
    virtual ~ProductionComponent() {}

    virtual void process() = 0;
    virtual std::string getName() const = 0;
    virtual Iterator* createIterator() = 0;
    virtual void collect(std::vector<ProductionComponent*>& snapshotList) = 0;
};

#endif //PRODUCTIONCOMPONENT_H