//https://qtsource.wordpress.com/2011/09/12/multithreaded-audio-using-qaudiooutput/
#include <QFile>
#include <QApplication>
#include "sfxthread.h"
 
SfxThread::SfxThread(QObject *parent) :
    QThread(parent)
{ 
 //   ...do precaching etc of the sounds here
 
    start();
 
    // Move event processing of SfxThread to this thread
    QObject::moveToThread(this);
}
 
SfxThread::~SfxThread()
{
    quit();
    wait();
}
 
void SfxThread::play()
{
  //  playlist.append(...);
  //  playNext();
}

// Plays the next file from queue
void SfxThread::playNext()
{
    if (playlist.length() == 0 || _ao->state() == QAudio::ActiveState) {
        return;
    }
    _ao->stop();
    _buf.close();
 //   play(playlist.dequeue());
}
 
void SfxThread::play(QString& filename)
{
    QFile file(filename.toLatin1());
    file.open(QIODevice::ReadOnly);
    QByteArray *ptr = new QByteArray(file.readAll());

    _buf.setBuffer(ptr);
    _buf.open(QIODevice::ReadOnly);

    _ao->setBufferSize(_buf.size());
    _ao->start(&_buf);
}
 
void SfxThread::playerStateChanged(QAudio::State state)
{
    // Play finished, play next clip
    if (state == QAudio::IdleState)
    {
        playNext();
    }
}
 
void SfxThread::run()
{
   // ...set audio format here (_af.setCodec etc)
     
    _ao = new QAudioOutput(_af);
 
    connect(_ao, SIGNAL(stateChanged(QAudio::State)), this, SLOT(playerStateChanged(QAudio::State)));
 
    exec();
}
