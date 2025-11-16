#include<iostream>
using namespace std;

void countingSort(int a[], int n) {
    int max = a[0];
    for(int i=1;i<n;i++) if(a[i] > max) max = a[i];
    int cnt[max+1];
    for(int i=0;i<=max;i++) cnt[i] = 0;
    for(int i=0;i<n;i++) cnt[a[i]]++;
    int k = 0;
    for(int i=0;i<=max;i++) {
        while(cnt[i]--) {
            a[k++] = i;
        }
    }
}

int main() {
    int a[] = {4,2,2,8,3,3,1};
    int n = sizeof(a)/sizeof(a[0]);
    countingSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
