#ifndef SOUNDSTREAMPROCESSORSMANAGER_H
#define SOUNDSTREAMPROCESSORSMANAGER_H

#include <QObject>
#include <QMap>

#include "DesktopSoundStreamProcessors/DesktopSoundStreamProcessorBase.h"

namespace EarsExApp
{

class SoundStreamProcessorsManager : public QObject
{
   Q_OBJECT

public:
   SoundStreamProcessorsManager(QObject* pParent = nullptr)
      : QObject(pParent)
      , _lastProcessorId(0)
   {}

   quint32 AddProcessor(DesktopSoundStreamProcessorBase* pProc)
   {
      _processors[_lastProcessorId++] = pProc;
      return _lastProcessorId;
   }

   bool RemoveProcessor(quint32 procId)
   {
      return _processors.remove(procId) > 0;
   }

   const QList<DesktopSoundStreamProcessorBase*>* GetProcessors() const
   {
      return &_processors.values();
   }

   bool Init() const
   {
      foreach ( DesktopSoundStreamProcessorBase* pProc, _processors.values() )
      {
         if ( !pProc->Init() )
            return false;
      }
      return true;
   }

   void EnableProcessors() const
   {
      foreach ( DesktopSoundStreamProcessorBase* pProc, _processors.values() )
      {
         if ( !pProc->IsEnabled() )
            pProc->Enable();
      }
   }

   void DisableProcessors() const
   {
      foreach ( DesktopSoundStreamProcessorBase* pProc, _processors.values() )
         pProc->Disable();
   }

   void ProcessSample(QByteArray& sample) const
   {
      foreach ( DesktopSoundStreamProcessorBase* pProc, _processors.values() )
         pProc->ProcessSample(sample);
   }

private:
   quint32 _lastProcessorId;
   QMap<quint32, DesktopSoundStreamProcessorBase*> _processors;
};

} // namespace EarsExApp

#endif // SOUNDSTREAMPROCESSORSMANAGER_H
