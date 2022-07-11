#include <iostream>
using namespace std;
void swap (int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int arr[]={5,1,3,4,2};
    int i,j,min,temp,k;
    int n=sizeof(arr)/sizeof(int);
    for (i=0;i<n;i++){ min=arr[i];
        for (j=i+1;j<n;j++){
            if (arr[j]<min){
                min=arr[j];
            }
        }
    for (k=i;k<n;k++){
        if (arr[k]==min){
            break;
        }
    }
    swap(&arr[k],&arr[i]);
    }
    for (i=0;i<n;i++){
        cout << arr[i] <<endl;
}
return 0;
}

/*Improvised Code
#include <iostream>
using namespace std;
void swap (int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int arr[]={5,1,3,4,2};
    int i,j,min_index,temp;
    int n=sizeof(arr)/sizeof(int);
    for (i=0;i<n;i++){ min_index=i;
        for (j=i+1;j<n;j++){
            if (arr[j]<arr[min_index]){
                min_index=j;
            }
        }
    swap(&arr[min_index],&arr[i]);
    }
    for (i=0;i<n;i++){
        cout << arr[i] <<endl;
}
return 0;
}
*/
