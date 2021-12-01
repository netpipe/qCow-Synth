#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sfxplayer.h"

#include "fluidlite.h"
#include <stdlib.h>

#define SAMPLE_RATE 44100
#define SAMPLE_SIZE sizeof(float)
#define NUM_FRAMES SAMPLE_RATE
#define NUM_CHANNELS 2
#define NUM_SAMPLES (NUM_FRAMES * NUM_CHANNELS)

fluid_synth_t* synth;
float* flbuffer;
int audio_channels;


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

    testing();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testing(){
long loops;
int rc;
int size;
// snd_pcm_t *handle;
//   snd_pcm_hw_params_t *params;
unsigned int val;
int dir;
//  snd_pcm_uframes_t frames;
char *buffer2;

//flstuff
  audio_channels = 2;
  fluid_settings_t* settings = new_fluid_settings();
  synth = new_fluid_synth(settings);
 // fluid_synth_sfload(synth, "../sf_/Boomwhacker.sf2", 1);
  fluid_synth_sfload(synth, "./fluidlite/soundfont.sf2", 1);
   flbuffer = (float *)calloc( SAMPLE_SIZE, NUM_SAMPLES );
 //   float* flbuffer = calloc(SAMPLE_SIZE, NUM_SAMPLES);

  fluid_synth_noteon(synth, 0, 80, 127);
 // printf("triggered note\n");
  fluid_synth_noteon(synth, 0, 60, 127);


  //  QCoreApplication b(argc, argv);

    QBuffer *buffer;
    QAudioOutput *a;

    QAudioFormat format;
    format.setSampleRate(44100);
    format.setChannelCount(2);
    format.setSampleSize(32);
    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());
    if (info.isFormatSupported(format))
    {
 //       cout << "Format supported" << endl;
    }
    else
    {
//        cout << "Format not supported" << endl;
    }

    char *data = (char*)malloc(32768 * sizeof(char));

    char charVal[10];

    //4 is mininum width, 3 is precision; float value is copied onto buff



    //generating a sound
    for (int i = 0; i<256; ++i)
    {
        fluid_synth_write_float(synth, NUM_SAMPLES, flbuffer, 0, audio_channels, flbuffer, 0, audio_channels );
// dtostrf(flbuffer, 4, 3, charVal);

        for (int j = 0; j<128; ++j)
        {

            //sprintf(charVal, "%f", flbuffer);
            data[i * 128 + j] = (char)*flbuffer;
        }
    }


    QByteArray result;
    QDataStream s(result);

//int loops2 = 500;
//    while (loops2 > 0) {
//      loops2--;
//    //needs to find a loop somewhere then write it
//    fluid_synth_write_float(synth, NUM_SAMPLES, flbuffer, 0, audio_channels, flbuffer, 0, audio_channels );


//    s << flbuffer;

//}

//     cout << "Created samples" << endl;

    //copying into the buffer
    buffer = new QBuffer;
    buffer->open(QIODevice::ReadWrite);
   //  buffer->setData(result,NUM_SAMPLES); //NUM_FRAMES
    buffer->write(data, 32768);
  //   buffer->write(result, 32768);

    buffer->seek(0);

//     cout << "Filled buffer" << endl;

    //playing
    QThread thr;
    a = new QAudioOutput(format);
    //a->moveToThread(&thr);

    //thr.start();
    //QMetaObject::invokeMethod(a, "start", Q_ARG(QIODevice*, buffer));

    a->start(buffer);

    system("pause");

//    return b.exec();
}
