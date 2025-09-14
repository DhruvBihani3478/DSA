#include <iostream>
#include <algorithm>
using namespace std;
int main() {
   string s="car";
   string t="arc";
   int n=s.size();
   int m=t.size();
   bool flag=true;
   if(n!=m) {
    cout<<"not Anangrams";
    return 0;}
   sort(s.begin(),s.end());
   sort(t.begin(),t.end());
   for(int i=0;i<n;i++){
    if(s[i]!=t[i]){
        cout<<"not Anangrams";
        flag=false;
        break;}
   }
   if(flag)cout<<"Anangrams";
   return 0;
}
