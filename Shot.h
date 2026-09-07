#ifndef SHOT_H
#define SHOT_H

#include <string>

class ShotState;

class Shot
{
private:
    std::string name;
    ShotState* state;

public:
    Shot(const std::string& name);
    ~Shot();

    void startRecording();
    void stopRecording();

    void setState(ShotState* newState);

    const char* getStateName() const;
    std::string getName() const;
};

#endif //SHOT_H