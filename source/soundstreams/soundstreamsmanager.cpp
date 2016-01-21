#include "soundstreamsmanager.h"

namespace EarsExApp
{

SoundStreamsManager::SoundStreamsManager(QObject* pParent)
   : QObject(pParent)
   , _pSoundStream(nullptr)
{
#ifdef _DEBUG
   _streamMode = SSM_Desktop;
#elif
   _streamMode = SSM_Desktop;
#endif
}

ISoundStream* SoundStreamsManager::getSoundStream()
{
   if (_pSoundStream == nullptr)
   {
      switch (_streamMode)
      {
      case SSM_Desktop:
         {
            _pSoundStream = qobject_cast<ISoundStream*>( new DesktopSoundStream(this) );
         }
         break;
      }
   }

   return _pSoundStream;
}

ISoundStream* SoundStreamsManager::GetSoundStream()
{
   return getSoundStream();
}

} // namespace EarsExApp
