#include <iostream>
using namespace std;
bool validate (int numberToValidate,int arr[],int n,int numberOfStudents){
    int i=0;int j;
    int count=0;
    for (i=0;i<n; ){
        int sum=0;
        for (j=i;sum+arr[j]<=numberToValidate && j<n;j++){
            sum+=arr[j];
        }
        i=j;
        count++;
    }
    if (count==numberOfStudents){
        return true;
    }
    return false;
}
int BookAllocation(int arr1[],int arr[],int s,int e,int n, int numberOfStudents){
    int ans;
    while (s<=e){
        int mid=(s+e)/2;
        bool u=validate(arr[mid],arr1,n,numberOfStudents);
        if (u==true){
            ans=arr[mid];
            e=mid-1;
        }
        else if (u==false){
            s=mid+1;
        }
    }
    return ans;
}
int main(){
    int numberOfBooks,numberOfStudents;
    cout << "Enter the number of books" <<endl;
    cin>>numberOfBooks;
    cout << "Enter number of students" <<endl;
    cin>>numberOfStudents;
    int *bookArray=new int[numberOfBooks];
    int sum=0;
    cout << "Enter the number of pages in each book" <<endl;
    for (int i=0;i<numberOfBooks;i++){
        cin>>bookArray[i];
        sum+=bookArray[i];
    }
    int numOfElementsInNewArray=sum-bookArray[0]+1;
    int *arrayForBinarySearch=new int[numOfElementsInNewArray];
    for (int i=0;i<numOfElementsInNewArray;i++){
        arrayForBinarySearch[i]=i+bookArray[0];
    }
    int y=BookAllocation(bookArray,arrayForBinarySearch,0,numOfElementsInNewArray-1,numberOfBooks,numberOfStudents);
    cout << "Answer is " << y <<endl;
    delete []arrayForBinarySearch;
    delete []bookArray;
    return 0;
}

