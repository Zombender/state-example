#ifndef BUSYSTATE_H
#define BUSYSTATE_H

#include "ServerState.h"

class BusyState : public ServerState {
public:
  void handleDrop(ServerContext *context, const QString *filename) override;
  QString name() const override { return "BUSY (procesando)"; }
  QString color() const override {
    return "background-color: #FF9800; color: white;";
  }
};

#endif // !BUSYSTATE_H
