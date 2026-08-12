#include <iostream>
#include "Library/QueueFiles/MAIN/Queue.h"

int main() {
    Queue<double> q;
    q.Add( 1.1 );
    q.Add( 2.2 );
    q.Add( 3.3 );
    q.Add( 4.4 );
    q.Add( 5.5 );
    q.Add( 6.6 );
    q.Add( 7.7 );
    q.Add( 8.8 );
    q.Add( 9.9 );
    for (const double* it = &q.Front(); it != &q.Back() + 1; ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}