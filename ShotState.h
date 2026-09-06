#ifndef SHOTSTATE_H
#define SHOTSTATE_H

// Not gonna make 3 seperate small files

class Shot; // Shot is our context and we'll make it later
// State
class ShotState {
    public:
        virtual ~ShotState() {}
        virtual void startRecording(Shot& shot) = 0;
        virtual void stopRecording(Shot& shot) = 0;
        virtual const* getStateName() = 0;
};

// Concrete State
class Recording : public ShotState {
    public:
        void startRecording(Shot& shot);
        void stopRecording(Shot& shot);
        const char* getStateName();
};

class NotRecording : public ShotState {
    public:
        void startRecording(Shot& shot);
        void stopRecording(Shot& shot);
        const char* getStateName();
};

class Completed : public ShotState {
    public:
        void startRecording(Shot& shot);
        void stopRecording(Shot& shot);
        const char* getStateName();
};

#endif //SHOTSTATE_H