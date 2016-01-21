#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "soundstreams/soundstreamsmanager.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   explicit MainWindow( QWidget* pParent = 0 );
   ~MainWindow();

private slots:
   void on_btnStartStop_clicked( bool bChecked );

private:
   Ui::MainWindow* _pUi;

   EarsExApp::SoundStreamsManager* _pSoundStreamsMgr;
};

#endif // MAINWINDOW_H
