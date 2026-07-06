#include <iostream>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

// ── 1. QUEUE BASICS ───────────────────────────────────────────────────────────
// FIFO — First In First Out
// push() adds to back, pop() removes from front
void queueBasics()
{
    cout << "── Queue Basics ──" << endl;
    queue<int> q;
    
    q.push(10);         // enqueue
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;  // 10
    cout << "Back:  " << q.back()  << endl;  // 30
    cout << "Size:  " << q.size()  << endl;  // 3
    cout << "Empty: " << q.empty() << endl;  // 0 (false)

    q.pop();            // dequeue — removes 10
    cout << "After pop, Front: " << q.front() << endl; // 20

    cout << "Traverse: ";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl << endl;
}

// ── 2. PRIORITY QUEUE (MAX HEAP) ─────────────────────────────────────────────
// Largest element always at top
void priorityQueueMax()
{
    cout << "── Priority Queue (Max Heap) ──" << endl;
    priority_queue<int> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "Top (max): " << pq.top() << endl;  // 50

    cout << "Sorted descending: ";
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl << endl;
}

// ── 3. PRIORITY QUEUE (MIN HEAP) ─────────────────────────────────────────────
// Smallest element always at top
void priorityQueueMin()
{
    cout << "── Priority Queue (Min Heap) ──" << endl;
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(20);

    cout << "Top (min): " << pq.top() << endl;  // 10

    cout << "Sorted ascending: ";
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl << endl;
}

// ── 4. DEQUE (DOUBLE-ENDED QUEUE) ────────────────────────────────────────────
// Can push/pop from both front and back
void dequeDemo()
{
    cout << "── Deque (Double-Ended Queue) ──" << endl;
    deque<int> dq;

    dq.push_back(20);   // add to back
    dq.push_front(10);  // add to front
    dq.push_back(30);   // add to back

    cout << "Front: " << dq.front() << endl;  // 10
    cout << "Back:  " << dq.back()  << endl;  // 30

    dq.pop_front();     // removes 10
    dq.pop_back();      // removes 30

    cout << "After pops, Front: " << dq.front() << endl;  // 20

    cout << "Traverse: ";
    for(int x : dq) cout << x << " ";
    cout << endl << endl;
}

// ── 5. IMPLEMENT QUEUE USING TWO STACKS ──────────────────────────────────────
// Classic interview question — simulate FIFO using two LIFO stacks
class MyQueue
{
    stack<int> inbox;   // for push
    stack<int> outbox;  // for pop/peek

    void transfer()     // move inbox -> outbox when outbox is empty
    {
        if(outbox.empty())
            while(!inbox.empty())
            {
                outbox.push(inbox.top());
                inbox.pop();
            }
    }

public:
    void push(int val)  { inbox.push(val); }

    void pop()
    {
        transfer();
        outbox.pop();
    }

    int front()
    {
        transfer();
        return outbox.top();
    }

    bool empty() { return inbox.empty() && outbox.empty(); }
};

void queueUsingStacks()
{
    cout << "── Queue Using Two Stacks ──" << endl;
    MyQueue mq;
    mq.push(1);
    mq.push(2);
    mq.push(3);

    cout << "Front: " << mq.front() << endl;  // 1
    mq.pop();
    cout << "After pop, Front: " << mq.front() << endl;  // 2
    cout << endl;
}

// ── 6. CIRCULAR QUEUE (fixed size array) ─────────────────────────────────────
class CircularQueue
{
    vector<int> arr;
    int head, tail, size, capacity;

public:
    CircularQueue(int k) : arr(k), head(0), tail(0), size(0), capacity(k) {}

    bool enqueue(int val)
    {
        if(size == capacity) return false;  // full
        arr[tail] = val;
        tail = (tail + 1) % capacity;
        size++;
        return true;
    }

    bool dequeue()
    {
        if(size == 0) return false;  // empty
        head = (head + 1) % capacity;
        size--;
        return true;
    }

    int front()  { return size == 0 ? -1 : arr[head]; }
    int rear()   { return size == 0 ? -1 : arr[(tail - 1 + capacity) % capacity]; }
    bool empty() { return size == 0; }
    bool full()  { return size == capacity; }
};

void circularQueueDemo()
{
    cout << "── Circular Queue ──" << endl;
    CircularQueue cq(4);

    cq.enqueue(1);
    cq.enqueue(2);
    cq.enqueue(3);
    cq.enqueue(4);

    cout << "Front: " << cq.front() << endl;  // 1
    cout << "Rear:  " << cq.rear()  << endl;  // 4
    cout << "Full:  " << cq.full()  << endl;  // 1 (true)

    cq.dequeue();
    cq.enqueue(5);  // wraps around

    cout << "After dequeue + enqueue(5), Front: " << cq.front() << endl;  // 2
    cout << "Rear: " << cq.rear() << endl;  // 5
    cout << endl;
}

int main()
{
    queueBasics();
    priorityQueueMax();
    priorityQueueMin();
    dequeDemo();
    queueUsingStacks();
    circularQueueDemo();
    return 0;
}
