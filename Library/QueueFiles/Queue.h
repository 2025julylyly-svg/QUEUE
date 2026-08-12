#pragma once

template <typename value>
class Queue
{
private:
    using pointer = value*;
    using const_pointer = const value*;
    using reference = value&;
    using const_reference = const value&;
private:
    pointer queue;
};