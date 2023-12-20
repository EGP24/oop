#pragma once
#include <vector>


template<typename T> class Set {
    private:
        std::vector<T> elements;

    public:
        explicit Set(std::vector<T> items);
        ~Set();

        void add(T item);
        void remove(T item);
        void clear();
        T pop();

        bool hasItem(T item);
        int length();

        void print();

        typename std::vector<T>::iterator begin();
        typename std::vector<T>::iterator end();

        Set<T> operator|=(Set<T>& set);
        Set<T> operator&=(Set<T>& set);
        Set<T> operator-=(Set<T>& set);
        Set<T> operator^=(Set<T>& set);
};

template<typename T> Set<T> operator|(Set<T>& a, Set<T>& b);
template<typename T> Set<T> operator&(Set<T>& a, Set<T>& b);
template<typename T> Set<T> operator-(Set<T>& a, Set<T>& b);
template<typename T> Set<T> operator^(Set<T>& a, Set<T>& b);

template<typename T> bool operator==(Set<T>& a, Set<T>& b);
template<typename T> bool operator!=(Set<T>& a, Set<T>& b);
template<typename T> bool operator>=(Set<T>& a, Set<T>& b);
template<typename T> bool operator<=(Set<T>& a, Set<T>& b);
template<typename T> bool operator>(Set<T>& a, Set<T>& b);
template<typename T> bool operator<(Set<T>& a, Set<T>& b);

#include "Set.hpp"
