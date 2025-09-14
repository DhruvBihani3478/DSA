#include <iostream>
using namespace std;
int main() {
    int n=4;
    int mat[4][4]={{1,0,0,0},{2,3,0,0},{4,5,6,0},{7,8,9,10}};
    int sparse[20][3],k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            if(mat[i][j]!=0)
                sparse[k][0]=i, sparse[k][1]=j, sparse[k++][2]=mat[i][j];
    for(int i=0;i<k;i++) cout<<sparse[i][0]<<" "<<sparse[i][1]<<" "<<sparse[i][2]<<endl;
}
