#include <iostream>
#include <queue>
#include "Library/QueueFiles/MAIN/Queue.h"

int main() {
    std::queue<std::queue<int>> q;
    q.push( std::queue<int>({1,2,3}) );
    return 0;
}