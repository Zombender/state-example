#include "DownState.h"
#include "../context/ServerContext.h"
#include <QDebug>
void DownState::handleDrop(ServerContext *context, const QString *fileName) {
  context->setState(context->getAvailableState());
  context->getCurrentState()->handleDrop(context, fileName);
}
