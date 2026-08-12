#pragma once
#include <initializer_list>
#include <iostream>
#include "../Errors/IsEmptyQueueError.h"

template<typename value>
class Queue final
{
private:
    using pointer = value*;
    using reference = value&;
    using const_reference = const value&;

private: // elements
    pointer queue;
    pointer AuxiliaryQueue;
    std::size_t ElementNumber;
    std::size_t Capacity;

private: // functions
    void Resize() {
        Capacity *= 2;
        AuxiliaryQueue = new value[Capacity];
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
        AuxiliaryQueue = queue;
    }

    // init constructor
    explicit Queue(const std::initializer_list<value>&& init) {
        this->ElementNumber = init.size();
        this->Capacity = ElementNumber <= 1 ? 2 : ElementNumber * 2;
        this->queue = new value[Capacity];
        int index = 0;
        for (const value& elem : init) {
            *(queue + index++) = elem;
        }
        AuxiliaryQueue = queue;
    }

    explicit Queue(const std::initializer_list<value>& init) {
        this->ElementNumber = init.size();
        this->Capacity = ElementNumber == 0 ? 2 : ElementNumber * 2;
        this->queue = new value[Capacity];
        std::size_t index = 0;
        for (const value& elem : init) {
            *(queue + index++) = elem;
        }
        AuxiliaryQueue = queue;
    }

    // copy constructor
    explicit Queue(const Queue& other) {
        this->ElementNumber = other.ElementNumber;
        this->Capacity = other.Capacity;
        this->queue = new value[Capacity];
        for (int i = 0; i < ElementNumber; ++i) {
            *(queue + i) = *(other.queue + i);
        }
        AuxiliaryQueue = queue;
    }

    // move constructor
    explicit Queue(Queue&& other) noexcept {
        this->ElementNumber = other.ElementNumber;
        this->Capacity = other.Capacity;
        this->queue = other.queue;
        this->AuxiliaryQueue = other.AuxiliaryQueue;

        other.ElementNumber = 0;
        other.Capacity = 0;
        delete[] other.queue;
        other.queue = nullptr;
        other.AuxiliaryQueue = nullptr;
    }

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

    void Add(value& elem) {
        if (this->IsFull()) {
            this->Resize();
        }
        this->queue[ElementNumber++] = elem;
    }
    void Add(value&& elem) {
        if (this->IsFull()) {
            this->Resize();
        }
        this->queue[ElementNumber++] = elem;
    }

    void Remove() {
        try {
            if (this->IsEmpty()) {
                throw EmptyQueueError( "queue is empty" );
            }
            AuxiliaryQueue = new value[Capacity];
            for (std::size_t i = 1; i < ElementNumber; ++i) {
                AuxiliaryQueue[i - 1] = queue[i];
            }
            --ElementNumber;
            delete[] queue;
            queue = AuxiliaryQueue;
        } catch (const EmptyQueueError& e) {
            std::cerr << "Error: " << e.what();
            std::cout << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what();
            std::cout << std::endl;
        }
    }
    Queue& operator= (const Queue& other) {
        if (this == &other) {
            return *this;
        }
        delete[] this->queue;
        this->Capacity = other.Capacity;
        this->ElementNumber = other.ElementNumber;
        this->queue = new value[Capacity];
        for (std::size_t i = 0; i < ElementNumber; ++i) {
            *(queue + i) = *(other.queue + i);
        }
        AuxiliaryQueue = queue;
        return *this;
    }
    ~Queue() {
        delete[] queue;
    }
};