#include "ShotIterator.h"
#include "ProductionGroup.h"

ShotIterator::ShotIterator(const std::vector<ProductionComponent*>& components)
    : snapshot(components) {
    this->pos = 0;
    next_valid();

}

void ShotIterator::next_valid() {
    while (pos < snapshot.size()) {
        if (dynamic_cast<ProductionGroup*>(snapshot[pos]) == nullptr) {
            break;
        }
        pos++;
    }
}

void ShotIterator::first() {
    pos = 0;
    next_valid();
}

void ShotIterator::next() {
    if (!isDone()) {
        pos++;
        next_valid();
    }
}

bool ShotIterator::isDone() const {
    return pos >= snapshot.size();
}

ProductionComponent* ShotIterator::currentItem() const {
    if (isDone()) return nullptr;
    return snapshot[pos];
}