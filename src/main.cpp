#include <fcntl.h>
#include <iostream>
#include <magic.h>
#include <reader/FileReader.h>
#include <sigc++/connection.h>
#include <SpeedReader.h>
#include <string>
#include <ui/ReadingWindow.h>
#include <unistd.h>
#include <vector>

std::string determineFileType(const std::string& iPath)
{
    if (-1 == access(iPath.c_str(), O_RDONLY))
    {
        std::cerr << "Unable to access file '" << iPath << "' : " << strerror(errno) << std::endl;
        return "";
    }

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
    using ui::ReadingWindow;

    if (argc < 2)
    {
        std::cout << "Usage: shpritz <file>" << std::endl;
        return -1;
    }

    std::vector<std::string> args(argv, argv + argc);

    std::string filePath = args.at(1);
    std::string mime = determineFileType(filePath);
    if (mime.empty())
    {
        std::cerr << "Failed to detect mime type" << std::endl;
        return -1;
    }
    std::unique_ptr<FileReader> reader(FileReader::create(mime, filePath));

    if (!reader)
    {
        std::cerr << "Failed to create file reader" << std::endl;
        return -1;
    }

    ReadingWindow win;
    SpeedReader sr(250, .45);

    sr.signalWordReady.connect(sigc::mem_fun(win, &ReadingWindow::showWord));
    sr.signalWordAwaiting.connect(sigc::mem_fun(*reader.get(), &FileReader::getWord));
    sr.signalSpeedChanged.connect(sigc::mem_fun(win, &ReadingWindow::showCurrentSpeed));

    win.signalPauseToggled.connect(sigc::mem_fun(sr, &SpeedReader::togglePause));
    win.signalSpeedDecreaseRequested.connect(sigc::mem_fun(sr, &SpeedReader::decreaseSpeed));
    win.signalSpeedIncreaseRequested.connect(sigc::mem_fun(sr, &SpeedReader::increaseSpeed));
    win.signalJumpPrevSentence.connect(sigc::mem_fun(sr, &SpeedReader::jumpPrevSentence));
    win.signalJumpNextSentence.connect(sigc::mem_fun(sr, &SpeedReader::jumpNextSentence));
    win.signalExitRequested.connect(sigc::mem_fun(sr, &SpeedReader::terminate));

    sr.start();

    return 0;
}
