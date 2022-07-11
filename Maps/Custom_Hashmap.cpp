//Functions to be implemented: size function of unordered map, getting the bucket array index, insert a key in the map, remove a key from the map and return its value, search for a key
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
template <typename V>
class LLNode
{
public:
    string key;
    V value;
    LLNode *next;
    LLNode(int key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~LLNode()
    {
        delete next;
    }
};
template <typename V>
class OurMap
{
public:
    LLNode<V> **bucketArray; // This would be wrong LLNode **bucketArray=new [sizeOfBuckets]
    int sizeOfBucket;
    int size;
    OurMap()
    {
        sizeOfBucket = 5;
        size = 0;
        bucketArray = new LLNode<V> *[numOfBuckets];
        for (int i = 0; i < sizeOfBucket; i++)
        {
            bucketArray[i] = NULL;
        }
        ~OurMap()
        {
            for (int i = 0; i < sizeOfBucket; i++)
            {
                delete bucketArray[i]; //doing so will call delete on head of each linked list, which in turn which call delete on all nodes
            }
            delete[] bucketArray;
        }
    }
    int sizeOfMap()
    {
        return size;
    }
    int getArrayIndex(string key)
    {
        int primeNum = 37;
        int power = 0;
        int value = 0;
        for (int power = 0; power < key.size(); power++)
        {
            value += key[power] * pow(prime, power);
            value = value % sizeOfBucket; //To avoid the value going out of bounds
            pow(prime, power) %= sizeOfBucket; //Again, to avoid the value from becoming too large
        }
        return value % sizeOfBucket;
    }
    void insert(string key, V value)
    { // I first need to search whether the elemnt is already present in the linked list or not
        int x = getArrayIndex(key);
        LLNode<V> *head = bucketArray[x];
        LLNode<V> *temp = head;
        while ((temp) != NULL)
        {
            if (temp->data == key)
            {
                temp->value = value; //if the user wants to update a value in the map, the key already exists
                return;
            }
            temp = temp->next;
        }
        LLNode<V> *firstNode = new LLNode<V>(key, value);
        firstNode->next = head; //We will make the new key-value pair as the head node of linked list
        bucketArray[x] = firstNode;
        size++;
    }
    int remove(int key)
    {
        int x = getArrayIndex[key];
        LLNode<V> *head = bucketArray[x];
        LLNode<V> *temp = head;
        LLNode<V> *previous;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                if (previous != NULL)
                { //deleting at a non-head node in the linked list
                    previous->next = temp->next;
                    bucketArray[x] = previous;
                    V y = temp->value;
                    temp->next = NULL; //so that entire linked list may not get recursively deleted
                    delete temp;
                    size--;
                    return y;
                }
                else
                { // if we want to delete the  head node
                    bucketArray[x] = temp->next; 
                    V y = temp->value;
                    temp->next = NULL;
                    delete temp;
                    size--;
                    return y;
                }
            }
            previous = temp;
            temp = temp->next;
        }
        return 0;
    }
    void search(string key)
    {
        int x = getArrayIndex[key];
        LLNode<V> *head = bucketArray[x];
        LLNode<V> *temp = head;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return 0;
    }
};
