#pragma once

#include <sigc++/signal.h>
#include <sigc++/trackable.h>
#include <sys/types.h>

class SpeedReader : public sigc::trackable
{
    public:
        SpeedReader(unsigned int iWpm, double iORPFactor);

        void start();
        void togglePause();
        void decreaseSpeed();
        void increaseSpeed();
        void jumpPrevSentence();
        void jumpNextSentence();
        void terminate();

        sigc::signal<std::string> signalWordAwaiting;
        sigc::signal<void, std::string, unsigned int> signalWordReady;
        sigc::signal<void, unsigned int> signalSpeedChanged;

    private:
        int calcORP(size_t n);

    private:
        unsigned int mWpm;
        double mORPFactor;
};
