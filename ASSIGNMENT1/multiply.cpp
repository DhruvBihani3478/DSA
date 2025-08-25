#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int arr[2][3]={1,2,3,4,5,6};
    int brr[3][2]={1,2,3,4,5,6};
    int crr[2][3];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            crr[i][j]=0;
            for(int k=0;k<3;k++){
            crr[i][j]+=arr[i][k]*brr[k][j];}}}
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<crr[i][j]<<" ";}
        cout<<endl;}
    }
