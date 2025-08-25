
#include<iostream>
using namespace std;
int main(){
	int a[10];
	for(int i=0;i<6;i++){
		cout<<"enter number :";
		cin>>a[i];
	}
	for(int i=0;i<3;i++){
	    int temp=a[i];
	    a[i]=a[6-i-1];
	    a[6-i-1]=temp;
	}
	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}
	return 0;}