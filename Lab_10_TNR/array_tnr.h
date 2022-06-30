#ifndef ARRAY_TNR_H
#define ARRAY_TNR_H

#include <iostream>
#include <qdebug.h>
#include <string_tnr.h>
#include <QObject>
#include <polynom_tnr.h>

template <typename T>
class Array_TNR
{
public:
    Array_TNR();
    ~Array_TNR();

    T Append(T& item);
    void Clear();
    T& At(std::size_t i);
    int Length();

    T SetAt(std::size_t i, T& item);

    enum SortWay { Descending, Ascending };
    static SortWay SortWays;
    void Sort(SortWay way = Ascending);
    T Minimum();

    struct Iterator
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;
        using reference         = T&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator& operator++() { m_ptr++; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&array[0]); }
    Iterator end()   { return Iterator(&array[size]); }
private:
    T * array = nullptr;
    std::size_t size = 0;
    std::size_t maxSize = 10;
    void IncreaseArray();
    int Min(int start);
    int Max(int start);
    void Swap(int n, int m);
};


#endif // ARRAY_TNR_H
