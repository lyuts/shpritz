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

