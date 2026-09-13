#include "BusyState.h"
#include "../context/ServerContext.h"

void BusyState::handleDrop(ServerContext *context, const QString *fileName) {
  // Si está ocupado, encola el archivo
  context->enqueueFile(*fileName);
}
