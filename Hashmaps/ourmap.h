#include <iostream>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode<V> *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    MapNode<V> **buckets;
    int numBuckets;
    int count;

public:
    ourmap()
    {
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
            buckets[i] = NULL;
        count = 0;
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
            delete buckets[i];
        delete[] buckets;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int coeff = 1;
        for (int i = 0; i < key.length(); i++)
        {
            hashCode += key[i] * coeff;
            hashCode %= numBuckets;
            coeff *= 37;
            coeff %= 37;
        }

        return hashCode % numBuckets;
    }

    void rehash()
    {
        MapNode<V> **temp = buckets;
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
            buckets[i] = NULL;
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                insert(head->key, head->value);
                head = head->next;
            }

            delete temp[i];
        }

        delete[] temp;
    }

public:
    double getLoadFactor()
    {
        return (1.0 * count) / numBuckets;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }

            head = head->next;
        }

        head = buckets[bucketIndex];
        MapNode<V> *newNode = new MapNode<V>(key, value);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count++;
        double loadFactor = (1.0 * count) / numBuckets;
        if (loadFactor >= 0.7)
            rehash();
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == nullptr)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }

                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }

            prev = head;
            head = head->next;
        }

        return 0;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }

            head = head->next;
        }

        return 0;
    }

    int size()
    {
        return count;
    }
};