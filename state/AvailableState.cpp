#include "AvailableState.h"
#include "../context/ServerContext.h"

void AvailableState::handleDrop(ServerContext *context,
                                const QString *fileName) {
  // Cambia a BUSY e inicia el procesamiento
  context->setState(context->getBusyState());
  context->uploadFile(*fileName);
}
