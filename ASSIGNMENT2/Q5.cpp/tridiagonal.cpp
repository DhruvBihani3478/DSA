#include <iostream>
using namespace std;
int main() {
    int n=4;
    int mat[4][4]={{1,2,0,0},{3,4,5,0},{0,6,7,8},{0,0,9,10}};
    int sparse[20][3],k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(abs(i-j)<=1 && mat[i][j]!=0)
                sparse[k][0]=i, sparse[k][1]=j, sparse[k++][2]=mat[i][j];
    for(int i=0;i<k;i++) cout<<sparse[i][0]<<" "<<sparse[i][1]<<" "<<sparse[i][2]<<endl;
}
