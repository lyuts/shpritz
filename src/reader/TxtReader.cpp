#include <reader/TxtReader.h>

namespace reader
{

TxtReader::TxtReader(const std::string& iPath)
    : FileReader(iPath)
{
}

std::string
TxtReader::getWord() const
{
    return "temp";
}
}
