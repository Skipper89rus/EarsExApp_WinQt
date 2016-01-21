#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget *pParent )
   : QMainWindow(pParent)
   , _pUi(new Ui::MainWindow)
   , _pSoundStreamsMgr( new EarsExApp::SoundStreamsManager(this) )
{
   _pUi->setupUi(this);
}

MainWindow::~MainWindow()
{
   delete _pSoundStreamsMgr;
   delete _pUi;
}

void MainWindow::on_btnStartStop_clicked( bool bChecked )
{
    if (bChecked)
    {
       _pUi->btnStartStop->setText("Stop");
       _pSoundStreamsMgr->GetSoundStream()->Start();
    }
    else
    {
       _pUi->btnStartStop->setText("Start");
       _pSoundStreamsMgr->GetSoundStream()->Stop();
    }
}
