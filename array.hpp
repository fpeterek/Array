//
//  array.hpp
//  array
//
//  Created by Filip Peterek on 12/12/2016.
//  Copyright © 2016 Filip Peterek. All rights reserved.
//

#ifndef array_hpp
#define array_hpp

#include <stdio.h>
#include <iostream>
#include <cstdlib>

template <typename T>
class array {
    
    T * _array;
    long long _size;
    long long _items = 0;
    
    void resize(long long size) {
        
        _size = size;
        _array = (T*) realloc(_array, size * sizeof(T));
        
    }
    
    void sizeCheck() {
        
        if (_size - _items < 5 ) {
            resize(_size + 10);
        }
        else if (_size - _items > 20) {
            
            resize(_size - 10);
            
        }
        
    }
    
public:
    
    array() {
        
        _array = nullptr;
        _size = 0;
        
    }
    
    array(long long size) {
        
        _size = size;
        _array = malloc(_size * sizeof(T));
        
    }
    
    array(array<T> & arr) {
        
        _size = arr._size;
        _items = arr._items;
        
        _array = (T*)malloc(_size * sizeof(T));
        memcpy(_array, arr._array, _size * sizeof(T));
        
    }
    
    array(array<T> && arr) {
        
        _size = arr._size;
        _items = arr._items;
        
        _array = (T*)malloc(_size * sizeof(T));
        memcpy(_array, arr._array, _size * sizeof(T));
        
    }
    
    ~array() {
        
        free(_array);
        _array = nullptr;
        
    }
    
    void setValues(T & value) {
        
        for (long long i = 0; i < _items; ++i) {
        
            _array[i] = value;
        
        }
        
    }
    
    T & at(long long pos) {
        
        if (pos >= _items) {
            throw std::out_of_range("Error, trying to access element outside memory bounds. ");
        }
        
        return _array[pos];
        
    }
    
    T & operator[] (long long pos) {
        
        return at(pos);
        
    }
    
    void push(T && var) {
        
        insert(0, var);
        
    }
    
    void push(T & var) {
        
        insert(0, var);
        
    }
    
    void emplace_back(T && var) {
        
        insert(_items, var);
        
    }
    
    void emplace_back(T & var) {
        
        insert(_items, var);
        
    }
    
    void insert(long long pos, T & var) {
        
        if (pos > _items) {
            throw std::out_of_range("Error, trying to access element outside memory bounds. ");
        }
        
        sizeCheck();
        for (long long i = _items - 1; i >= pos; --i) {
            _array[i + 1] = _array[i];
        }
        _array[pos] = var;
        
        ++_items;
        
    }

    
    void insert(long long pos, T && var) {
        
        if (pos > _items) {
            throw std::out_of_range("Error, trying to access element outside memory bounds. ");
        }
        
        sizeCheck();
        for (long long i = _items - 1; i >= pos; --i) {
            _array[i + 1] = _array[i];
        }
        _array[pos] = var;
        
        ++_items;
        
    }
    
    void remove(long long pos) {
        
        if (pos > _items) {
            throw std::out_of_range("Error, trying to access element outside memory bounds. ");
        }
        
        for (long long i = pos; i < _items - 1; ++i) {
            _array[i] = _array[i + 1];
        }
        
        sizeCheck();
        --_items;
        
    }
    
    void pop() {
        
        remove(_items - 1);
        
    }
    
    void concatenate(array<T> & a) {
        
        resize(length() + a.length() + 10);
        
        for (long long i = 0; i < a.length(); ++i) {
            
            emplace_back(a[i]);
            
        }
        
    }
    
    void operator+= (array<T> & a) {
        
        concatenate(a);
        
    }
    
    array<T> operator+ (array<T> & a) {
        
        array<T> arr(*this);
        
        arr.concatenate(a);
        
        return arr;
        
    }
    
    long long length() {
        
        return _items;
        
    }
    
    long long size() {
        
        return _items;
        
    }
    
    bool compare(array<T> & a) {
        
        return operator==(a);
    
    }
    
    bool compare(array<T> && a) {
        
        return operator==(a);
        
    }
    
    bool operator== (array<T> & a) {
        
        if (a.length() != length()) { return false; }
        
        for (long long i = 0; i < length(); ++i) {
            
            if (a[i] != at(i)) { return false; }
            
        }
        
        return true;
        
    }
    
    bool operator== (array<T> && a) {
        
        if (a.length() != length()) { return false; }
        
        for (long long i = 0; i < length(); ++i) {
            
            if (a[i] != at(i)) { return false; }
            
        }
        
        return true;
        
    }
    
};

template <typename Collection>
std::ostream & operator<< (std::ostream & os, Collection & c) {
    
    for (long long i = 0; i < c.length(); ++i) {
        
        os << std::string("[") << i << std::string("] ") << c[i] << std::endl;
        
    }
    
    return os;
}

#endif /* array_hpp */
