#include <iostream>
using namespace std;
int main() {
    int target;
    cout << "Enter target number: ";
    cin >> target;
    int arr[6] = {8, 9, 45, 56, 78, 93};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0, high = n - 1;
    int result = -1; 
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            result = mid; 
            break;}
        else if (arr[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
