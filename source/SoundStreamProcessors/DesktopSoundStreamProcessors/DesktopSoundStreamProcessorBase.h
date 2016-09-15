#ifndef DESKTOPSOUNDSTREAMPROCESSORBASE_H
#define DESKTOPSOUNDSTREAMPROCESSORBASE_H

#include <QObject>
#include <QByteArray>

#include "SoundStreamProcessors/ISoundStreamProcessor.h"

namespace EarsExApp
{

class DesktopSoundStreamProcessorBase : public QObject, public ISoundStreamProcessor
{
   Q_OBJECT

public:
   DesktopSoundStreamProcessorBase(QObject* pParent = nullptr) : QObject(pParent) {}
   ~DesktopSoundStreamProcessorBase(){}

   // ISoundStreamProcessor
   virtual bool     Init() = 0;
   virtual wchar_t* GetName() = 0;
   virtual wchar_t* GetDescription() = 0;
   virtual void     Enable() { _isEnabled = true; }
   virtual void     Disable() { _isEnabled = false; }
   virtual bool     IsEnabled() { return _isEnabled; }

   void ProcessSample(QByteArray& sample)
   {
      if (_isEnabled)
         processSample(sample);
   }

protected:
   virtual void processSample(QByteArray& sample) = 0;

protected:
   bool _isEnabled;
};

} // namespace EarsExApp

#endif // DESKTOPSOUNDSTREAMPROCESSORBASE_H
