#pragma once

template<typename T>
void swap(T* a, T* b);

template <typename T, typename Compare>
void sort(T *first, T *last, Compare comp);


template <typename T, typename Compare>
void insertion_sort(T *first, T *last, Compare comp);

template <typename T, typename Compare>
T pivot_point(T *first, T *last, Compare comp);

template <typename T, typename Compare>
void quicksort(T *first, T *last, Compare comp);

template<typename T, typename Compare>
bool isSorted(T* first, T* last, Compare comp);

#include "sort.hpp"
