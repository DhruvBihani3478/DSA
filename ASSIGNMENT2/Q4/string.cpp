#include <iostream>
using namespace std;
int main() {
    char s[20] = "dhruv ";
    char t[] = "bihani";
    int m = 0;
    while (s[m] != '\0') m++;  
    int n = 0;
    while (t[n] != '\0') n++;  
    for (int i = 0; i <= n; i++) {  
        s[m + i] = t[i];
    }
    cout << s << endl;
    return 0;
}
