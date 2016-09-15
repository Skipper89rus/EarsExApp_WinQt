#include "DesktopSoundStream.h"

namespace EarsExApp
{

DesktopSoundStream::DesktopSoundStream(QObject* pParent)
   : QObject(pParent)
   , _isStarted(false)
{
   prepareAudioIO();
   prepareProcessors();
}

void DesktopSoundStream::Start()
{
   _pInputDevice = _pAudioInput->start();
   _pOutputDevice = _pAudioOutput->start();

   connect( _pInputDevice, SIGNAL(readyRead()), this, SLOT(readNextSample()) );
   connect( this, SIGNAL(readyProcess()), SLOT(processNextSample()) );
   connect( this, SIGNAL(readyPlay()), SLOT(playNextSample()) );

   _isStarted = true;
}

void DesktopSoundStream::Stop()
{
   if (_pAudioInput != nullptr && _pAudioInput->state() == QAudio::AudioInput)
      _pAudioInput->stop();
   if (_pAudioOutput != nullptr && _pAudioOutput->state() == QAudio::AudioOutput)
      _pAudioOutput->stop();

   disconnect( _pInputDevice, SIGNAL(readyRead()), this, SLOT(readNextSample()) );
   disconnect( SIGNAL(readyProcess()), this, SLOT(processNextSample()) );
   disconnect( SIGNAL(readyPlay()), this, SLOT(playNextSample()) );

   _isStarted = false;
}

bool DesktopSoundStream::IsStarted() const
{
   return _isStarted;
}

unsigned int DesktopSoundStream::GetAvailableProcessors(ISoundStreamProcessor** ppProcessors)
{
   const QList<DesktopSoundStreamProcessorBase*>* processors = _processorsManager.GetProcessors();
   *ppProcessors = processors->front();
   return processors->size();
   return 0;
}

void DesktopSoundStream::prepareAudioFormat(QAudioFormat& format) const
{
   format.setSampleRate(8000);
   format.setChannelCount(1);
   format.setSampleSize(8);
   format.setCodec("audio/wav");
   format.setByteOrder(QAudioFormat::LittleEndian);
   format.setSampleType(QAudioFormat::UnSignedInt);
}

void DesktopSoundStream::prepareAudioIO()
{
   QAudioFormat format;
   prepareAudioFormat(format);

   QAudioDeviceInfo infoIn( QAudioDeviceInfo::defaultInputDevice() );
   if ( !infoIn.isFormatSupported(format) )
   {
      qWarning() << "Default format not supported - trying to use nearest";
      format = infoIn.nearestFormat(format);
   }
   _pAudioInput = new QAudioInput(infoIn, format, this);
   _pAudioInput->setBufferSize( _buffer.GetBufferSize() );

   QAudioDeviceInfo infoOut( QAudioDeviceInfo::defaultOutputDevice() );
   if ( !infoOut.isFormatSupported(format) )
   {
      qWarning() << "Default format not supported - trying to use nearest";
      format = infoOut.nearestFormat(format);
   }
   _pAudioOutput = new QAudioOutput(infoOut, format, this);
}

void DesktopSoundStream::prepareProcessors()
{
   _pDesktopProcessorTest = new DesktopSoundStreamProcessorTest();
   _processorsManager.AddProcessor(_pDesktopProcessorTest);
   _processorsManager.Init();
}

void DesktopSoundStream::readNextSample()
{
   if(_pInputDevice == nullptr)
       return;

   const qint64 bytesCount = _pAudioInput->bytesReady();
   if (bytesCount == 0)
      return;

   char* pData = nullptr;
   while ( !_buffer.GetFreeBufferToWrite(&pData) );

   const qint64 resBytesCount = _pInputDevice->read(pData, bytesCount);
   Q_ASSERT(resBytesCount == bytesCount);

   emit readyProcess();
}

void DesktopSoundStream::processNextSample()
{
   QByteArray buf;
   while ( !_buffer.GetNextBufferToProcess(buf) );

   _processorsManager.ProcessSample(buf);
   emit readyPlay();
}

void DesktopSoundStream::playNextSample()
{
   if (_pOutputDevice == nullptr)
      return;

   QByteArray buf;
   while ( !_buffer.GetNextBufferToOutput(buf) );
   _pOutputDevice->write(buf.constData(), buf.size());
}

} // namespace EarsExApp
