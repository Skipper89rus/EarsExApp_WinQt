#ifndef ISOUNDSTREAM_H
#define ISOUNDSTREAM_H

namespace EarsExApp
{

class ISoundStream
{
public:
   // Запуск/остановка потока звука
   virtual void Start() = 0;
   virtual void Stop()  = 0;

   // Добавить обработчик потока (возвращает его id)
   virtual quint32 AddProcessor() = 0;
   // Убрать обработчик потока по id
   virtual void RemoveProcessor( quint32 processorId ) = 0;
};

} // namespace EarsExApp

Q_DECLARE_INTERFACE(EarsExApp::ISoundStream, "EarsExApp.ISoundStream")

#endif // ISOUNDSTREAM_H
