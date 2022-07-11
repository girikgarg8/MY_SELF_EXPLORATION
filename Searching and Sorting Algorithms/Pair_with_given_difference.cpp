#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={5,3,20,5,2,80};
    int n=sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
    int i=0;
    int j=1;
    int key=75;
    int flag=0;
    while (i<n && j<n){
        if ((arr[j]-arr[i])==key){
            flag=1;
            cout << "Difference found" <<endl;
            break;
        }
        else if ((arr[j]-arr[i])>key)
        i++;
        else if ((arr[j]-arr[i])<key){
            j++;
        }
    }
    if (flag==0) cout << "Difference not found";
    return 0;
}
