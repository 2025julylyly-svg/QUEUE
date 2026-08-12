#include "IsEmptyQueueError.h"

EmptyQueueError::EmptyQueueError(const char* msg) : std::logic_error( msg ) {}