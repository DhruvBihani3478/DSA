#include <iostream>
using namespace std;
int inversions(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (i < i + 1 && arr[i] > arr[i + 1])
            count++;
    }
    return count;
}
int main()
{
    int count = 0;
    int arr[5] = {4, 3, 1, 2, 0};
    cout << "Number of inversions are:" << inversions(arr, 5);
}