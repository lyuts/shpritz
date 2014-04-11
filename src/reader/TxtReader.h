#pragma once

#include <reader/FileReader.h>

namespace reader
{
class TxtReader : public FileReader
{
    public:
        TxtReader(const std::string& iPath);

        std::string getWord() const override;
};
}

