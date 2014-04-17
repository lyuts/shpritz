#pragma once

#include <reader/FileReader.h>
#include <sigc++/signal.h>
#include <sys/types.h>

class SpeedReader
{
    public:
        SpeedReader(unsigned int iWpm, double iORPFactor);

        void setText(Text iText);
        void sendWord();
        void setSpeed(unsigned int);

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
        int calcORP(const std::string& iWord);

    private:
        Text::const_iterator mCurrentWord;
        Text mText;
        unsigned int mWpm;
        double mORPFactor;
        bool mPause;
};
