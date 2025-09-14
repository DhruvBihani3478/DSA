#include <iostream>
using namespace std;
int main() {
    char s[20] = "raghav";
    int m = 0;
    while (s[m] != '\0') m++;  
    for(int i=0;i<m-1;i++){
        bool flag =true;
        for(int j=0;j<m-1;j++){
            if(s[j]>s[j+1]){
            swap (s[j],s[j+1]);
            flag=false;}
        }
        if(flag) break;
    }
    cout << s << endl;
    return 0;
}
