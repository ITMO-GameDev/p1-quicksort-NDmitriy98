#ifndef P1_QUICKSORT_NDMITRIY98_ARRAY_HPP
#define P1_QUICKSORT_NDMITRIY98_ARRAY_HPP

#pragma once
#include <iostream>

template <typename T>
class Array final
{


public:

    class Iterator
    {
        friend class Array<T>;
    public:
        Iterator() = default;
        explicit Iterator(Array<T>& arr);
        const T& get() const;
        void set(const T& value);
        void insert(const T& value);
        void remove();
        void next();
        void prev();
        void toIndex(int _index);
        bool hasNext() const;
        bool hasPrev() const;
    private:
        Array<T>& arr;
        int index;
    };


    Array();
    explicit Array(int capacity);
    ~Array();
    Array(const  Array&){};// { assert( false ); }
    void operator=(const  Array&){};// { assert( false ); }
    void insert(const T& value);
    void insert(int index, const T& value);
    void remove(int index);
    int size();
    int capacity();
    const T& operator[](int index) const;
    T& operator[](int index);
    Iterator iterator() {
        Iterator iterator(*this);
        return iterator;
    }
    const Iterator iterator() const {
        Iterator iterator(*this);
        return iterator;
    }

private:
    T* arr;
    int cUsedItems;
    int currentCapacity;
    void expandArray(); //expand array if needed
};



template <typename T>
Array<T>::Array() {
    arr = new T[8];
    cUsedItems = 0;
    currentCapacity = 8;
}

template <typename T>
Array<T>::Array(int capacity) {
    arr = new T[capacity];
    cUsedItems = 0;
    currentCapacity = capacity;
}

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
void Array<T>::insert(const T& value) {
    if (cUsedItems == currentCapacity) {
        expandArray();
    }
    arr[cUsedItems] = value;
    cUsedItems++;
}

template <typename T>
void Array<T>::insert(int index, const T& value) {
    if (index > cUsedItems) {
        throw std::out_of_range("Unable to insert. Bad index.");
    }
    if (cUsedItems == currentCapacity) {
        expandArray();
    }
    std::copy(arr + index, arr + cUsedItems, arr + index + 1);
    arr[index] = value;
    cUsedItems++;
}

template <typename T>
void Array<T>::remove(int index) {
    if (index > currentCapacity) {
        throw std::out_of_range("Unable to remove. Bad index.");
    }
    if (cUsedItems > 0) {
        std::copy(arr + index + 1, arr + cUsedItems, arr + index);
        arr[cUsedItems - 1] = 0;
        cUsedItems--;
    }
}

template<typename T>
int Array<T>::size()
{
    return cUsedItems;
}

template<typename T>
int Array<T>::capacity()
{
    return currentCapacity;
}

template <typename T>
T& Array<T>::operator[](int index) {

    if (index < 0 || index >= currentCapacity) {
        throw std::out_of_range("Bad index");
    }
    return arr[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const
{
    if (index < 0 || index >= currentCapacity) {
        throw std::out_of_range("Wrong index");
    }
    return arr[index];
}


template<typename T>
void Array<T>::expandArray()
{
    T* tmp = NULL;
    if (cUsedItems == currentCapacity) {
        tmp = new T[currentCapacity * 2];
        std::move(arr, arr + cUsedItems, tmp);
    }
    delete arr;
    arr = tmp;
    currentCapacity = currentCapacity * 2;
}


template<typename T>
Array<T>::Iterator::Iterator(Array<T>& arr) : arr(arr)
{
    index = 0;
}

template<typename T>
const T& Array<T>::Iterator::get() const
{
    return arr[index];
}

template<typename T>
void Array<T>::Iterator::set(const T& value)
{
    arr[index] = value;
}

template<typename T>
void Array<T>::Iterator::insert(const T& value)
{
    if (arr.cUsedItems < arr.currentCapacity)
        arr.insert(index, value);
}

template<typename T>
void Array<T>::Iterator::remove()
{
    arr.remove(index);
}

template<typename T>
void Array<T>::Iterator::next()
{
    if (hasNext())
        index++;
}

template<typename T>
void Array<T>::Iterator::prev()
{
    if (hasPrev())
        index--;
}

template<typename T>
void Array<T>::Iterator::toIndex(int _index)
{
    if (_index < arr.cUsedItems)
        this->index = _index;
}

template<typename T>
bool Array<T>::Iterator::hasNext() const
{
    return index < arr.cUsedItems - 1;
}

template<typename T>
bool Array<T>::Iterator::hasPrev() const
{
    return index > 0;
}


#endif //P1_QUICKSORT_NDMITRIY98_ARRAY_HPP
