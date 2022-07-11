#include <iostream>
using namespace std;
void Permutations(string s, int i)
{
    if (i >= s.size())
    {
        cout << s << endl;
        return;
    }
    for (int j = i; j < s.size(); j++)
    {
        swap(s[i], s[j]);
        Permutations(s, i + 1);
    }
}
int main()
{
    Permutations("abc", 0);
    return 0;
}