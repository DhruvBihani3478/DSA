#include<iostream>
using namespace std;

void countingSort(int a[], int n, int exp) {
    int out[n], cnt[10] = {0};
    for(int i=0;i<n;i++) cnt[(a[i]/exp)%10]++;
    for(int i=1;i<10;i++) cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--) {
        int d = (a[i]/exp)%10;
        out[cnt[d]-1] = a[i];
        cnt[d]--;
    }
    for(int i=0;i<n;i++) a[i] = out[i];
}

void radixSort(int a[], int n) {
    int mx = a[0];
    for(int i=1;i<n;i++) if(a[i] > mx) mx = a[i];
    for(int exp=1; mx/exp>0; exp*=10) countingSort(a,n,exp);
}

int main() {
    int a[] = {170,45,75,90,802,24,2,66};
    int n = sizeof(a)/sizeof(a[0]);
    radixSort(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
