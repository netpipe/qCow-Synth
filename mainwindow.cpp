#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sfxplayer.h"

SfxPlayer::SfxPlayer(QObject *parent)
    : QObject(parent)
{

}

void SfxPlayer::play()
{
    // Call playInternal of SfxThread (and invoke it in the other thread)
    QMetaObject::invokeMethod(&_sfxThread, "play", Qt::QueuedConnection);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
