#ifndef SHOT_H
#define SHOT_H

#include "ProductionComponent.h"
#include "ShotState.h"
#include "ProductionComponent.h"
#include <string>
#include <iostream>
using namespace std;


class ShotState;

// This is our context
class Shot : public ProductionComponent
{
    private:
        string name;
        ShotState* state;
    public:
        Shot(const string& name);
        ~Shot();
        void startRecording();
        void stopRecording();
        void setState(ShotState* newState);
        const char* getStateName();
        string getName() const;
        void process() override; 
        Iterator* createIterator() override; 
        void collect(std::vector<ProductionComponent*>&) override;
};

#endif //SHOT_H