#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int temp[1000];
    for(int i = 0; i < n; i++)
        cin >> temp[i];
    int answer[1000] = {0};
    stack<int> s;
    for(int i = n-1; i >= 0; i--) {
        while(!s.empty() && temp[s.top()] <= temp[i])
            s.pop();
        if(!s.empty())
            answer[i] = s.top() - i;
        s.push(i);
    }
    for(int i = 0; i < n; i++)
        cout << answer[i] << " ";
    return 0;
}
