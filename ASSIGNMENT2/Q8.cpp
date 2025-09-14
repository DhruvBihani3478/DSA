#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int arr[] = {1,5,6,2,5,4,7,8,5,7,8,5,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int>nums(arr,arr+n);
    int count=0;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < n; i++) {
        if (i == 0 || nums[i] != nums[i-1]) {  
            cout << nums[i] << " ";
            count++;
        }
    }
    cout<<endl;
    cout<<count;
    return 0;
}
