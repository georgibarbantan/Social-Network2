//
// Created by georg on 20.06.2022.
//

#ifndef PROIECT_SDA_ARRAYLIST_H
#define PROIECT_SDA_ARRAYLIST_H


#include <stdexcept>
#include <iostream>
#include "../ExceptionHandler/CustomException.h"

template<class T>
class ArrayList {
private:
    T *list;
    int size = 0;

public:
    ArrayList() {
        list = new T[1000000];
        size = 0;
    };


    void add(T element);

    void remove(T element);

    bool contains(T element);

    T get(int index);

    int update(T element, T newElement);

    int getSize();

    int getIndex(T element);

};

template<class T>
int ArrayList<T>::update(T element, T newElement) {
    if (contains(element)) {
        list[getIndex(element)] = newElement;
        return 1;
    }
    return 0;
}

template<class T>
int ArrayList<T>::getIndex(T element) {
    for (int i = 0; i < size; i++)
        if (list[i] == element)
            return i;
    return -1;
}

template<class T>
void ArrayList<T>::add(T element) {
    list[size] = element;
    size++;
}

template<class T>
bool ArrayList<T>::contains(T element) {
    for (int i = 0; i < size; i++)
        if (list[i] == element)
            return true;
    return false;
}

template<class T>
T ArrayList<T>::get(int index) {
    try {
        if (index >= size) {
            throw CustomException("Index out of range!\n");
        }
        return list[index];
    } catch (CustomException &exception) {
        std::cout << exception.getMessage();
    }

}

template<class T>
void ArrayList<T>::remove(T element) {
    int index = getIndex(element);
    if (index != -1) {
        for (int i = index; i < size - 1; i++) {
            T temp = list[i];
            list[i] = list[i + 1];
            list[i + 1] = temp;
        }

        size--;
    } else
        return;
}

template<class T>
int ArrayList<T>::getSize() {
    return size;
}

#endif //PROIECT_SDA_ARRAYLIST_H
