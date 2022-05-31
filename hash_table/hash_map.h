#ifndef HASH_MAP_H
#define HASH_MAP_H

template<typename K, typename V>
class HashNode
{
    public:
    V value;
    K key;

    HashNode(K key, V value)
    {
        this->value = value;
        this->key = key;
    }
};

template <typename K, typename V>
class HashMap {
public:
    HashMap();
    ~HashMap();
    V get(int);
    void insertNode(const K &key, const V &value);
    V deleteNode(const K &key);
    int sizeofMap();
    bool isEmpty();
    void display();
private:
    unsigned long size;
    unsigned long capacity;
    HashNode<K, V> **table;
    unsigned long hashFunc(K);
};

#endif