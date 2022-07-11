#include <bits/stdc++.h>
using namespace std;
//A class to store the pair sum in auxiliary array aux[]
class PairSum{
    public:
    int first; //index of first element in pair
    int sec; //index of second element in pair
    int sum; //sum of the pair
};
//Function to check if two given elements have any common element or not
bool noCommon(PairSum a, PairSum b){
    if (a.first==b.first || a.first==b.sec || a.sec==b.first || a.sec==b.sec){
        return false;
    }
    return true;
}
bool compare(PairSum a,PairSum b){ //Comparator function
    return a.sum<b.sum;
}
//The below function finds four elements with given sum X
void findFourElements(int arr[],int n,int X){
    int i,j;
    int size=n*(n-1)/2;  //this is the size of the auxliary array, its proof is (n-1) (for first element) + (n-2)+ .... 1=n*(n-1)/2
    PairSum aux[size];
    //Generate all possible pairs from A[] and store sums of all possible pairs in aux[]
    int k=0; //This denotes index of the auxiliary array index at which I am inserting the pair
    for (int i=0;i<(n-1);i++){
        for (int j=i+1;j<n;j++){
            aux[k].first=i;
            aux[k].sec=j;
            aux[k].sum=arr[i]+arr[j];
            k++;
        }
    }
    sort(aux,aux+size,compare);
    //Now use the approach as we used in two sum problem, take two pointers and move them accordingly
    int u=0;
    int v=size-1;
    while (u<size && v>=0){
        if ((aux[u].sum)+(aux[v].sum)==X){
            if (noCommon(aux[u],aux[v])){
                cout << arr[aux[u].first] << " , " << arr[aux[u].sec] << ", " << arr[aux[v].first] << " ," << arr[aux[v].sec];
                return ;
            }
        }
        else if ((aux[u].sum+aux[v].sum)<X){
            u++;
        }
        else v--;
    }
}
int main(){
    int arr[]={10,20,30,40,1,2};
    int n=sizeof(arr)/sizeof(int);
    int X=91;
    findFourElements(arr,n,X);
    return 0;
}