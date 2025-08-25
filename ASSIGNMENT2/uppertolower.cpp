#include <iostream>
using namespace std;
int main() {
    char s[20] = "raghav";
    int m = 0;
    while (s[m] != '\0') m++;  
    for(int i=0;i<m;i++){
        if(s[i]>='a' && s[i]<='z') s[i]-=32;
        else if (s[i]>='A' && s[i]<='Z') s[i]+=32;
        {
            /* code */
        }
        
    }
    cout << s << endl;
    return 0;
}
