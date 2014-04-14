#include <reader/FileReader.h>
#include <reader/TxtReader.h>

namespace reader
{
FileReader*
FileReader::create(const std::string& iMime)
{
    FileReader* reader = nullptr;

    if (0 == iMime.find("text/"))
    {
        reader = new TxtReader();
    }
    return reader;
}

}
