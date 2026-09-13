#include "BusyState.h"
#include "../context/ServerContext.h"
#include <QDebug>
void BusyState::handleDrop(ServerContext *context, const QString *fileName) {
  context->enqueueFile(*fileName);
}
