#pragma once
#include <stdexcept>
class EmptyQueueError : public std::logic_error
{
public:
    explicit EmptyQueueError(const char*);
};