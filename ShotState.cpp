#include "ShotState.h"

// Recording (we can make it three seperate file for each if u guys want, or keep all in one)
void Recording::startRecording(Shot& shot)
{
    cout << shot.getName() << ": Already Recording \n";
}

void Recording::stopRecording(Shot& shot)
{
    cout << shot.getName() << ": Recording Stoped \n";
    shot.setState(new Completed());
}

const char* Recording::getStateName()
{
    return "Recording";
}


// NotRecording
void NotRecording::startRecording(Shot& shot)
{
    cout << shot.getName() << ": Starting Recording... \n";
    shot.setState(new Recording());
}

void NotRecording::stopRecording(Shot& shot)
{
    cout << shot.getName() << ": Cannot stop Recording as it is not active \n";
}

const char* NotRecording::getStateName()
{
    return "Not Recording";
}


// Completed
void Completed::startRecording(Shot& shot)
{
    cout << shot.getName() << ": Shot already completed \n";
}

void Completed::stopRecording(Shot& shot)
{
    cout << shot.getName() << ": Shot already comlpeted \n";
}

const char* Completed::getStateName()
{
    return "Comlpeted";
}