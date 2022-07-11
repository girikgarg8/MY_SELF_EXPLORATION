#include <bits/stdc++.h>
using namespace std;
int ternarySearch(int low,int high,int key,int arr[]){
    while (low<=high){
        int mid1=low+(high-low)/3;
        int mid2=high-(high-low)/3;
        if (arr[mid1]==key){
            return mid1;
        }
        else if (arr[mid2]==key){
            return mid2;
        }
        else if (key>arr[mid2]){
            low=mid2+1;
        }
        else if (key<arr[mid1]){
            high=mid1-1;
        }
        else{
            low=mid1+1;
            high=mid2-1;
        }
    }
    return -1;
}
int main()
{
    int l, r, p, key;
 
    // Get the array
    // Sort the array if not sorted
    int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
 
    // Starting index
    l = 0;
 
    // length of array
    r = 9;
 
    // Checking for 5
 
    // Key to be searched in the array
    key = 5;
 
    // Search the key using ternarySearch
    p = ternarySearch(l, r, key, ar);
 
    // Print the result
    cout << "Index of "<<key<<" is " << p << endl;
 
    // Checking for 50
 
    // Key to be searched in the array
    key = 50;
 
    // Search the key using ternarySearch
    p = ternarySearch(l, r, key, ar);
 
    // Print the result
    cout << "Index of "<<key<<" is " << p;
}