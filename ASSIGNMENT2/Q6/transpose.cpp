#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 3;
    int mat[3][3] = {{0,0,3},
                     {0,0,0},
                     {2,0,0}};

    int sparse[rows*cols][3];
    int k = 0;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(mat[i][j] != 0){
                sparse[k][0] = i; 
                sparse[k][1] = j; 
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }

    int trans[k][3];
    for(int i=0;i<k;i++){
        trans[i][0] = sparse[i][1]; 
        trans[i][1] = sparse[i][0]; 
        trans[i][2] = sparse[i][2];
    }
    cout << "Transpose (Row Col Val):\n";
    for(int i=0;i<k;i++){
        cout << trans[i][0] << " " 
             << trans[i][1] << " " 
             << trans[i][2] << endl;
    }

    return 0;
}
