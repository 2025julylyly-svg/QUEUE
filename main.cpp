#include <iostream>
#include <queue>
#include "Library/QueueFiles/MAIN/Queue.h"

int main() {
    Queue<Queue<int>> q;
    q.Add( Queue<int>({1,2,3}) );
    return 0;
}