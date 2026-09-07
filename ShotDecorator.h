#ifndef SHOTDECORATOR_H
#define SHOTDECORATOR_H

#include "ProductionComponent.h"
#include <string>
using namespace std;

// This is the decorator (Abstract kinda one)
class ShotDecorator : public ProductionComponent {
    protected:
        ProductionComponent* component;
    public:
        ShotDecorator(ProductionComponent* component);
        virtual ~ShotDecorator();
        virtual void process() = 0;
        virtual string getName() const = 0;
        virtual Iterator* createIterator() override;
        virtual void collect(std::vector<ProductionComponent*>& snapshotList) override;
};

#endif //SHOTDECORATOR_H