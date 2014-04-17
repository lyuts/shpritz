#include <iostream>
#include <SpeedReader.h>
#include <thread>

SpeedReader::SpeedReader(unsigned int iWpm, double iORPfactor)
    : mCurrentWord(),
      mText(),
      mWpm(iWpm),
      mORPFactor(iORPfactor),
      mPause(true)
{

}

void
SpeedReader::setText(Text iText)
{
    mText = iText;
    mCurrentWord = mText.begin();
}

int
SpeedReader::calcORP(const std::string& iWord)
{
    size_t length = iWord.size();
    char lastChar = iWord[length - 1];

    if (lastChar == '\n')
    {
        lastChar = iWord[length - 2];
        length--;
    }

    if (std::string::npos != std::string(",.?!:;\"").find(lastChar))
    {
        length--;
    }

    int orp = length <= 1 ? 0 :
                    (length == 2 ? 1 :
                     (length == 3 ? 1 :
                      (length / 2) - 1));

    return orp + 1;

//    int orp = n * 0.45 + 0.5;

//    return orp > 0 ? orp : 1;
}

void
SpeedReader::start()
{
    while (true)
    {
        if (mPause) continue;
        if (mCurrentWord != mText.end() && !mCurrentWord->empty())
        {
            signalWordReady.emit(*mCurrentWord, calcORP(*mCurrentWord));
            if (mCurrentWord->at(mCurrentWord->size() - 1) == '.')
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(60000/mWpm));
            }

            mCurrentWord++;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(60000/mWpm));

//        mTimer.expires_from_now();
//        mTimer.async_wait(std::bind(&SpeedReader::sendWord, this));
    }
}

void
SpeedReader::sendWord()
{
        std::cout << "sending word" << std::endl;
    signalWordReady.emit("qwerty", 0);
//    std::string w = signalWordAwaiting.emit();
//    if (mCurrentWord != mText.end())
//    {
//        signalWordReady.emit(*mCurrentWord, calcORP(mCurrentWord->size()));
//        mCurrentWord++;
//    }
//    else
//    {
//        std::cout << "cancelling timer" << std::endl;
//        mTimer.cancel();    
//    }
}

void
SpeedReader::togglePause()
{
    mPause = !mPause;
}

void
SpeedReader::decreaseSpeed()
{
    setSpeed(mWpm - 50);
}


void
SpeedReader::increaseSpeed()
{
    setSpeed(mWpm + 50);
}

void
SpeedReader::setSpeed(unsigned int iWpm)
{
    if (iWpm > 0)
    {
        mWpm = iWpm;
    }
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
