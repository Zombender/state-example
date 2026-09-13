#ifndef SERVERDROPAREA_H
#define SERVERDROPAREA_H

#include <QWidget>

class ServerContext;

class ServerDropArea : public QWidget {
  Q_OBJECT
public:
  explicit ServerDropArea(ServerContext *ctx, QWidget *parent = nullptr);

protected:
  void dragEnterEvent(QDragEnterEvent *event) override;
  void dropEvent(QDropEvent *event) override;

private:
  ServerContext *m_server;
};

#endif // SERVERDROPAREA_H
