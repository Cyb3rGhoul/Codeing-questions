#include <bits/stdc++.h>
using namespace std;
/*
********What are Queues?
Queues are a type of container adaptors which operate in a first in first out (FIFO) type of arrangement. Elements are inserted at the back (end) and are deleted from the front.

*********Operations on Queue:
Mainly the following four basic operations are performed on queue:
Enqueue: Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition.
Dequeue: Removes an item from the queue. The items are popped in the same order in which they are pushed. If the queue is empty, then it is said to be an Underflow condition.
Front: Get the front item from the queue.
isEmpty: Check whether the queue is empty or not.

*********The syntax for declaring a queue is:
queue <int> q;


*********There is something called input restricted queue and output restricted queue.

Input Restricted Queue: In input restricted queue, the input can be done from only one end but output can be done from both ends.
eg: q.push_front()
    q.pop_back()
    q.pop_front()

Output Restricted Queue: In output restricted queue, the output can be done from only one end but input can be done from both ends.
*/
class Queue
{
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    Queue()
    {
        size = 10001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        if (qfront == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
        if (rear == size)
        {
            cout << "Queue is full";
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        // Implement the dequeue() function
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        // Implement the front() function
        if (qfront == rear)
        {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};