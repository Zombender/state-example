#include "ServerContext.h"
#include "../state/AvailableState.h"
#include "../state/BusyState.h"
#include "../state/DownState.h"
#include <memory>
#include <qlabel.h>
#include <qlistwidget.h>

ServerContext::ServerContext(QLabel *statusLabel, QProgressBar *progressBar,
                             QListWidget *serverList, QListWidget *queueList)
    : m_statusLabel(statusLabel), m_progressBar(progressBar),
      m_serverList(serverList), m_queueList(queueList) {

  m_downState = std::make_shared<DownState>();
  m_availableState = std::make_shared<AvailableState>();
  m_busyState = std::make_shared<BusyState>();

  setState(m_downState);
  connect(&m_uploadTimer, &QTimer::timeout, this, [this]() {
    int val = m_progressBar->value() + 10;
    if (val <= 100) {
      m_progressBar->setValue(val);
    } else {
      m_uploadTimer.stop();
      m_serverList->addItem(m_currentFileProcessing);
      m_progressBar->setValue(0);

      if (!m_fileQueue.isEmpty()) {
        QString nextFile = m_fileQueue.dequeue();
        delete m_queueList->takeItem(0);
        uploadFile(nextFile);
      } else {
        setState(m_availableState);
      }
    }
  });
}
void ServerContext::setState(std::shared_ptr<ServerState> newState) {
  m_currentState = newState;
  m_statusLabel->setText(m_currentState->name());
  m_statusLabel->setStyleSheet(
      QString("font-weight: bold; padding: 5px; border-radius: 3px; %1")
          .arg(m_currentState->color()));
}
void ServerContext::uploadFile(const QString &fileName) {
  m_currentFileProcessing = fileName;
  m_progressBar->setValue(0);
  m_uploadTimer.start(150);
}

void ServerContext::enqueueFile(const QString &fileName) {
  m_fileQueue.enqueue(fileName);
  m_queueList->addItem(fileName);
}
void ServerContext::reset() {
  m_uploadTimer.stop();
  m_fileQueue.clear();
  m_queueList->clear();
  m_serverList->clear();
  m_progressBar->setValue(0);
  setState(m_downState);
}
