#include <iostream>
using namespace std;
int main() {
    int target;
    cout << "Enter target number: ";
    cin >> target;
    int arr[] = {1,2,2,3,3,3,3,4,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0, high = n - 1;
    int result = -1; 
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target && arr[mid]==arr[mid-1]) high = mid - 1;
        else if (arr[mid] == target && arr[mid]!=arr[mid-1]) {
            result=mid;
            break;}
        else if(arr[mid]<target) low=mid+1;
        else high=mid-1;
    }
    cout<<result;
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
