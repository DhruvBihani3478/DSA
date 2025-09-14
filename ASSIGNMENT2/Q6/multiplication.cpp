#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 3;

    int A[3][3] = {{1,0,0},{0,0,2},{0,3,0}};
    int sparseA[rows*cols][3]; int a=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(A[i][j]!=0){
                sparseA[a][0]=i;
                sparseA[a][1]=j;
                sparseA[a][2]=A[i][j];
                a++;
            }
        }
    }
    int B[3][3] = {{0,4,0},{0,0,5},{6,0,0}};
    int sparseB[rows*cols][3]; int b=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(B[i][j]!=0){
                sparseB[b][0]=i;
                sparseB[b][1]=j;
                sparseB[b][2]=B[i][j];
                b++;
            }
        }
    }
    int sparseC[rows*cols][3]; int c=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            if(sparseA[i][1] == sparseB[j][0]){
                int row = sparseA[i][0];
                int col = sparseB[j][1];
                int val = sparseA[i][2] * sparseB[j][2];
                int found = 0;
                for(int k=0;k<c;k++){
                    if(sparseC[k][0]==row && sparseC[k][1]==col){
                        sparseC[k][2] += val;
                        found = 1;
                        break;
                    }
                }

                if(!found){
                    sparseC[c][0]=row;
                    sparseC[c][1]=col;
                    sparseC[c][2]=val;
                    c++;
                }
            }
        }
    }

    cout<<"Row Col Val (A*B):\n";
    for(int i=0;i<c;i++){
        cout<<sparseC[i][0]<<" "
            <<sparseC[i][1]<<" "
            <<sparseC[i][2]<<endl;
    }

    return 0;
}
