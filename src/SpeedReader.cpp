#include <iostream>
#include <SpeedReader.h>

SpeedReader::SpeedReader(unsigned int iWpm, double iORPfactor)
    : mWpm(iWpm),
      mORPFactor(iORPfactor)
{

}

int
SpeedReader::calcORP(size_t n)
{
    return n * 0.45 + 0.5;
}

void
SpeedReader::start()
{
    std::string w = signalWordAwaiting.emit();
    signalWordReady.emit(w, calcORP(w.size()));
}

void
SpeedReader::togglePause()
{

}

void
SpeedReader::decreaseSpeed()
{
    mWpm -= 50;
}


void
SpeedReader::increaseSpeed()
{
    mWpm += 50;
}

void
SpeedReader::jumpPrevSentence()
{

}

void
SpeedReader::jumpNextSentence()
{

}

void
SpeedReader::terminate()
{
    exit(0);
}
