#include <iostream>
#include <cmath>
#define ll long long
#define prime 37
using namespace std;
ll int calculateHash(string a)
{
    int power = 0;
    int value = 0;
    int s = a.size();
    for (int i = 0; i < a.size(); i++)
    {
        value += (ll)(a[i] * (ll)pow(prime, i));
    }
    return value;
}
ll recalculateHash(string text, ll hash, int i, int j, string pat)
{
    ll l1 = pat.size() - 1;
    hash -= (ll)calculateHash(text.substr(i, 1)); //I am using reverse order of hashing i.e. abc=a*(37^0)+b*37^1+c*37^2
    hash /= prime;
    hash += (ll)calculateHash(text.substr(j, 1)) * pow(prime, l1);
    return (ll)hash;
}
void RabinAlgo(string text, string pat)
{
    int i = 0;
    int l = pat.length();
    int l1 = text.length();
    int j = pat.length() - 1;
    ll hashFirstSlidingWindow = calculateHash(text.substr(0, l));
    ll hashPattern = calculateHash(pat);
    ll hashOfCurSW = hashFirstSlidingWindow;
    while (j < l1)
    {
        if (hashPattern != hashOfCurSW)
        {
            hashOfCurSW = recalculateHash(text, hashOfCurSW, i, j + 1, pat);
            i++;
            j++;
        }
        else if (hashPattern == hashOfCurSW)
        {
            if (text.substr(i, l) == pat)
            {
                cout << "Substring found at index " << i << endl;
                hashOfCurSW = recalculateHash(text, hashOfCurSW, i, j + 1, pat);
                i++;
                j++;
            }
            else
            {
                hashOfCurSW = recalculateHash(text, hashOfCurSW, i, j + 1, pat);
                i++;
                j++;
            }
        }
    }
}
int main()
{
    string str = "ababdcabdab";
    string pat = "abd";
    RabinAlgo(str, pat);
    return 0;
}