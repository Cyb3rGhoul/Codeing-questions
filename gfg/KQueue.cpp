#include <bits/stdc++.h>
using namespace std;

class KQueue
{
    int *arr;
    int *front;
    int *rear;
    int *next;
    int n, k;
    int freeSpot;

    public:
    KQueue(int n, int k){
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++)
        {
            front[i] = rear[i] = -1;
        }

        next = new int[n];

        for (int i = 0; i < n - 1; i++)
        {
            next[i] = i + 1;
        }

        next[n - 1] = -1;
        arr = new int[n];
        freeSpot = 0;
    }

    void enqueue(int item, int qn){

        //overflow
        if (freeSpot == -1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        //find first free index
        int i = freeSpot;

        //update freeSpot
        freeSpot = next[i];


        //check wheather first element is being inserted
        if (front[qn] == -1)
        {
            front[qn] = i;
        }
        else
        {
            //link new element with the previous element
            next[rear[qn]] = i;
        }
        //update next
        next[i] = -1;

        //update rear
        rear[qn] = i;

        //put the item in the array
        arr[i] = item;
    }

    int dequeue(int qn){
        //underflow
        if (front[qn-1] == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        //find index to pop
        int i = front[qn-1];

        //front ko aage badhao
        front[qn-1] = next[i];

        //freeSpot ko manage karo
        next[i] = freeSpot;
        freeSpot = i;
        return arr[i];
    }
};