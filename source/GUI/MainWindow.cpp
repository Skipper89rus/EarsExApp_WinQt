#include "GUI/MainWindow.h"
#include "ui_MainWindow.h"

namespace EarsExApp {
namespace GUI {
namespace Desktop {

MainWindow::MainWindow(QWidget *pParent)
   : QMainWindow(pParent)
   , _pUi( new EarsExApp::Ui::MainWindow )
   , _pSoundStream( new EarsExApp::DesktopSoundStream(this) )
{
   _pUi->setupUi(this);
}

MainWindow::~MainWindow()
{
   delete _pSoundStream;
   delete _pUi;
}

void MainWindow::on_btnStartStop_clicked(bool bChecked)
{
    if (bChecked)
    {
       if ( !_pSoundStream->IsStarted() )
       {
         _pUi->btnStartStop->setText("Stop");
         _pSoundStream->Start();
       }
    }
    else
    {
       _pUi->btnStartStop->setText("Start");
       _pSoundStream->Stop();
    }
}

void MainWindow::on_btnSettings_clicked()
{

}

} // namespace Desktop
} // namespace GUI
} // namespace EarsExApp
