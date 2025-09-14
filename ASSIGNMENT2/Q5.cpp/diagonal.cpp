#include <iostream>
using namespace std;
int main() {
    int n=4;
    int mat[4][4]={{5,0,0,0},{0,8,0,0},{0,0,9,0},{0,0,0,12}};
    int sparse[4][3],k=0;
    for(int i=0;i<n;i++)
        if(mat[i][i]!=0)
            sparse[k][0]=i, sparse[k][1]=i, sparse[k++][2]=mat[i][i];
    for(int i=0;i<k;i++) cout<<sparse[i][0]<<" "<<sparse[i][1]<<" "<<sparse[i][2]<<endl;
}
