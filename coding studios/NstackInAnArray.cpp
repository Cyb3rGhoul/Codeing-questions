#include <bits/stdc++.h>
class NStack
{
    int *arr;
    int *top;
    int *next;

    int n, s;

    int freeSpot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        s = S;
        n = N;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top ko intialize kardo
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // next ko intialize kardo
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }

        // update last index to -1
        next[s - 1] = -1;

        freeSpot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Check for overflow
        if (freeSpot == -1)
        {
            return false;
        }

        // find index

        int index = freeSpot;

        // update freeSpot

        freeSpot = next[index];

        // insert element to array
        arr[index] = x;

        // update next
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Check underflow
        if (top[m - 1] == -1)
        {
            return -1;
        }

        // ulta kardo upar wala
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};