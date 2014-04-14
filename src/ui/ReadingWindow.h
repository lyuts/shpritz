#pragma once

#include <ncurses.h>
#include <sigc++/signal.h>
#include <string>

namespace ui
{

class ReadingWindow
{
    public:
        ReadingWindow();
        ~ReadingWindow();

        void showWord(std::string, unsigned int);
        void showCurrentSpeed(unsigned int);
        void show();

        sigc::signal<void> signalPauseToggled;
        sigc::signal<void> signalSpeedDecreaseRequested;
        sigc::signal<void> signalSpeedIncreaseRequested;
        sigc::signal<void> signalJumpPrevSentence;
        sigc::signal<void> signalJumpNextSentence;
        sigc::signal<void> signalExitRequested;

    private:
        void createSpritzWindow();
        void createMainWindow();
        void refreshWindows();

    private:
        std::unique_ptr<WINDOW, decltype(&delwin)> mSpritzWindow;
        std::unique_ptr<WINDOW, decltype(&delwin)> mMainWindow;
};

}

