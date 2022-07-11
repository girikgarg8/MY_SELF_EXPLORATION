#include <iostream>
using namespace std;
char data[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
void PhoneKeyPad(char *in, char *output, int i, int j)
{
    //i represents current index we are reading from input array and j represnts current index we are feeding into the output array
    //Base case
    if (in[i] == '\0')
    {
        output[j] = '\0';
        cout << output;
        return;
    }
    //Recursive call
    int index = in[i] - '0';
    for (int k = 0; data[index][k] != '\0'; k++)
    {
        output[j] = data[index][k];
        PhoneKeyPad(in, output, i + 1, j + 1);
        cout << endl;
    }
}
int main()
{
    char input[100];
    cin >> input;
    char output[100];
    PhoneKeyPad(input, output, 0, 0);
}