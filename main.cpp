#include <QApplication>
#include "lines.h"

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  Lines window;

  window.resize(1300, 700);
  window.setWindowTitle("Lines");
  window.show();

  return app.exec();
}
