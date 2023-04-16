#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int mima(int depth, int nodeIndex, bool isMaximum, int leaves[], int height)
{
    // if we reach till the dept of the node
    if (depth == height)
    {
        return leaves[nodeIndex];
    }

    // Now if the current move is of max then find the max value
    int firstmax = mima(depth + 1, nodeIndex * 2, false, leaves, height);
    int secondmax = mima(depth + 1, nodeIndex * 2 + 1, false, leaves, height);
    int firstmin = mima(depth + 1, nodeIndex * 2, true, leaves, height);
    int secondmin = mima(depth + 1, nodeIndex * 2 + 1, true, leaves, height);

    // If the current move is of max move then if is executed
    if (isMaximum)
    {
        return max(firstmax, secondmax);
    }
    // if the current move is of minimum then else
    else
    {
        return min(firstmin, secondmin);
    }
}
// if n is true then 0 and if n is not true then again log of n/2
int logtwo(int n)
{
    return (n == 1) ? 0 : 1 + logtwo(n / 2);
}
int main()
{
    int leaves[] = {3, 5, 2, 9, 12, 5, 23, 23};
    int n = sizeof(leaves) / sizeof(leaves[0]);
    int hei = logtwo(n);
    int store_result = mima(0, 0, true, leaves, hei);
    cout << "The final optimal value is" << store_result << endl;
    return 0;
}