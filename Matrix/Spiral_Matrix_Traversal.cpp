#include <bits/stdc++.h>
using namespace std;
void spiralTraversal(int arr[][6],int m,int n){
    int top=0;
    int down=m-1; //m is number of rows, n is number of columns
    int left=0;
    int right=n-1;
    int dir=0;
    while (top<=down && left<=right){
        if (dir==0){
            for (int i=left;i<=right;i++){
                cout << arr[top][i] << " ";
            }
            top+=1;
        }
        else if (dir==1){
            for (int i=top;i<=down;i++){
                cout << arr[i][right] << " ";
            }
            right-=1;
        }
        else if (dir==2){
            for (int i=right;i>=left;i--){
                cout << arr[down][i] << " ";
            }
            down-=1;
        }
        else if (dir==3){
            for (int i=down;i>=top;i--){
                cout << arr[i][left] << " ";
            }
        left+=1;
        }
        dir=(dir+1)%4;
    }
}
int main(){
    int a[3][6]={{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}};
    spiralTraversal(a,3,6);
    return 0;
}