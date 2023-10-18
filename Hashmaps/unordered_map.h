#include<iostream>
using namespace std;

template <typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;

    MapNode(string key, V value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

    ~MapNode() {
        delete next;
    }
};

template <typename V>
class ourmap{
    MapNode<V>** buckets;
    int count;
    int numBuckets;
    int bucketIndex;

    public:
    ourmap() {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V>*[numBuckets];
        for(int i = 0; i < numBuckets; i++) buckets[i] = nullptr;
    }

    ~ourmap() {
        for(int i = 0; i < numBuckets; i++) delete buckets[i];
        delete [] buckets;
    }

    int size() {
        return count;
    }

    private:
    int getBucketIndex(string key) {
        int hashCode = 0;
        int currCoefficient = 1;
        for(int i = key.length() - 1; i >= 0; i--) {
            hashCode += key[i] * currCoefficient;
            hashCode = hashCode % numBuckets;
            currCoefficient *= 37;
            currCoefficient = currCoefficient % numBuckets;
        }

        return hashCode % numBuckets;
    }

    void rehash() {
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2 * numBuckets];
        for(int i = 0; i < 2 * numBuckets; i++) buckets[i] = nullptr;
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        count = 0;
        for(int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            while(head != nullptr) {
                insert(head->key, head->value);
                head = head->next;
            }
        }
        
        for(int i = 0; i < oldBucketCount; i++) {
            MapNode<V>* head = temp[i];
            delete head;
        }

        delete [] temp;
    }

    public:
    double getLoadFactor() {
        return (count * 1.0) / numBuckets;
    }

    V getValue(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != nullptr) {
            if(head->key == key) {
                return head->value;
            }
            head = head->next;
        }

        return 0;
    }

    void insert(string key, V value) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        while(head != nullptr) {
            if(head->key == key) {
                head->value = value;
                return;
            }

            head = head->next;
        }

        head = buckets[bucketIndex];
        MapNode<V>* newNode = new MapNode<V>(key, value);
        newNode->next = head;
        buckets[bucketIndex] = newNode;
        count++; 
        double loadFactor = (count * 1.0) / numBuckets;
        if(loadFactor >= 0.7) {
            rehash();
        }
    }

    V remove(string key) {
        int bucketIndex = getBucketIndex(key);
        MapNode<V>* head = buckets[bucketIndex];
        MapNode<V>* prev = nullptr;
        while(head != nullptr) {
            if(head->key == key) {
                if(prev == nullptr) {
                    buckets[bucketIndex] = head->next;
                } else {
                    prev->next = head->next;
                }
                V val = head->value;
                head->next = nullptr;
                delete head;
                count--;
                return val;
            }

            prev = head;
            head = head->next;
        }

        return 0;
    }
};