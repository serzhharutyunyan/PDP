#include <iostream>
#include "hash_map.h"

template <typename K, typename V>
HashMap<K,V> :: HashMap()
{
    capacity = 20;
    size = 0;
    table = new HashNode<K,V>*[capacity];
    for(int i=0 ; i < capacity ; i++)
    {
        table[i] = NULL;
    }
}

template <typename K, typename V>
HashMap<K,V> :: ~HashMap()
{
    for (int i = 0; i < size; ++i) {
        HashNode<K, V> *entry = table[i];
        while (entry != NULL) {
            HashNode<K, V> *prev = entry;
            entry = entry->getNext();
            delete prev;
        }

        table[i] = NULL;
    }

    delete [] table;
}

template <typename K, typename V>
V HashMap<K,V> :: get(int key)
{
    int hashIndex = hashFunc(key);
    int counter = 0;
    while(table[hashIndex] != NULL)
    {
        int counter = 0;
        if(counter++>capacity)
        {
            return NULL;
        }
        if(table[hashIndex]->key == key)
        {
            return table[hashIndex]->value;
        }

        hashIndex++;
         hashIndex %= capacity;
    }

    return NULL;
}

template <typename K, typename V>
void HashMap<K,V> :: insertNode(const K &key, const V &value)
{
    HashNode<K,V> *temp = new HashNode<K,V>(key, value);
    int hashIndex = hashFunc(key);
    while(table[hashIndex] != NULL && table[hashIndex]->key != key
        && table[hashIndex]->key != -1)
    {
        hashIndex++;
        hashIndex %= capacity;
    }

    if(table[hashIndex] == NULL || table[hashIndex]->key == -1)
    size++;
    table[hashIndex] = temp;
}

template <typename K, typename V>
V HashMap<K,V> :: deleteNode(const K &key)
{
    int hashIndex = hashFunc(key);
    while(table[hashIndex] != NULL)
    {
        if(table[hashIndex]->key == key)
        {
            HashNode<K,V> *temp = table[hashIndex];
            size--;
            return temp->value;
        }

        hashIndex++;
        hashIndex %= capacity;

    }

    return NULL;
}

template <typename K, typename V>
unsigned long HashMap<K,V> :: hashFunc(K key)
{
    return key % capacity;;
}

template <typename K, typename V>
int HashMap<K,V> :: sizeofMap()
{
    return size;
}

template <typename K, typename V>
bool HashMap<K,V> :: isEmpty()
{
    return size == 0;
}

template <typename K, typename V>
void HashMap<K,V> :: display()
{
    for(int i=0 ; i<capacity ; i++)
    {
        if(table[i] != NULL && table[i]->key != -1)
        {
            std::cout << "key = " << table[i]->key
            <<"  value = "<< table[i]->value << std::endl;
        }
    }
}