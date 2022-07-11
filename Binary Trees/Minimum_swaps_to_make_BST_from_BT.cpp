/*

Prerequisite: Minimum number of swaps to sort the array
#include<bits/stdc++.h>

using namespace std;

// Function returns the
// minimum number of swaps
// required to sort the array
int minSwaps(int arr[], int n)
{
	// Create an array of
	// pairs where first
	// element is array element
	// and second element
	// is position of first element
	pair<int, int> arrPos[n];
	for (int i = 0; i < n; i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}

	// Sort the array by array
	// element values to
	// get right position of
	// every element as second
	// element of pair.
	sort(arrPos, arrPos + n);

	// To keep track of visited elements.
	// Initialize
	// all elements as not visited or false.
	vector<bool> vis(n, false);

	// Initialize result
	int ans = 0;

	// Traverse array elements
	for (int i = 0; i < n; i++)
	{
		// already swapped and corrected or
		// already present at correct pos
		if (vis[i] || arrPos[i].second == i)
			continue;

		// find out the number of node in
		// this cycle and add in ans
		int cycle_size = 0;
		int j = i;
		while (!vis[j])
		{                    //the intuition for these steps is if element at position 1 wants to be at position 3, we go and ask the element at position 3 where it wants to be and so on 
			vis[j] = 1;

			// move to next node
			j = arrPos[j].second;
			cycle_size++;
		}

		// Update answer by adding current cycle.
		if (cycle_size > 0)
		{
			ans += (cycle_size - 1);
		}
	}

	// Return result
	return ans;
}

// Driver program to test the above function
int main()
{
	int arr[] = {1, 5, 4, 3, 2};
	int n = (sizeof(arr) / sizeof(int));
	cout << minSwaps(arr, n);
	return 0;
}



       

*/

/*
#include<bits/stdc++.h>
using namespace std;
 
// Inorder Traversal of Binary Tree
void inorder(int a[], vector<int> &v,
                        int n, int index)
{
    // if index is greater or equal to vector size
    if(index >= n)
        return;
    inorder(a, v, n, 2 * index + 1);
     
    // push elements in vector
    v.push_back(a[index]);
    inorder(a, v, n, 2 * index + 2);
}

int minSwaps(vector<int> &v)
{
pair<int, int> arrPos[n];
	for (int i = 0; i < n; i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}

	// Sort the array by array
	// element values to
	// get right position of
	// every element as second
	// element of pair.
	sort(arrPos, arrPos + n);

	// To keep track of visited elements.
	// Initialize
	// all elements as not visited or false.
	vector<bool> vis(n, false);

	// Initialize result
	int ans = 0;

	// Traverse array elements
	for (int i = 0; i < n; i++)
	{
		// already swapped and corrected or
		// already present at correct pos
		if (vis[i] || arrPos[i].second == i)
			continue;

		// find out the number of node in
		// this cycle and add in ans
		int cycle_size = 0;
		int j = i;
		while (!vis[j])
		{                    //the intuition for these steps is if element at position 1 wants to be at position 3, we go and ask the element at position 3 where it wants to be and so on 
			vis[j] = 1;

			// move to next node
			j = arrPos[j].second;
			cycle_size++;
		}

		// Update answer by adding current cycle.
		if (cycle_size > 0)
		{
			ans += (cycle_size - 1);
		}
	}








*/