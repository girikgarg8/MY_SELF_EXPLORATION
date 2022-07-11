#include <bits/stdc++.h>
using namespace std;
#define M 4
#define N 5
void printCommonElements(int mat[M][N]){
    unordered_map <int,int> m1;
    //Initiialise 1st row elements with value 1
    for (int j=0;j<N;j++){
        m1[mat[0][j]]=1;
    }
    //traverse the matrix
    for (int i=1;i<M;i++){
        for (int j=0;j<N;j++){
           //If element is not present in the map and is not duplicated in current row
           if (m1[mat[i][j]]==i) //Means the element has occured in all the previous rows and has not been duplicated in any row
           {
               m1[mat[i][j]]=i+1;
           }
           //If this is the last row
           if (i==(M-1) && m1[mat[i][j]]==M){ //means that the element mat[i][j] has occured M times i.e. it has occured in all the rows
                cout << mat[i][j] << " ";
           } 
        }
    }
}
int main()
{
    int mat[M][N] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    printCommonElements(mat);
 
    return 0;
}