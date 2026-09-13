#ifndef AVAILABLESTATE_H
#define AVAILABLESTATE_H

#include "ServerState.h"

class AvailableState : public ServerState {
public:
  void handleDrop(ServerContext *context, const QString *filename) override;
  QString name() const override { return "AVAILABLE (disponible)"; }
  QString color() const override {
    return "background-color: #4CAF50; color: white;";
  }
};

#endif // !AVAILABLESTATE_H
