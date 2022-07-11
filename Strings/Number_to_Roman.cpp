#include <iostream>
using namespace std;
void printRoman(int number){
    int num[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string symbol[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12; //index of maximum element in num array i.e. 1000
    while (number>0){
        int div=number/num[i]; //number of times num[i] will be repeated
        number=number%num[i]; //remainder
        while (div--) //equivalent to while (div!=0)
        {
            cout << symbol[i];
        }
        i--;
    }
}
int main(){
    int number=3549;
    printRoman(number);
    return 0;
}