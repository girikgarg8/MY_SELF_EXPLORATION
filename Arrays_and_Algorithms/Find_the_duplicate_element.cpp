#include <iostream> //O(1) space complexity
using namespace std;
int findDuplicate(int arr[])
{
    //I don't need to know the size of the array over here, because I will be moving in a loop with slow and fast pointers
    int fast = arr[0];
    int slow = arr[0]; //initialise both fast and slow pointers from same starting position
    do
    { //Initially both fast and fast pointers are equal, so I use do-while
        fast = arr[arr[fast]];
        slow = arr[slow];
    } while (slow != fast);
    //At this point, there would be first intersection
    slow = arr[0]; //Send the slow pointer aka tortoise back to first position
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    //At this point both slow and fast pointers would be equal and equal to the duplicate element in the array
    return slow;
}
int main()
{
    int a[] = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    cout << "The duplicate element is " << findDuplicate(a) << endl;
    return 0;
}