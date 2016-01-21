#ifndef SOUNDSTREAMSMANAGER_H
#define SOUNDSTREAMSMANAGER_H

#include <QObject>

#include "soundstreams.h"

namespace EarsExApp
{

enum SoundStreamMode
{
   SSM_Desktop,
   SSM_Headphones
};

class SoundStreamsManager : public QObject
{
   Q_OBJECT

public:
   SoundStreamsManager( QObject* pParent = 0 );
   ~SoundStreamsManager(){}

public:
   ISoundStream* GetSoundStream();

private:
   ISoundStream* getSoundStream();

private:
   SoundStreamMode _streamMode;

   ISoundStream* _pSoundStream;
};

} // namespace EarsExApp

#endif // SOUNDSTREAMSMANAGER_H
