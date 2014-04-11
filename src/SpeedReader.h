#pragma once

#include <sigc++/signal.h>
#include <sys/types.h>

class SpeedReader
{
    public:
        SpeedReader(unsigned int iWpm, double iORPFactor);

        void start();

        sigc::signal<std::string> signalWordAwaiting;
        sigc::signal<void, std::string, unsigned int> signalWordReady;

    private:
        int calcORP(size_t n);

    private:
        unsigned int mWpm;
        double mORPFactor;
};
