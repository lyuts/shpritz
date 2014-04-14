#include <reader/TxtReader.h>
#include <fstream>

namespace reader
{

TxtReader::TxtReader()
    : FileReader()
{
}

Text
TxtReader::parse(const std::string& iPath) const
{
    std::ifstream f(iPath, std::fstream::in);

    std::vector<std::string> words;

    while (f.good())
    {
        std::string word;
        f >> word;
        words.emplace_back(word);
    }

    f.close();

    return words;
}
}
