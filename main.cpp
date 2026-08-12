#include <iostream>
#include "Library/QueueFiles/MAIN/Queue.h"

int main() {
    Queue<int> q;
    for (int i = 0; i < 5; i++) {
        q.Add( i + 1 );
    }
    q.Remove();
    for (int it = q.Front(); it <= q.Back(); ++it) {
        std::cout << it << std::endl;
    }
    return 0;
}