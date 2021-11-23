#ifndef SFXTHREAD_H
#define SFXTHREAD_H
 
#include <QThread>
#include <QAudioOutput>
#include <QBuffer>
#include <QQueue>
 
class SfxThread : public QThread
{
    Q_OBJECT
public:
    explicit SfxThread(QObject *parent = 0);
    ~SfxThread();
    void run();
 
signals:
 
public slots:
    void play();
    void playerStateChanged(QAudio::State state);
private:
    void playNext();
    void play(QString& filename);
 
    QAudioOutput *_ao;
    QAudioFormat _af;
    QBuffer _buf;
 
    QQueue<QString> playlist;
};
 
#endif // SFXTHREAD_H
