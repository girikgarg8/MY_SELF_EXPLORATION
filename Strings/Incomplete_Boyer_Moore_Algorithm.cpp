#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;
void BoyerMoore(string text, string pat)
{
    queue<int> q1;
    unordered_map<char, int> m1;
    int n = pat.length();
    int m = text.length();
    m1['*'] = n;
    m1[pat[n - 1]] = n;
    for (int i = 0; i < (n - 1); i++)
    {
        if (pat[i] != pat[n - 1])
        {
            m1[pat[i]] = n - i - 1;
        }
    }
    int x = 0;     //starting point of pattern
    int y = n - 1; //ending point of pattern
    int u = 0;     //starting point of substring of text that I am comparing
    int v = n - 1; //ending point of substring of text that I am comparing
    while (v < m && u >= 0 && y >= 0)
    {
        if (y == 0)
        {
            cout << "Pattern found at index " << x;
            break;
        }
        else if (pat[y] != text[v])
        {
            if (!q1.empty())
            {
                int a = q1.front();
                int t = m1[text[a]];
                x += t;
                y += t;
                while (!q1.empty())
                {
                    q1.pop();
                }
            }
            else if (m1.count(text[v]))
            {
                int temp = m1[text[v]];
                x += temp;
                y += temp;
            }
            else
            {
                x += n;
                y += n;
            }
        }
        else if (pat[y] == text[v])
        {
            q1.push(v);
            y--;
            v--;
        }
    }
}
int main()
{
    string text = "WELCOMETOSURANACOLLEGE";
    string pat = "SURANA";
    BoyerMoore(text, pat);
    return 0;
}