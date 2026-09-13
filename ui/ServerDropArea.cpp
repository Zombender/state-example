#include "ServerDropArea.h"
#include "../context/ServerContext.h"
#include "../state/ServerState.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

ServerDropArea::ServerDropArea(ServerContext *ctx, QWidget *parent)
    : QWidget(parent), m_server(ctx) {
  setAcceptDrops(true);
}

void ServerDropArea::dragEnterEvent(QDragEnterEvent *event) {
  if (event->mimeData()->hasText()) {
    event->acceptProposedAction();
  }
}

void ServerDropArea::dropEvent(QDropEvent *event) {
  QString fileName = event->mimeData()->text();
  if (m_server && m_server->getCurrentState()) {
    m_server->getCurrentState()->handleDrop(m_server, &fileName);
  }
  event->acceptProposedAction();
}
