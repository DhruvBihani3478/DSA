#include <iostream>
using namespace std;
int main() {
    char s[20] = "dhruv";
    int m = 0;
    while (s[m] != '\0') m++;    
    for (int i = 0; i <m/2; i++) {  
        swap(s[i],s[m-i-1]);
    }
    cout << s << endl;
    return 0;
}
