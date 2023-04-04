// Subsequences of the array using the power set alog

#include <iostream>
#include <vector>
using namespace std;
// these is the concept of taking and not taking the element at each position
void printseq(int index, vector<int> &vec, int arr[], int n)
{
    // if we reach till the last index then print the seq
    if (index == n)
    {
        for (auto it : vec)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // Now we have to add the particular element in the list
    // or we can say that   take or pick the particular index in the subsq
    // now  we have to move to next index
    // remove the particular index whhich have been added
    vec.push_back(arr[index]);
    printseq(index + 1, vec, arr, n); 
    vec.pop_back();

    // now we have to specify the condition for not take conddition means the element is not added to the sq 
    printseq(index + 1, vec, arr, n);
}
int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> vec;
    printseq(0, vec, arr, n);
}