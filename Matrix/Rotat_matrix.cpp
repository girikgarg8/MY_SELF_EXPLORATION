#include <bits/stdc++.h>
using namespace std;
int main(){
    int mat[][3]={{1,2,3},{4,5,6},{7,8,9}};
    for (int i=0;i<3;i++){
        for (int j=0;j<i;j++){
            swap(mat[i][j],mat[j][i]); //Till here we have don ethe reanspose of the matrix in-place
    }
}
for (int i=0;i<3;i++){
    reverse (mat[i],mat[i]+3);
}
for (int i=0;i<3;i++){
    for (int j=0;j<3;j++){
        cout << mat[i][j] << " ";
    }
    cout <<endl;
}
return 0;
}