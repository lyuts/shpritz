#pragma once

#include <string>
#include <vector>

typedef std::vector<std::string> Text;

namespace reader
{

class FileReader
{
    public:
        static FileReader* create(const std::string& iMime);

        virtual Text parse(const std::string& iPath) const = 0;
};

}

