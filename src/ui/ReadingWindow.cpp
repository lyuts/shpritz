#include <iostream>
#include <ui/ReadingWindow.h>
#include <unistd.h>

namespace ui
{
ReadingWindow::ReadingWindow()
    : mSpritzWindow(nullptr, &delwin),
      mMainWindow(nullptr, &delwin)
{
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    raw();
    keypad(stdscr, TRUE);
    noecho();

    createSpritzWindow();
    createMainWindow();
    refreshWindows();
}

ReadingWindow::~ReadingWindow()
{
    endwin();
}

void
ReadingWindow::createSpritzWindow()
{
    mSpritzWindow.reset(newwin(3, COLS, 0, 0));
    box(mSpritzWindow.get(), 0, 0);
}

void
ReadingWindow::refreshWindows()
{
    // draw ticks for ORP
    int x, y;
    getmaxyx(mSpritzWindow.get(), y, x);
    wmove(mSpritzWindow.get(), 0, x / 2);
    waddch(mSpritzWindow.get(), ACS_TTEE);
    wmove(mSpritzWindow.get(), 2, x / 2);
    waddch(mSpritzWindow.get(), ACS_BTEE);

    refresh();
    wrefresh(mSpritzWindow.get());
    wrefresh(mMainWindow.get());
}

void
ReadingWindow::createMainWindow()
{
    int x, y;
    getmaxyx(mSpritzWindow.get(), y, x);
    mMainWindow.reset(newwin(LINES - y, COLS, y, 0));
    box(mMainWindow.get(), 0, 0);
    scrollok(mMainWindow.get(), TRUE);
    wmove(mMainWindow.get(), 1, 1);
}

void
ReadingWindow::showWord(std::string iWord, unsigned int iORP)
{
    wmove(mSpritzWindow.get(), 1, 1);
    wclrtoeol(mSpritzWindow.get());

    int x, y;
    getmaxyx(mSpritzWindow.get(), y, x);
    int orpPos = x / 2;
    int head = orpPos - iORP + 1;
    int tail = x - 2 - iWord.size() - head;

    wmove(mSpritzWindow.get(), 1, head);
    waddstr(mSpritzWindow.get(), iWord.substr(0, iORP - 1).c_str());
    wattron(mSpritzWindow.get(), COLOR_PAIR(1));
    waddstr(mSpritzWindow.get(), iWord.substr(iORP - 1, 1).c_str());
//    wprintw(mSpritzWindow.get(), "%s", iWord.substr(iORP - 1, 1).c_str());
    wattroff(mSpritzWindow.get(), COLOR_PAIR(1));
    waddstr(mSpritzWindow.get(), iWord.substr(iORP).c_str());
//    mvwaddstr(mSpritzWindow.get(), 1, head, iWord.substr(0, iORP).c_str());

    box(mSpritzWindow.get(), 0, 0); // replace with drawing left/right border only

    waddstr(mMainWindow.get(), iWord.c_str());
//    wprintw(mMainWindow.get(), "(%d)", iORP);
    waddstr(mMainWindow.get(), " ");



    refreshWindows();
}

void
ReadingWindow::showCurrentSpeed(unsigned int iWpm)
{

}

void
ReadingWindow::show()
{
    refreshWindows();
    char ch;
    while ('q' != (ch = getch()))
    {
        refreshWindows();
        if ('z' == ch)
        {

            signalSpeedDecreaseRequested.emit();
        }
        else if ('a' == ch)
        {
            signalSpeedIncreaseRequested.emit();
        }
        else if ('x' == ch)
        {
            signalPauseToggled.emit();
        }
        else if ('k' == ch)
        {
            signalJumpPrevSentence.emit();
        }
        else if ('j' == ch)
        {
            signalJumpNextSentence.emit();
        }
    }

    signalExitRequested.emit();
}
}
