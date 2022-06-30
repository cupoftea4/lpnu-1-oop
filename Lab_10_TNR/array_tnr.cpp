#include "array_tnr.h"

template <typename T>
Array_TNR<T>::Array_TNR()
{
    array = new T[maxSize];
}

template<typename T>
Array_TNR<T>::~Array_TNR()
{
    delete [] array;
}

template<typename T>
T Array_TNR<T>::Append(T& item)
{
    if (size + 1 > maxSize) {
        IncreaseArray();
    }
    array[size++] = item;
    return item;
}

template<typename T>
void Array_TNR<T>::Clear()
{
    this->maxSize = 10;
    this->size = 0;
    delete [] array;
    array = new T[maxSize];
}

template<typename T>
void Array_TNR<T>::Sort(SortWay way)
{
    for (std::size_t i = 0; i < size; i++)
        if (way == Ascending) {
            Swap(i, Min(i));
        } else {
            Swap(i, Max(i));
        }
}

template<typename T>
T Array_TNR<T>::Minimum()
{
    return array[Min(0)];
}

template<typename T>
T& Array_TNR<T>::At(std::size_t i)
{
    if (i < size)
        return array[i];
    return array[size-1];
}

template<typename T>
int Array_TNR<T>::Length()
{
    return size;
}

template<typename T>
T Array_TNR<T>::SetAt(std::size_t i, T &item)
{
    if (i > size) return item;
    array[i-1] = item;
    return item;
}

template<typename T>
void Array_TNR<T>::IncreaseArray()
{
    T temp[size];
    for (std::size_t i = 0; i < size; i++) {
        temp[i] = array[i];
    }
    maxSize += 10;
    delete [] array;
    array = new T[maxSize];
    for (std::size_t i = 0; i < size; i++) {
        array[i] = temp[i];
    }
}

template<typename T>
int Array_TNR<T>::Min(int start)
{
    T min = array[start];
    int minIndex = start;
    for (std::size_t i = start + 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
            minIndex = i;
        }
    }
    return minIndex;
}

template<typename T>
int Array_TNR<T>::Max(int start)
{
    T max = array[start];
    int maxIndex = start;
    for (std::size_t i = start + 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

template<typename T>
void Array_TNR<T>::Swap(int n, int m)
{
    T temp = array[n];
    array[n] = array[m];
    array[m] = temp;
}

template class Array_TNR<double>;
template class Array_TNR<int>;
template class Array_TNR<String_TNR>;
template class Array_TNR<Polynom_TNR>;






