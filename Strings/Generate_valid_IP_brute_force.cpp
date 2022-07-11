
#include <iostream>
#include <vector>
using namespace std;
int is_valid(string ip) //Function checks whether IP digits are valid or not
{
    //Splitting by "."
    vector <string> ips; //THis vector will store the different digits of IP, for example for IP 119.189.172.878, it will store 119, 189,172,878
    string ex="";
    int n=ip.size();
    for (int i=0;i<n;i++){
        if (ip[i]=='.'){
            ips.push_back(ex);
            ex="";
        }
        else{
            ex=ex+ip[i];
        }
    }
    //After this for loop, 
    ips.push_back(ex); //This is for the last set of digits in the IP address
    for (int i=0;i<ips.size();i++){
        if (ips[i].length()>3 || stoi(ips[i])<0 || stoi(ips[i])>255){
            return 0;
        }
        if (ips[i].length()>1 && stoi(ips[i])==0){
            return 0;
        }
        if (ips[i].length()>1 && stoi(ips[i])!=0 && ips[i][0]=='0' ){
            return 0;
        }
    }
    return 1;
}
void convert(string ip){ //Function converts the string to IP
    int l=ip.length();
    if (l>12 || l<4){
        cout << "NO IP address can be formed from these characters";
    }
    string check=ip; //We have copied the given string ip into check, now we will insert dot at various places using loop and check if it is a valid configuration or not
    vector <string> ans;
    for (int i=1;i<l-2;i++){
        for (int j=i+1;j<l-1;j++){
            for (int k=j+1;k<l;k++){
                check=check.substr(0,k)+"."+check.substr(k,l-k+2);
                //Consider the input string 255254254, initially i=1,j=2,k=3, we put a dot at 255.254254, the substring 254254 is from index 3 to 8 i.e. k=3 and length of substring=l-k+2=9-3+2=8, this does not give an error
                check=check.substr(0,j)+"."+check.substr(j,l-j+3);
                check=check.substr(0,i)+"."+check.substr(i,l-i+4);
            if (is_valid(check)){
                ans.push_back(check);
                cout <<check <<endl;
            }
            check=ip;
        }
        }
    }
}
int main(){
    string a="25525511135";
    string b="25505011535";
    convert(a);
    convert(b);
    return 0;
}