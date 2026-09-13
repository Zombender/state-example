#ifndef DOWNSTATE_H
#define DOWNSTATE_H

#include "ServerState.h"

class DownState : public ServerState {
public:
  void handleDrop(ServerContext *context, const QString *filename) override;
  QString name() const override { return "DOWN (apagado)"; }
  QString color() const override {
    return "background-color: #f44336; color: white;";
  }
};

#endif // !DROPSTATE_H
