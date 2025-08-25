#include<iostream>
using namespace std;
int main(){
    int arr[6]={1,3,3,5,5,6};
    int brr[6];
    int k=0;
    for(int i=0;i<6;i++){
        bool flag=false;
        for(int j=i+1;j<6;j++){
            if(arr[i]==arr[j]) flag=true;}
        if(!flag) {
            brr[k]=arr[i];
            k++;}
        }
    	for(int i=0;i<k;i++){
		    cout<<brr[i]<<" ";
    }}
