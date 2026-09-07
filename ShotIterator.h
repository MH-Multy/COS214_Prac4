#ifndef SHOT_ITERATOR_H
#define SHOT_ITERATOR_H

#include "Iterator.h"
#include <vector>
#include <cstddef>

class ShotIterator : public Iterator {
private:
    std::vector<ProductionComponent*> snapshot;
    size_t pos;

public:
    ShotIterator(const std::vector<ProductionComponent*>& components);
    
    void first() override;
    void next() override;
    bool isDone() const override;
    ProductionComponent* currentItem() const override;
    void next_valid();
};

#endif