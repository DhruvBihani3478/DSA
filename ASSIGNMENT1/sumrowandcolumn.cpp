// question 3-10000
// int main()
// {
// int i;
// int arr[5] = {1};
// for (i = 0; i < 5; i++) printf("%d",arr[i]);
// return 0;
// }

#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int arr[2][3]={1,2,3,4,5,6};
    for(int i=0;i<2;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum+=arr[i][j];}
        cout<<"sum of row"<<i<<": "<<sum;
        cout<<endl;}
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<2;j++){
            sum+=arr[j][i];}
        cout<<"sum of column"<<i<<": "<<sum;
        cout<<endl;}
    }
 

