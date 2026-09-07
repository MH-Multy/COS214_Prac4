#include "ShotDecorator.h"
#include "HierarchyIterator.h"

ShotDecorator::ShotDecorator(ProductionComponent* comp) : component(comp) {}

ShotDecorator::~ShotDecorator() {
    delete component;
}

void ShotDecorator::collect(std::vector<ProductionComponent*>& snapshotList) {
    snapshotList.push_back(this);
}

Iterator* ShotDecorator::createIterator() {
    std::vector<ProductionComponent*> vec;
    this->collect(vec);
    return new HierarchyIterator(vec);
}