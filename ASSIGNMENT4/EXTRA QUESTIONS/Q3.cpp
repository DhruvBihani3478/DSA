#include<iostream>
#include<queue>
#include<stack>
using namespace std;

bool checkSorted(queue<int>& q){
    stack<int> s;
    int expected=1;
    int n=q.size();

    while(!q.empty()){
        int curr=q.front();
        q.pop();

        if(curr==expected){
            expected++;
        }
        else{
            while(!s.empty() && s.top()==expected){
                s.pop();
                expected++;
            }
            if(!s.empty() && s.top()<curr) return false;
            s.push(curr);
        }
    }

    while(!s.empty() && s.top()==expected){
        s.pop();
        expected++;
    }

    return (expected==n+1);
}

int main(){
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    if(checkSorted(q)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
