#include "Shot.h"
#include "HierarchyIterator.h"

Shot::Shot(const string& name)
{
    this->name = name;
    this->state = new NotRecording();
}

Shot::~Shot()
{
    delete state;
}

void Shot::startRecording()
{
    state->startRecording(*this);
}

void Shot::stopRecording()
{
    state->stopRecording(*this);
}

void Shot::setState(ShotState* newState)
{
    delete state;
    state = newState;
}

const char* Shot::getStateName()
{
    return state->getStateName();
}

string Shot::getName() const
{
    return name;
}

void Shot::process() 
{
    cout << "processing shot: " << name << " (Status: " << getStateName() << ")\n";
}

void Shot::collect(std::vector<ProductionComponent*>& snapshotList) 
{
    snapshotList.push_back(this);
}

Iterator* Shot::createIterator() 
{
    std::vector<ProductionComponent*> vec;
    this->collect(vec);
    return new HierarchyIterator(vec,0); 
}