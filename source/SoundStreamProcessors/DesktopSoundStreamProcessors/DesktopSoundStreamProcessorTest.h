#ifndef DESKTOPSOUNDSTREAMPROCESSORTEST_H
#define DESKTOPSOUNDSTREAMPROCESSORTEST_H

#include "DesktopSoundStreamProcessorBase.h"

namespace EarsExApp
{

// Просто увеличим амплитуду
class DesktopSoundStreamProcessorTest : public DesktopSoundStreamProcessorBase
{
   Q_OBJECT

public:
   DesktopSoundStreamProcessorTest(QObject* pParent = nullptr)
      : DesktopSoundStreamProcessorBase(pParent)
      , _power(10)
   {}
   ~DesktopSoundStreamProcessorTest(){}

public:
   // ISoundStreamProcessor
   virtual bool     Init() { return true; }
   virtual wchar_t* GetName() { return L"Test"; }
   virtual wchar_t* GetDescription() { return L"Test description"; }

protected:
   // DesktopSoundStreamProcessorBase
   virtual void processSample(QByteArray& sample)
   {
      for (QByteArray::iterator amplIt = sample.begin(); amplIt != sample.end(); ++amplIt)
         *amplIt *= _power;
   }

private:
   quint32 _power;
};

} // namespace EarsExApp

#endif // DESKTOPSOUNDSTREAMPROCESSORTEST_H
