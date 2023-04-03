#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int count = 0;
// void print()
// {
//     // We are going to use these varible for testing purpose
//     if (count == 5)
//     {
//         return;
//     }
//     else
//     {
//         count++;
//         cout << count << endl;
//         print(); 
//     }
// }
int cntname = 0;
void printname()
{
    if (cntname == 5)
    {
        return;
    }
    else
    {
        cout << "THE ATHARV" << endl;
        cntname++;
        printname();
    }
}
void printn(int i, int n)
{
    if (i > n)
    {
        return;
    }z      
    else
    {
        cout << "Atharv powalkr these is good programmer and has ability to do anything in the life" << endl;
        printn(i + 1, n);
    }
}
void printoneton(int i, int n)
{
    if (i < n)
    {
        return;
    }
    else
    {
        cout << i << endl;
        printoneton(i - 1, n);
    }
}
void backtrackoneton(int i, int n)
{
    if (i < n)
    {
        return;
    }
    else
    {   
        backtrackoneton(i - 1, n);
        // backtrackoneton(3,1)
        // backtrackoneton(2,1)
        // backtrackoneton(1,1)
        cout << i << endl;
    }
}
void backtrack(int i, int n)
{
    if (i > n)
    {
        return;
    }
    else
    {
        backtrack(i + 1, n);
        cout << i << endl;
    }
}
int sumrec(int n, int sum)
{
    if (n < 1)
    {
        return sum;
    }
    else
    {
        sumrec(n - 1, sum + n);
        // sum(3,0)
        // sum(2,3)
        // sum(1,5)
        // sum(0,6)
    }
}
// These is paremeterized recurions
// There are changing the parameters so these is the parameterized recursion
void sumtry(int n, int sum)
{
    if (n < 1)
    {
        cout << sum << endl;
    }
    else
    {
        sumtry(n - 1, sum + n);
    }
}
int sumoo(int n)
{
    if (n == 0)
    {
        return n;
    }
    else
    {
        return n + sumoo(n - 1);
    }
}
int fact(int n)
{
    if (n == 1)
    {
        return n;
    }
    else
    {
        return n * fact(n - 1);
    }
}
// Using the 2 pointer
void revusingrec(int left, int right, int arr[])
{
    if (left >= right)
    {
        return;
    }
    else
    {
        swap(arr[left], arr[right]);
        revusingrec(left + 1, right - 1, arr);
    }
}
// void revarrussingptr(int position, int arr[], int n)
// {
//     if (position > n / 2)
//     {
//         return;
//     }
//     else
//     {
//         // using the single pointer if the pointer crosses the n/2 then we have to stop
//         swap(arr[position], arr[n - position - 1]);
//         revarrussingptr(position + 1);
//     }
// }
bool checkpalin(int i, string &s)
{
    if (i >= s.size() / 2)
    {
        return true;
    }
    if (s[i] != s[s.size() - i - 1])
    {
        return false;
    }
    return checkpalin(i + 1, s);
}
int multiplerec(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int l = multiplerec(n - 1);
    int r = multiplerec(n - 2);
    return l + r;
}
int main()
{
    cout << "We are going to learn the recursion in these tut" << endl;
    // print();
    // printname();
    // printn(1, 5);
    // printoneton(1, 10);
    // printoneto100(1, 100);
    // printoneton(100, 1);
    // backtrackoneton(4, 1);
    // backtrack(1, 4);
    // int sum = sumrec(3, 0);
    // cout << sum << endl;
    // sumtry(20, 0);
    // int t = sumoo(20);
    // cout << t << endl;
    // int f = fact(5);
    // cout << f << endl;

    // int arr[5] = {12, 54, 67, 87, 34};
    // int n = 5;
    // revusingrec(0, n - 1, arr);
    // cout << "Aarray after swapping" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    // cout << "Successfully" << endl;

    // These is functional recursive function
    string store = "madam";
    if (checkpalin(0, store))
    {
        cout << "THESE IS " << endl;
    }
    else
    {
        cout << "THESE IS NOT" << endl;
    }

    int result = multiplerec(9);
    cout << result << endl;
}