#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[1000];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    stack<int> s;
    int nge[1000];
    for(int i = n-1; i >= 0; i--) {
        while(!s.empty() && s.top() <= arr[i])
            s.pop();
        if(s.empty())
            nge[i] = -1;
        else
            nge[i] = s.top();
        s.push(arr[i]);
    }
    for(int i = 0; i < n; i++)
        cout << nge[i] << " ";
    return 0;
}
