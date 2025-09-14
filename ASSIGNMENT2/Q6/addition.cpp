#include <iostream>
using namespace std;

int main() {
    int A[3][3] = {{0,0,3},{0,4,0},{2,0,0}};
    int B[3][3] = {{5,0,0},{0,0,0},{0,7,0}};
    int rows = 3, cols = 3;

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

    int i=0, j=0, k=0;
    int sparseC[(rows*cols)*2][3]; 

    while(i<a && j<b){
        if(sparseA[i][0]<sparseB[j][0] || 
          (sparseA[i][0]==sparseB[j][0] && sparseA[i][1]<sparseB[j][1])){
            sparseC[k][0]=sparseA[i][0];
            sparseC[k][1]=sparseA[i][1];
            sparseC[k][2]=sparseA[i][2];
            i++; k++;
        }
        else if(sparseB[j][0]<sparseA[i][0] || 
               (sparseB[j][0]==sparseA[i][0] && sparseB[j][1]<sparseA[i][1])){
            sparseC[k][0]=sparseB[j][0];
            sparseC[k][1]=sparseB[j][1];
            sparseC[k][2]=sparseB[j][2];
            j++; k++;
        }
        else {
            sparseC[k][0]=sparseA[i][0];
            sparseC[k][1]=sparseA[i][1];
            sparseC[k][2]=sparseA[i][2]+sparseB[j][2];
            i++; j++; k++;
        }
    }

    while(i<a){
        sparseC[k][0]=sparseA[i][0];
        sparseC[k][1]=sparseA[i][1];
        sparseC[k][2]=sparseA[i][2];
        i++; k++;
    }
    while(j<b){
        sparseC[k][0]=sparseB[j][0];
        sparseC[k][1]=sparseB[j][1];
        sparseC[k][2]=sparseB[j][2];
        j++; k++;
    }

    cout<<"Row Col Val(A+B):\n";
    for(int x=0;x<k;x++){
        cout<<sparseC[x][0]<<" "
            <<sparseC[x][1]<<" "
            <<sparseC[x][2]<<endl;
    }

    return 0;
}
