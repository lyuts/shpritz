#include <reader/FileReader.h>
#include <reader/TxtReader.h>

namespace reader
{
FileReader::FileReader(const std::string& iPath)
    : mPath(iPath)
{
}

FileReader::~FileReader()
{
}


FileReader*
FileReader::create(const std::string& iMime, const std::string& iPath)
{
    FileReader* reader = nullptr;

    if (0 == iMime.find("text/"))
    {
        reader = new TxtReader(iPath);
    }
    return reader;
}

}
