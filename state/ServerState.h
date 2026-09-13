#ifndef SERVERSTATE_H
#define SERVERSTATE_H

#include <QString>

class ServerContext;

class ServerState {
public:
  virtual ~ServerState() = default;
  virtual void handleDrop(ServerContext *context, const QString *fileName) = 0;
  virtual QString name() const = 0;
  virtual QString color() const = 0;
};
#endif // !DEBUG
