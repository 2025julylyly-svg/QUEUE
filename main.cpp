#include <iostream>
#include "Library/QueueFiles/MAIN/Queue.h"

int main() {
    Queue<Queue<int>> q;
    q.Add( Queue<int>({1,2,3}) );
    Queue<int> q2 (q.Front());
    std::cout << *(&q2.Back() - 1) << std::endl;
    return 0;
}