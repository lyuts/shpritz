#pragma once

#include <sigc++/trackable.h>
#include <string>

namespace reader
{

class FileReader : public sigc::trackable
{
    public:
        static FileReader* create(const std::string& iMime, const std::string& iPath);
        virtual ~FileReader();

        virtual std::string getWord() const = 0;

    protected:
        FileReader(const std::string& iPath);

    private:
        std::string mPath;
};

}

