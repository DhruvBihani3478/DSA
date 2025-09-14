#include <iostream>
using namespace std;
int main() {
    int n=4;
    int mat[4][4]={{1,2,3,4},{0,5,6,7},{0,0,8,9},{0,0,0,10}};
    int sparse[20][3],k=0;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(mat[i][j]!=0)
                sparse[k][0]=i, sparse[k][1]=j, sparse[k++][2]=mat[i][j];
    for(int i=0;i<k;i++) cout<<sparse[i][0]<<" "<<sparse[i][1]<<" "<<sparse[i][2]<<endl;
}
