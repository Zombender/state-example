#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QProgressBar>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "context/ServerContext.h"
#include "state/ServerState.h"
#include "ui/ServerDropArea.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("State pattern");
  window.resize(650, 400);

  QVBoxLayout *clientLayout = new QVBoxLayout();
  QLabel *clientTitle = new QLabel("<b>Cliente (Archivos Locales)</b>");
  QListWidget *clientList = new QListWidget();
  clientList->setDragEnabled(true);
  clientList->setDragDropMode(QAbstractItemView::DragOnly);
  clientList->setDefaultDropAction(Qt::CopyAction);

  clientList->addItems(
      {"Documento.pdf", "Imagen.png", "Video.mp4", "Datos.csv"});
  clientLayout->addWidget(clientTitle);
  clientLayout->addWidget(clientList);

  QVBoxLayout *serverLayout = new QVBoxLayout();
  QLabel *serverTitle = new QLabel("<b>Servidor (Drag and Drop)</b>");
  QLabel *statusLabel = new QLabel();
  QProgressBar *progressBar = new QProgressBar();
  progressBar->setRange(0, 100);

  QListWidget *serverList = new QListWidget();
  QListWidget *queueList = new QListWidget();

  serverLayout->addWidget(serverTitle);
  serverLayout->addWidget(statusLabel);
  serverLayout->addWidget(new QLabel("Progreso de carga:"));
  serverLayout->addWidget(progressBar);
  serverLayout->addWidget(new QLabel("Archivos Subidos:"));
  serverLayout->addWidget(serverList);
  serverLayout->addWidget(new QLabel("Cola de Espera:"));
  serverLayout->addWidget(queueList);

  ServerContext *server =
      new ServerContext(statusLabel, progressBar, serverList, queueList);

  ServerDropArea *serverDropWidget = new ServerDropArea(server);
  serverDropWidget->setLayout(serverLayout);

  QHBoxLayout *controlLayout = new QHBoxLayout();
  QPushButton *toggleBtn = new QPushButton("Cambiar Estado (Down/Available)");
  QPushButton *resetBtn = new QPushButton("Resetear Simulación");

  controlLayout->addWidget(toggleBtn);
  controlLayout->addWidget(resetBtn);

  QHBoxLayout *mainLayout = new QHBoxLayout();
  QWidget *clientWidget = new QWidget();
  clientWidget->setLayout(clientLayout);

  mainLayout->addWidget(clientWidget, 1);
  mainLayout->addWidget(serverDropWidget, 2);

  QVBoxLayout *rootLayout = new QVBoxLayout(&window);
  rootLayout->addLayout(mainLayout);
  rootLayout->addLayout(controlLayout);

  QObject::connect(toggleBtn, &QPushButton::clicked, [server]() {
    if (server->getCurrentState() == server->getDownState()) {
      server->setState(server->getAvailableState());
    } else {
      server->reset();
    }
  });

  QObject::connect(resetBtn, &QPushButton::clicked, [server, clientList]() {
    server->reset();
    clientList->clear();
    clientList->addItems(
        {"Documento.pdf", "Imagen.png", "Video.mp4", "Datos.csv"});
  });

  window.show();
  return app.exec();
}
