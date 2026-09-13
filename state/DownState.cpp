#include "DownState.h"
#include "../context/ServerContext.h"

void DownState::handleDrop(ServerContext *context, const QString *fileName) {
  // Si recibe un archivo estando apagado, se levanta a AVAILABLE y procesa el
  // archivo
  context->setState(context->getAvailableState());
  context->getCurrentState()->handleDrop(context, fileName);
}
