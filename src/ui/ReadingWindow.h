#pragma once

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
};

}

