#include <iostream>
using namespace std;
int main() {
    int nums[] = {2,2,1,0,1,0,2,0};
    int n = sizeof(nums) / sizeof(nums[0]);
    int i=0,j=0,k=n-1;
    while(k>=j){
        if(nums[j]==0){ 
            swap(nums[i],nums[j]);
            j++;
            i++;}
        else if( nums[j]==2) {
            swap(nums[j],nums[k]);
            k--;}
        else j++;
        }
    for(int i=0;i<n;i++){
		cout<<nums[i]<<" ";
	}
    return 0;
}
