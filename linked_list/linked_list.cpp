#include <iostream>

#include "linked_list.h"
#include "iterator.h"

template<typename T>
List<T>::List() {
    head = new Node<T>;
    tail = new Node<T>;
    head->prev = nullptr;
    head->next = tail;
    tail->prev = head;
    tail->next = nullptr;
    len = 0;
}

template<typename T>
List<T>::List(int count, T value) {
    this->head= nullptr;
    tail->next = nullptr;
    len = 0;

    for (int i = 0; i < count; i++) {
        push_back(value);
        head = head->next;
        ++len;
    }
}

template<typename T>
List<T>::List(const List<T>& list) {
    head = new Node<T>;
    tail = new Node<T>();
    head->prev = nullptr;
    head->next = tail;
    tail->prev = head;
    tail->next = nullptr;
    len = 0;

    for (Node<T>* ptr = list.head; ptr != 0; ptr = ptr->next) {
        push_back(ptr->data);
    }
}

template<typename T>
List<T>& List<T>::operator= (const List<T> &list) {
	List<T>::iterator it;
	for (it = list.begin(); it != list.end(); it++) {
	    push_back(*it);
    }

	return *this;
}

template<typename T>
List<T>::~List() {
    while (len) {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        --len;
    }
}

template<typename T>
typename List<T>::iterator List<T>::begin() {
    return iterator(head->next);
}

template<typename T>
typename List<T>::iterator List<T>::end() {
    return iterator(tail);
}

template<typename T>
void List<T>::push_back(const T& value) {
    Node<T>* ntemp = new Node<T>;
    ntemp->prev = 0;
    ntemp->next = 0;
    ntemp->data = value;
    if (nullptr == head) {
        tail = new Node<T>;
        head = ntemp;
        head->next = tail;
        tail->prev = head;
        tail->next = 0;
    } else {
        tail->prev->next = ntemp;
        ntemp->prev = tail->prev;
        ntemp->next = tail;
        tail->prev = ntemp;
    }
    ++len;
}

template<typename T>
void List<T>::push_front(const T& value) {
    if (0 == len) {
        push_back(value);
        return;
    } else {
        Node<T>* ptr = new Node<T>(value, 0, head->next);
        head->next = ptr;
    }
    ++len;
}


template<typename T>
void List<T>::pop_front() {
    if (0 == len) {
        std::cout << "List is empty!!!" << std::endl;
    }
    Node<T>* tmp = head;
    head = head->next;
    delete tmp;
    --len;
}

template<typename T>
void List<T>::pop_back() {
    if (0 == len) {
        std::cout << "List is empty!!!" << std::endl;
    }

    if (tail == head) {
        return;
    }

    tail = tail->prev;
    --len;
}

template<typename T>
unsigned int List<T>::size() const {
    return len;
}

template<typename T>
bool List<T>::empty() const {
    if (0 == len) {
        return true;
    }

    return false;
}