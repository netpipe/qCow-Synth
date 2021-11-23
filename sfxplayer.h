#ifndef SFXPLAYER_H
#define SFXPLAYER_H
 
#include <QObject>
#include "sfxthread.h"
 
class SfxPlayer : public QObject
{
    Q_OBJECT
public:
    explicit SfxPlayer(QObject *parent = 0);
 
signals:
 
public slots:
    void play();
 
private:
    SfxThread _sfxThread;
};
 
#endif // SFXPLAYER_H
