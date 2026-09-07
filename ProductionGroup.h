#ifndef PRODUCTIONGROUP_H
#define PRODUCTIONGROUP_H

#include "ProductionComponent.h"
#include <vector>

class ProductionGroup : public ProductionComponent
{
private:
    std::string name;
    std::vector<ProductionComponent*> children;

public:
    ProductionGroup(const std::string& name);
    virtual ~ProductionGroup();
    void add(ProductionComponent* component);
    void remove(ProductionComponent* component);
    void process();
    std::string getName() const;

    virtual Iterator* createIterator() override;
    virtual void collect(std::vector<ProductionComponent*>& snapshotList) override;
};

#endif //PRODUCTIONGROUP_H