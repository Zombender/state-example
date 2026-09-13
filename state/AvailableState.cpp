#include "AvailableState.h"
#include "../context/ServerContext.h"
#include <qlogging.h>

void AvailableState::handleDrop(ServerContext *context,
                                const QString *fileName) {
  context->setState(context->getBusyState());
  context->uploadFile(*fileName);
}
