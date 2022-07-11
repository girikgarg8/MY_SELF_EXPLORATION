#include <bits/stdc++.h>
#define N 5
using namespace std;
int findMaxValue (int mat[][N]){
    int maxValue=INT_MIN;
    for (int i=0;i<N-1;i++){
        for (int j=0;j<N-1;j++){
            for (int x=i+1;x<N;x++){
                for (int y=j+1;y<N;y++){
                    maxValue=max(maxValue,mat[x][y]-mat[i][j]);
                }
            }
        }
    }
    return maxValue;
}
int main()
{
int mat[N][N] = {
                { 1, 2, -1, -4, -20 },
                { -8, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 10, -5, 1 }
            };
    cout << "Maximum Value is "
        << findMaxValue(mat);
 
    return 0;
}
