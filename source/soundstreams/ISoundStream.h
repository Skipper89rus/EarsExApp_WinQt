#ifndef ISOUNDSTREAM_H
#define ISOUNDSTREAM_H

#include "SoundStreamProcessors/ISoundStreamProcessor.h"

namespace EarsExApp
{

class ISoundStream
{
public:
   // Запуск/остановка потока звука
   virtual void Start()            = 0;
   virtual void Stop()             = 0;
   virtual bool IsStarted() const  = 0;

   // Обработчики потока
   virtual unsigned int GetAvailableProcessors(ISoundStreamProcessor** ppProcessors) = 0;
};

} // namespace EarsExApp

#endif // ISOUNDSTREAM_H
