#pragma once
#include <initializer_list>

template<typename value>
class Queue
{
private:
    using pointer = value*;
    using reference = value&;
    using const_reference = const value&;

private: // elements
    pointer queue;
    std::size_t ElementNumber;
    std::size_t Capacity;

private: // functions
    void Resize() {
        Capacity *= 2;
        pointer AuxiliaryQueue = new value[Capacity];
        for (std::size_t i = 0; i < ElementNumber; ++i) {
            *(AuxiliaryQueue + i) = *(queue + i);
        }
        delete[] queue;
        queue = AuxiliaryQueue;
    }

public:
    // default constructor
    explicit Queue() {
        ElementNumber = 0;
        Capacity = 2;
        queue = new value[Capacity];
    }

    // init constructor
    explicit Queue(const std::initializer_list<value>&& init) {}
    explicit Queue(const std::initializer_list<value>&);
    // copy constructor
    explicit Queue(const Queue&);
    // move constructor
    explicit Queue(Queue&&);
    ///////////////
    // functions //
    ///////////////
    reference Front() {
        return queue[0];
    }

    const_reference Front() const {
        return queue[0];
    }

    reference Back() {
        return queue[ElementNumber - 1];
    }

    const_reference Back() const {
        return queue[ElementNumber - 1];
    }

    [[nodiscard]] bool IsEmpty() const {
        return ElementNumber == 0;
    }

    [[nodiscard]] bool IsFull() const {
        return ElementNumber == Capacity;
    }

    void Add(value elem) {
        if (this->IsFull()) {
            this->Resize();
        }
        this->queue[ElementNumber++] = elem;
    }

    void Remove() {}
};