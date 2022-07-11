#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4
int maxHist(int arr[],int n){
  int maxArea = 0;
    stack<int> s1;
    int i=0;
    while (i<n)
    {
        if (s1.empty() || (arr[i] > arr[s1.top()]))
        {
            s1.push(i);
            i++;
        }
        else
        {
                int value = arr[s1.top()];
                s1.pop(); //I need to pop first, don't pop after making the function call
                bool b = s1.empty();
                if (!b)
                {
                    int l = s1.top();
                    int area = value * (i - l - 1);
                    maxArea = max(area, maxArea);
                }
                else
                {
                    int area = value * i;
                    maxArea = max(area, maxArea);
                }
            }
    }
            while (!s1.empty()){
            int value = arr[s1.top()];
                s1.pop(); //I need to pop first, don't pop after making the function call
                bool b = s1.empty();
                if (!b)
                {
                    int l = s1.top();
                    int area = value * (i - l - 1);
                    maxArea = max(area, maxArea);
                }
                else
                {
                    int area = value * i;
                    maxArea = max(area, maxArea);
                }
            }
    return maxArea;
}
int maxRectangle(int mat[][C]){
    //Write this function first
    int result=maxHist(mat[0],C); //As there is no previous row to the first row, we can simply calculate the 
    //Iterate over each row to find the maximum area in that row's histogram
    for (int i=1;i<R;i++){
        for (int j=0;j<C;j++){
            if (mat[i][j]!=0){
                mat[i][j]+=mat[i-1][j];
            }
            result=max(result,maxHist(mat[i],C));
        }
    }
    return result;
}
int main()
{
    int A[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
 
    cout << "Area of maximum rectangle is "
         << maxRectangle(A);
    return 0;
}