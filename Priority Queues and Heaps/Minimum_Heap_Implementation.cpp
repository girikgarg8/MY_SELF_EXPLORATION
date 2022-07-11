#include <iostream>
#include <vector>
using namespace std;
class priorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int size()
    {
        return pq.size();
    }
    int getMin()
    {
        if (!isEmpty())
        {
            return pq[0];
        }
        return -1;
    }
    void insert(int number)
    {
        pq.push_back(number);
        int ChildIndex = pq.size() - 1;
        while (ChildIndex > 0)
        {
            int ParentIndex = (ChildIndex - 1) / 2;
            if (pq[ChildIndex] < pq[ParentIndex])
            {
                swap(pq[ChildIndex], pq[ParentIndex]);
            }
            else
            {
                break;
            }
            ChildIndex = ParentIndex;
        }
    }
    int removeMin()
    {
        if (isEmpty())
        {
            return -1;
        }
        int answer = pq[0];
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();
        int MinIndex;
        int ParentIndex = 0;
        while ((2 * (ParentIndex) + 1) < pq.size())
        {
            int LeftChildIndex = 2 * ParentIndex + 1;
            int RightChildIndex = 2 * ParentIndex + 2;
            if (LeftChildIndex < pq.size() && RightChildIndex < pq.size())
            {
                if (pq[LeftChildIndex] < pq[RightChildIndex])
                {
                    MinIndex = LeftChildIndex;
                }
                else
                    MinIndex = RightChildIndex;
            }
            else if (LeftChildIndex < pq.size())
            {
                MinIndex = LeftChildIndex;
            }
            if (pq[ParentIndex] > pq[MinIndex])
            {
                swap(pq[ParentIndex], pq[MinIndex]);
            }
            else if (pq[ParentIndex] < pq[MinIndex])
            {
                break;
            }
            ParentIndex = MinIndex;
        }
        return answer;
    }
};
int main()
{
    priorityQueue p1;
    p1.insert(100);
    p1.insert(10);
    p1.insert(15);
    p1.insert(4);
    p1.insert(17);
    p1.insert(21);
    p1.insert(67);
    cout << "Size of priority queue is " << p1.size() << endl;
    cout << "Minimum element in the heap is " << p1.getMin() << endl;
    while (!p1.isEmpty())
    {
        cout << p1.removeMin() << endl;
    }
    return 0;
}