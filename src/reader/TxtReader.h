#pragma once

#include <reader/FileReader.h>

namespace reader
{
class TxtReader : public FileReader
{
    public:
        TxtReader();

        Text parse(const std::string& iPath) const override;
};
}

