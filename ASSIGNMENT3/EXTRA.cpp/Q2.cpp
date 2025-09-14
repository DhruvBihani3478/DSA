#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<long long> s;
    long long minEle;
public:
    void push(long long x) {
        if(s.empty()) {
            s.push(x);
            minEle = x;
        } else {
            if(x < minEle) {
                s.push(2*x - minEle);
                minEle = x;
            } else s.push(x);
        }
    }
    
    void pop() {
        if(s.empty()) return;
        long long t = s.top();
        s.pop();
        if(t < minEle) minEle = 2*minEle - t;
    }
    
    long long top() {
        long long t = s.top();
        if(t < minEle) return minEle;
        return t;
    }
    
    long long getMin() {
        return minEle;
    }
};

int main() {
    MinStack st;
    st.push(3);
    st.push(5);
    cout << st.getMin() << "\n";
    st.push(2);
    st.push(1);
    cout << st.getMin() << "\n";
    st.pop();
    cout << st.getMin() << "\n";
    st.pop();
    cout << st.top() << "\n";
    cout << st.getMin() << "\n";
    return 0;
}
