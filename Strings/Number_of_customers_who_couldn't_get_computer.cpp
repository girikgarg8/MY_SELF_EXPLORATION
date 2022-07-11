#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26 
//This is the maximum number of people who can visit the cafe
int customerSimulation(int n,string seq){
    // n is number of computers in the cafe
    // seq is the sequence in which customers enter and leave the cafe
    int seen[MAX_CHAR]={0};
    //There would be three flags
    // seen[i]=0 means that the person has not visited the cafe
    // seen[i]=1 means that the person has visted the cafe, but is not on the computer rn
    // seen[i]=2 means that the person has visted the cafe, and is not on the computer rn
    int res=0;
    // res denotes number of people who couldn't get the computer
    int occupied=0; //number of people who have occupied the computer
    for (int i=0;i<seq.length();i++){
        int ind=seq[i]-'A';
        if (seen[ind]==0){
            seen[ind]=1; //we have said that will visit,but we will have to check whether we can give him the computer or not
            if (occupied<n){
                occupied++;
                seen[ind]=2;
            }
            else{
                res++; //it means that more number of people have already been occupied, so we cannot place that person, hence increase res
            }
        }
        //Now I will deal with that case when I encounter a reapeated character eg. ABCA, now I have encountered A for the second time
        else{
            if (seen[ind]==2){ //Decrement the occupied only in case seen is 2, not in case seen is 1
                occupied--;
            }
            seen[ind]=0;
        }
    }
    return res;
}
int main()
{
    cout << customerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << customerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << customerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << customerSimulation(1, "ABCBCA") << endl;
    cout << customerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}