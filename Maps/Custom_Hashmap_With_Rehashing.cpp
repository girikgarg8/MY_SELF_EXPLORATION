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
        bucketArray = new LLNode<V> *[sizeOfBucket];
        for (int i = 0; i < sizeOfBucket; i++)
        {
            bucketArray[i] = NULL;
        }
    }
    ~OurMap()
    {
        for (int i = 0; i < sizeOfBucket; i++)
        {
            delete bucketArray[i]; //doing so will call delete on head of each linked list, which in turn which call delete on all nodes
        }
        delete[] bucketArray;
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
            value += key[power] * pow(primeNum, power);
            value = value % sizeOfBucket;
            pow(primeNum, power) = (int)pow(primeNum, power) % (sizeOfBucket);
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
                temp->value = value;
                return;
            }
            temp = temp->next;
        }
        LLNode<V> *firstNode = new LLNode<V>(key, value);
        firstNode->next = head;
        bucketArray[x] = firstNode;
        size++;
        float loadFactor = size / (float)(sizeOfBucket);
        if (loadFactor > 0.7)
        {
            rehash();
        }
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
                {
                    previous->next = temp->next;
                    bucketArray[x] = previous;
                    V y = temp->value;
                    temp->next = NULL;
                    delete temp;
                    size--;
                    return y;
                }
                else
                {
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
    int search(string key)
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
    void rehash()
    {
        LLNode<V> **temp = bucketArray;
        LLNode<V> **bucketArray = new LLNode<V> *[2 * sizeOfBucket];
        for (int i = 0; i < (2 * sizeOfBucket); i++)
        {
            bucketArray[i] = 0;
        }
        int oldBucketSize = sizeOfBucket;
        sizeOfBucket *= 2;
        size = 0;
        for (int i = 0; i < oldBucketSize; i++)
        {
            LLNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value); //When I will call insert function, the sizeofBucket would have been doubled, so it would take care of that
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketSize; i++)
        {
            LLNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }
};
