#include <iostream>
using namespace std;
int main() {
    char s[20] = "dhruv";
    int m = 0;
    while (s[m] != '\0') m++;  
    for(int i=0;i<m;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='u'){
            s[i]=s[i+1];
            m--;
        }
    }
    for(int i=0;i<m;i++){
        cout<<s[i];
    }
    return 0;
}
