#include <bits/stdc++.h>
using namespace std;
bool isValidConfiguration(int pages[],int booksNum,int studentsNum,int numToValidate){
    int numOfStudents=1;
    int sum_till_now=0;
    for (int i=0;i<booksNum;i++){
        if (sum_till_now+pages[i]>numToValidate){
            numOfStudents++;
            sum_till_now=pages[i]; //It would be wrong to reset this value ot zero, this is because if we do so, pages[i] would be missed
            if (numOfStudents>studentsNum) return false;
        }
        else sum_till_now+=pages[i];
    }
    return true;
}
int BinarySearchOnPages(int pages[],int booksNum,int studentsNum){
    int sumOfPages=0;
    for (int i=0;i<booksNum;i++){
        sumOfPages+=pages[i];
    }
    int low=0;
    int ans=0;
    int high=sumOfPages;
    while (low<=high){
        int mid=(low)+(high-low)/2;
        if (isValidConfiguration(pages,booksNum,studentsNum,mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    int numOfBooks=4;
    int numOfStudents=2;
    int pages[]={12,34,67,90};
    cout << BinarySearchOnPages(pages,numOfBooks,numOfStudents);
    return 0;
}