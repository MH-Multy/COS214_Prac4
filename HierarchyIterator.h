#ifndef HIERARCHY_ITERATOR_H
#define HIERARCHY_ITERATOR_H

#include "Iterator.h"
#include <vector>
#include <cstddef>

class HierarchyIterator : public Iterator {
private:
    std::vector<ProductionComponent*> snapshot;
    size_t pos;

public:
    HierarchyIterator(const std::vector<ProductionComponent*>& components, std::size_t initialPos = 0);
    
    void first() override;
    void next() override;
    bool isDone() const override;
    ProductionComponent* currentItem() const override;
};

#endif