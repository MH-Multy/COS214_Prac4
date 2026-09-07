#ifndef SHOT_H
#define SHOT_H

#include "ShotState.h"
#include <string>
#include <iostream>
using namespace std;


class ShotState;

// This is our context
class Shot{
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
};

#endif //SHOT_H