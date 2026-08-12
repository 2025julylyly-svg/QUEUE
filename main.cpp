#include <iostream>
#include "Library/QueueFiles/MAIN/Queue.h"

int main() {
    Queue<int> q;
    for (int i = 0; i <= 10; i += 2) {
        q.Add( i );
    }
    q.Remove();
    for (const int* it = &q.Front(); it != &q.Back() + 1; ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}