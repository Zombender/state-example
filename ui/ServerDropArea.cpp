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
  if (event->mimeData()->hasText() ||
      event->mimeData()->hasFormat(
          "application/x-qabstractitemmodeldatalist")) {
    event->acceptProposedAction();
  }
}

void ServerDropArea::dropEvent(QDropEvent *event) {
  QString fileName;

  if (event->mimeData()->hasText()) {
    fileName = event->mimeData()->text();
  } else if (event->source()) {
    QListWidget *sourceList = qobject_cast<QListWidget *>(event->source());
    if (sourceList && sourceList->currentItem()) {
      fileName = sourceList->currentItem()->text();
    }
  }

  if (!fileName.isEmpty() && m_server && m_server->getCurrentState()) {
    m_server->getCurrentState()->handleDrop(m_server, &fileName);
  }

  event->acceptProposedAction();
}
