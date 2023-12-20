#pragma once
#include "Set.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


template <typename T> Set<T>::Set(vector<T> items) {
    sort(items.begin(), items.end());
    for (auto i : items) {
        if (find(elements.begin(), elements.end(), i) == elements.end())
            elements.push_back(i);
    }
}

template <typename T> Set<T>::~Set() = default;

template <typename T> void Set<T>::add(T item) {
    if (elements.empty())
        elements.push_back(item);
    if (this->hasItem(item))
        return;
    if (elements[elements.size() - 1] < item)
        elements.push_back(item);
    if (elements[0] > item)
        elements.insert(elements.begin(), item);

    for (auto it = elements.begin() + 1; it != elements.end() - 1; ++it) {
        if (*(it - 1) < item && *(it + 1) > item) {
            elements.insert(it + 1, item);
            break;
        }
    }
}

template <typename T> void Set<T>::remove(T item) {
    vector<T> newElements;

    for (auto i : elements) {
        if (i != item)
            newElements.push_back(i);
    }
    this->elements = newElements;
}

template <typename T> void Set<T>::clear() {
    elements.clear();
}

template <typename T> T Set<T>::pop() {
    T removedElement = *(elements.end() - 1);
    elements.pop_back();
    return removedElement;
}

template <typename T> bool Set<T>::hasItem(T item) {
    for (auto it = elements.begin(); it != elements.end(); ++it) {
        if (*it == item)
            return true;
    }
    return false;
}

template <typename T> int Set<T>::length() {
    return elements.size();
}

template <typename T> void Set<T>::print() {
    cout << "{";
    for (int i = 0; i < elements.size(); ++i) {
        cout << elements[i];
        if (i != elements.size() - 1)
            cout << ", ";
    }
    cout << "}" << '\n';
}

template <typename T> typename vector<T>::iterator Set<T>::begin() {
    return elements.begin();
}

template <typename T> typename vector<T>::iterator Set<T>::end() {
    return elements.end();
}

template <typename T> Set<T> Set<T>::operator|=(Set<T>& set) {
    vector<T> newElements;
    for (auto i : (*this | set))
        newElements.push_back(i);

    elements = newElements;
    return Set<T>(newElements);
}

template <typename T> Set<T> Set<T>::operator&=(Set<T>& set) {
    vector<T> newElements;
    for (auto i : (*this & set))
        newElements.push_back(i);

    elements = newElements;
    return Set<T>(newElements);
}

template <typename T> Set<T> Set<T>::operator-=(Set<T>& set) {
    vector<T> newElements;
    for (auto i : (*this - set))
        newElements.push_back(i);

    elements = newElements;
    return Set<T>(newElements);
}

template <typename T> Set<T> Set<T>::operator^=(Set<T>& set) {
    vector<T> newElements;
    for (auto i : (*this ^ set))
        newElements.push_back(i);

    elements = newElements;
    return Set<T>(newElements);
}

template <typename T> Set<T> operator|(Set<T>& a, Set<T>& b) {
    vector<T> items;
    
    for (auto i = a.begin(); i != a.end(); ++i) {
        if (find(items.begin(), items.end(), *i) == items.end())
            items.push_back(*i);
    }
    for (auto i = b.begin(); i != b.end(); ++i) {
        if (find(items.begin(), items.end(), *i) == items.end())
            items.push_back(*i);
    }
    return Set<T>(items);
}

template <typename T> Set<T> operator&(Set<T>& a, Set<T>& b) {
    vector<T> items;
    
    for (auto i = a.begin(); i != a.end(); ++i) {
        if (find(b.begin(), b.end(), *i) != b.end())
            items.push_back(*i);
    }
    return Set<T>(items);
}

template <typename T> Set<T> operator-(Set<T>& a, Set<T>& b) {
    vector<T> items;
    
    for (auto i = a.begin(); i != a.end(); ++i) {
        if (find(b.begin(), b.end(), *i) == b.end())
            items.push_back(*i);
    }
    return Set<T>(items);
}

template <typename T> Set<T> operator^(Set<T>& a, Set<T>& b) {
    Set<T> m = a | b;
    Set<T> n = a & b;
    return m - n;
}

template <typename T> bool operator==(Set<T>& a, Set<T>& b) {
    return a >= b && a <= b;
}

template <typename T> bool operator!=(Set<T>& a, Set<T>& b) {
    return !(a == b);
}

template <typename T> bool operator>=(Set<T>& a, Set<T>& b) {
    for (auto i : b) {
        if (!a.hasItem(i))
            return false;
    }
    return true;
}

template <typename T> bool operator<=(Set<T>& a, Set<T>& b) {
    for (auto i : a) {
        if (!b.hasItem(i))
            return false;
    }
    return true;
}

template <typename T> bool operator>(Set<T>& a, Set<T>& b) {
    return a != b && a >= b;
}

template <typename T> bool operator<(Set<T>& a, Set<T>& b) {
    return a != b && a <= b;
}
