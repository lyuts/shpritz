#pragma once

#include <sigc++/signal.h>
#include <sigc++/trackable.h>
#include <string>

namespace ui
{

class ReadingWindow : public sigc::trackable
{
    public:
        ReadingWindow();
        ~ReadingWindow();

        void showWord(std::string, unsigned int);
        void showCurrentSpeed(unsigned int);

        sigc::signal<void> signalPauseToggled;
        sigc::signal<void> signalSpeedDecreaseRequested;
        sigc::signal<void> signalSpeedIncreaseRequested;
        sigc::signal<void> signalJumpPrevSentence;
        sigc::signal<void> signalJumpNextSentence;
        sigc::signal<void> signalExitRequested;
};

}

