#include <QApplication>
#include <QDialog>
#include <qapplication.h>

#include "view/designer.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QDialog dialog;
  Ui::Dialog ui;
  ui.setupUi(&dialog);
  dialog.show();
  return app.exec();
}
