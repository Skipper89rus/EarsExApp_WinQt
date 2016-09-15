#ifndef DESKTOPSOUNDSTREAM_H
#define DESKTOPSOUNDSTREAM_H

#include <QObject>
#include <QDebug>
#include <QAudioOutput>
#include <QAudioInput>
#include <QIODevice>

#include "ISoundStream.h"
#include "Common/SoundSampleBuffer.h"

#include "SoundStreamProcessors/SoundStreamProcessorsManager.h"
#include "SoundStreamProcessors/DesktopSoundStreamProcessors/DesktopSoundStreamProcessorTest.h"

namespace EarsExApp
{

class DesktopSoundStream : public QObject, public ISoundStream
{
   Q_OBJECT

public:
   DesktopSoundStream(QObject* pParent = nullptr);
   ~DesktopSoundStream(){}

   // ISoundStream
   virtual void Start();
   virtual void Stop();
   virtual bool IsStarted() const;

   virtual unsigned int GetAvailableProcessors(ISoundStreamProcessor** ppProcessors);

signals:
   void readyProcess();
   void readyPlay();

private slots:
   void readNextSample();
   void processNextSample();
   void playNextSample();

private:
   void prepareAudioFormat(QAudioFormat& format) const;
   void prepareAudioIO();

   void prepareProcessors();

private:
   SoundSampleBuffer _buffer;

   QAudioInput*      _pAudioInput;
   QAudioOutput*     _pAudioOutput;
   QIODevice*        _pInputDevice;
   QIODevice*        _pOutputDevice;

   SoundStreamProcessorsManager _processorsManager;
   DesktopSoundStreamProcessorTest* _pDesktopProcessorTest;

   bool _isStarted;
};

} // namespace EarsExApp

#endif // DESKTOPSOUNDSTREAM_H
