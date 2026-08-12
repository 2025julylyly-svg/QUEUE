#pragma once
#include <initializer_list>

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
public:
    // default constructor
    explicit Queue();
    // init constructor
    explicit Queue(std::initializer_list<value>);
    // copy constructor
    explicit Queue(const Queue&);
    // move constructor
    explicit Queue(Queue&&);
};