#include <QApplication>
#include "GUI/MainWindow.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   EarsExApp::GUI::Desktop::MainWindow mainWnd;
   // MainWindow не должен знать о менеджере!
   // TODO: их общение должно происходить через сигналы/слоты
   mainWnd.show();
   return a.exec();
}
