#include "HierarchyIterator.h"

HierarchyIterator::HierarchyIterator(const std::vector<ProductionComponent*>& components, std::size_t initialPos) 
    : snapshot(components), pos(initialPos) {}

void HierarchyIterator::first() {
    pos = 0;
}

void HierarchyIterator::next() {
    if (!isDone()) {
        pos++;
    }
}

bool HierarchyIterator::isDone() const {
    return pos >= snapshot.size();
}

ProductionComponent* HierarchyIterator::currentItem() const {
    if (isDone()) return nullptr;
    return snapshot[pos];
}