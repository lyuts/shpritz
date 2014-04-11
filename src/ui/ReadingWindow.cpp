#include <iostream>
#include <ncurses.h>
#include <ui/ReadingWindow.h>
#include <unistd.h>

namespace ui
{
ReadingWindow::ReadingWindow()
{
    initscr();
    raw();
}

ReadingWindow::~ReadingWindow()
{
    endwin();
}

void
ReadingWindow::showWord(std::string iWord, unsigned int iORP)
{
    std::cout << "asdfasdf" << std::endl;
    printw(iWord.c_str());
    getch();
}

}
