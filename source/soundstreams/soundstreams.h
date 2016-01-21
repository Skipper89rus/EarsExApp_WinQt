#ifndef SOUNDSTREAM_H
#define SOUNDSTREAM_H

#include <QObject>

#include "isoundstream.h"

namespace EarsExApp
{

class BaseSoundStream : public QObject
                      , public ISoundStream
{
   Q_OBJECT
   Q_INTERFACES(EarsExApp::ISoundStream)

public:
   BaseSoundStream( QObject* pParent )
      : QObject(pParent)
   {}
   ~BaseSoundStream(){}

   // ISoundStream
   virtual void Start() = 0;
   virtual void Stop()  = 0;

   virtual quint32 AddProcessor();
   virtual void RemoveProcessor( quint32 processorId );
};

class DesktopSoundStream : public BaseSoundStream
{
   Q_OBJECT
   Q_INTERFACES(EarsExApp::ISoundStream)

public:
   DesktopSoundStream( QObject* pParent = 0 )
      : BaseSoundStream(pParent)
   {}
   ~DesktopSoundStream(){}

   // ISoundStream
   virtual void Start();
   virtual void Stop();
};

class HeadphonesSoundStream : public BaseSoundStream
{
   Q_OBJECT
   Q_INTERFACES(EarsExApp::ISoundStream)

public:
   HeadphonesSoundStream( QObject* pParent = 0 )
      : BaseSoundStream(pParent)
   {}
   ~HeadphonesSoundStream(){}

   // ISoundStream
   virtual void Start();
   virtual void Stop();
};

} // namespace EarsExApp

#endif // SOUNDSTREAM_H
