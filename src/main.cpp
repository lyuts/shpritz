#include <fcntl.h>
#include <iostream>
#include <magic.h>
#include <reader/FileReader.h>
#include <string>
#include <vector>

std::string determineFileType(const std::string& iPath)
{
//    int fd = open(iPath.c_str(), O_RDONLY);
//    if (-1 == fd)
//    {
//        std::cerr << "Unable to open file '"
//                  << iPath
//                  << "': "
//                  << strerror(errno)
//                  << std::endl;
//        return;
//    }

    magic_t magic = magic_open(MAGIC_MIME_TYPE | MAGIC_CHECK);

    if (!magic)
    {
        std::cerr << "asdf" << std::endl;
    }

    if (-1 == magic_load(magic, NULL))
    {
        std::cerr << "Failed to load mime types" << std::endl;
    }
    std::string mime(magic_file(magic, iPath.c_str()));
    magic_close(magic);

    return mime;
}

int main(int argc, const char *argv[])
{
    using reader::FileReader;

    std::vector<std::string> args(argv, argv + argc);

    std::string filePath = args.at(1);
    std::string mime = determineFileType(filePath);
    std::unique_ptr<FileReader> reader(FileReader::create(mime, filePath));

    if (!reader)
    {
        std::cerr << "Failed to create file reader" << std::endl;
        return -1;
    }

    return 0;
}
