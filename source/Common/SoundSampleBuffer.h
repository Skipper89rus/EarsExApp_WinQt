#ifndef SOUNDSAMPLEBUFFER_H
#define SOUNDSAMPLEBUFFER_H

#include <QObject>
#include <QByteArray>
#include <QQueue>

namespace EarsExApp
{

class SoundSampleBuffer : public QObject
{
   Q_OBJECT

public:
   SoundSampleBuffer(qint32 maxBuffersNum = 4, qint32 bufferSize = 4096, QObject* pParent = nullptr)
      : QObject(pParent)
      , _maxBuffersNum(maxBuffersNum)
      , _buffersNum(0)
      , _bufferSize(bufferSize)
   {}

   qint32 GetBufferSize() const
   {
      return _bufferSize;
   }

   // Получить свободный буфер для записи.
   // Если все заняты, вернет false.
   bool GetFreeBufferToWrite(char** pData)
   {
      if (_buffersNum >= _maxBuffersNum)
         return false;

      QByteArray buf(_bufferSize, Qt::Uninitialized);
      *pData = buf.data();

      _buffers.enqueue(buf);
      _buffersNum++;
      return true;
   }

   // Получить следующий по очереди буфер на обработку.
   // Если очередь пуста, вернет false.
   bool GetNextBufferToProcess(QByteArray& buf)
   {
      if ( _buffers.empty() )
         return false;

      buf = _buffers.head();
      return true;
   }

   // Получить следующий по очереди буфер на вывод.
   // Если очередь пуста, вернет false.
   bool GetNextBufferToOutput(QByteArray& buf)
   {
      if ( _buffers.empty() )
         return false;

      buf.swap( _buffers.dequeue() );
      _buffersNum--;
      return true;
   }

private:
   qint32 _maxBuffersNum;
   qint32 _bufferSize;

   qint32             _buffersNum;
   QQueue<QByteArray> _buffers;
};

} // namespace EarsExApp

#endif // SOUNDSAMPLEBUFFER_H
