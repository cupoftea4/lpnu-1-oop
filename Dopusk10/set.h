#ifndef SET_H
#define SET_H

#include <QDebug>
#include <iostream>
using std::to_string;

template <typename T>
class Set {
public:
    Set(int size) {
        this->size = size;
        array = new T[size];
    }

    ~Set() {
        delete [] array;
    }

    int Size() {
        return size;
    }

    Set * operator+(const Set * set) {
        Set * res = new Set(size);
        for (int i = 0; i < size; i++) {
            res->array[i] = array[i] + set->array[i];
        }
        return res;
    }

    Set * operator-(const Set * set) {
        Set * res = new Set(size);
        for (int i = 0; i < size; i++) {
            res->array[i] = array[i] - set->array[i];
        }
        return res;
    }

    Set * Intersection(const Set * set) {
        Set * res = new Set(0);
        bool isInRes = false;
        for (int i = 0; i < size; i++) {
            for (int k = 0; k < res->size; k++){
                if (res->array[k] == array[i]) {
                    isInRes = true;
                    break;
                }
            }
            for (int j = 0; j < set->size; j++) {
                if (set->array[j] == array[i] && !isInRes) {
                    res->Push(array[i]);
                    isInRes = false;
                    break;
                }
            }
        }
        return res;
    }

    void SetAt(int i, const T& elem) {
        array[i] = elem;
    }

    void Push(T& elem) {
        T temp[size];
        for (int i = 0; i < size; i++) temp[i] = array[i];
        size++;
        delete [] array;
        array = new T[size];
        for (int i = 0; i < size - 1; i++) array[i] = temp[i];
        array[size - 1] = elem;
    }

    void qPrint(QString str) {
        qDebug() << str;
        for (int i = 0; i < size; i++) {
            qDebug() << to_qString(array[i]);
        }
    }

    void Print(std::string str) {
        std::cout << str << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << to_string(array[i]) << std::endl;
        }
    }


private:
  int size = 0;
  T * array;
};

#endif // SET_H
