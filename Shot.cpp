#include "Shot.h"

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

bool Shot::isGroup() const
{
    return false;
}