#include <iostream>
using namespace std;
int main()
{
    string text = "AAAABAAAAABBBAAAAB";
    string pattern = "AAAB";
    int lengthOfPattern = pattern.length();
    int *lps = new int[lengthOfPattern];
    lps[0] = 0;
    int i = 0; //for making the lps array
    int j = 1; //for making the lps array
    while (j <= lengthOfPattern)
    {
        if (pattern[i] == pattern[j])
        { //Matched,make value 1 bigger and move ahead
            lps[j] = i + 1;
            i++;
            j++;
        }
        else if (pattern[i] != pattern[j])
        {
            if (i == 0)
            {
                lps[j] = 0;
                j++;
            }
            else
            {
                i = lps[i - 1];
                //j++, Here j++ would be wrong
            }
        }
    }
    for (int i = 0; i < lengthOfPattern; i++)
    {
        cout << lps[i] << " ";
    }
    cout << endl;
    int lengthOfText = text.length();
    int a = 0; //for traversing in the text
    int b = 0; //for traversing in the pattern
    while (a < lengthOfText)
    {
        if (b == (lengthOfPattern))
        {
            cout << "Pattern found at index " << a - lengthOfPattern;
            b = 0;
        }
        if (text[a] == pattern[b])
        {
            a++;
            b++;
        }
        else if (text[a] != pattern[b])
        {
            if (b == 0)
            {
                a++;
            }
            else
            {
                int temp = lps[b - 1];
                if (temp == 0)
                {
                    a++;
                }
                else if (temp != 0)
                {
                    b = temp;
                }
            }
        }
    }
    if (b == (lengthOfPattern)) //This is for  example if I have AAAB at last, then while loop won't run
    {
        cout << "Pattern found at index " << a - lengthOfPattern;
    }
    return 0;
}