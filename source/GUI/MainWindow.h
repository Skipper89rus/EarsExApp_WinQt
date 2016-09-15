#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "SoundStreams/DesktopSoundStream.h"

namespace EarsExApp {
namespace Ui {
   class MainWindow;
} // namespace Ui
} // namespace EarsExApp

namespace EarsExApp {
namespace GUI {
namespace Desktop {

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   explicit MainWindow(QWidget* pParent = nullptr);
   ~MainWindow();

private slots:
   void on_btnStartStop_clicked(bool bChecked);

   void on_btnSettings_clicked();

private:
   Ui::MainWindow* _pUi;

   DesktopSoundStream* _pSoundStream;
};

} // namespace Desktop
} // namespace GUI
} // namespace EarsExApp

#endif // MAINWINDOW_H
