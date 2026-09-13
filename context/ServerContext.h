#ifndef SERVERCONTEXT_H
#define SERVERCONTEXT_H

#include <QLabel>
#include <QListWidget>
#include <QProgressBar>
#include <QQueue>
#include <QTimer>
#include <memory>
#include <qcontainerfwd.h>
#include <qlistwidget.h>
#include <qobject.h>
#include <qtmetamacros.h>
class ServerState;

class ServerContext : public QObject {
  Q_OBJECT
public:
  ServerContext(QLabel *statusLabel, QProgressBar *QProgressBar,
                QListWidget *serverList, QListWidget *queueList);
  void setState(std::shared_ptr<ServerState> newState);
  void uploadFile(const QString &fileName);
  void enqueueFile(const QString &fileName);
  void reset();

  std::shared_ptr<ServerState> getCurrentState() const {
    return m_currentState;
  }
  std::shared_ptr<ServerState> getDownState() const { return m_downState; }
  std::shared_ptr<ServerState> getAvailableState() const {
    return m_availableState;
  }
  std::shared_ptr<ServerState> getBusyState() const { return m_busyState; }

private:
  QLabel *m_statusLabel;
  QProgressBar *m_progressBar;
  QListWidget *m_serverList;
  QListWidget *m_queueList;

  QQueue<QString> m_fileQueue;
  QTimer m_uploadTimer;
  QString m_currentFileProcessing;

  std::shared_ptr<ServerState> m_currentState;
  std::shared_ptr<ServerState> m_downState;
  std::shared_ptr<ServerState> m_availableState;
  std::shared_ptr<ServerState> m_busyState;
};
#endif // !DEBUG
