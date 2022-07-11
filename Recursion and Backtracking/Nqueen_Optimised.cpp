#include <iostream>
#include <bitset>
using namespace std;
bitset<30> column;
bitset<30> leftDiagonal;
bitset<30> RightDiagonal;
void solve(int r, int n, int &ans)
{
    if (r == n)
    {
        ans++;
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (!column[c] && !leftDiagonal[r - c + n - 1] && !RightDiagonal[r + c])
        {
            //Means this is a safe position to place the queen
            column[c] = leftDiagonal[r - c + n - 1] = RightDiagonal[r + c] = 1;
            solve(r + 1, n, ans);                                               // If this is the correct solution, then it would return ; after going to base case
            column[c] = leftDiagonal[r - c + n - 1] = RightDiagonal[r + c] = 0; //backtracking and resetting the values to 0
        }
    }
}
//We will count number of possible ways in this approach
//Reverse indexing is not a problem becuase if the elements are getting stored at reverse indices, then they are being accessed also through the same indices
int main()
{
    int n;
    cout << "Enter the value of n " << endl;
    cin >> n;
    int ans = 0;
    solve(0, n, ans);
    cout << "Number of possible ways are " << ans << endl;
    return 0;
}