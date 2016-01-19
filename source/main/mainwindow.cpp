#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow( QWidget *pParent )
   : QMainWindow(pParent)
   , _pUi(new Ui::MainWindow)
{
   _pUi->setupUi(this);
}

MainWindow::~MainWindow()
{
   delete _pUi;
}
