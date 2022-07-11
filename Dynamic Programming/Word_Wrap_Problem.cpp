#include <bits/stdc++.h>
using namespace std;
int wordWrap(vector<string> words, int m, int n){
    //here m denotes the line width and n is number of words in the vector

    //create another vector to store the length of each word
    vector <int> len(n);
    for (int i=0;i<n;i++){
        len[i]=words[i].size();
    }
    //Initially I will calculate the cost (negative or positive) in the upper triangular matrix
    int cost[n][n]; //cost[i][j] will denote cost if I keep all of i and j in one single line
    for (int i=0;i<n;i++){
        cost[i][i]=m-len[i];
        for (int j=i+1;j<n;j++){
            cost[i][j]=cost[i][j-1]-len[j]-1; //this is because I had already subtrracted some numbers in cost[i][j],now I need to subtract the current word lengrth and 1 (1 for space between the two words)  
        }
    }
    //Update the cost matrix to remove combinations that are not possible
    for (int i=0;i<n;i++){
        for (int j=i;j<n;j++){
            if (cost[i][j]<0) cost[i][j]=INT_MAX;
            else cost[i][j]=cost[i][j]*cost[i][j];
        }
    }
    int minCost[n];
    int pos[n];
    for (int i=n-1;i>=0;i--){
        pos[i]=n;
        minCost[i]=cost[i][n-1]; //initially I initated it such that I am trying to place all the words in the same line
        for (int j=n-1;j>i;j--){
            //checking for possible locations of split and choosing the one that gives min cost
            if (cost[i][j-1]==INT_MAX){ 
                continue;
            }
            if (minCost[i]>cost[i][j-1]+minCost[j]){
                minCost[i] = cost[i][j - 1] + minCost[j];
                pos[i]=j;
            }
        }
    }
    cout << "Printing the minCost array\n";
    for (int i=0;i<n;i++){
        cout << minCost[i] << " ";
    }
    cout << "Printing the position array\n";
    for (int i=0;i<n;i++){
        cout << pos[i] << " ";
    }
    return minCost[0];
}
int main(){
    vector <string> words{"tushar","roy","likes","to","code"};
    int n=words.size();
    int m=10;
    wordWrap(words,m,n);
    return 0;
}