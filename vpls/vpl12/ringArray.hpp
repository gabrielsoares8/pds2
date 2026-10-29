#ifndef RINGARRAY_HPP
#define RINGARRAY_HPP

#include <vector>
#include <iostream>

template <class T>
class RingArray {
private:
    std::vector<T> _buffer;  
    int _capacidade;
    int _tamanho;
    int _head;
    int _tail;

public:
    RingArray(int capacidade) {
        _capacidade = capacidade;
        _tamanho = 0;
        _head = 0;
        _tail = 0;
        _buffer.resize(capacidade); 
    }

    
    int size(){
        return _tamanho;
    }
    bool is_empty(){
        return _tamanho == 0;
    }

    bool is_full(){
        return _tamanho == _capacidade;
        
    }

    void push(T item) {
    if (!is_full()) {
        _buffer[_tail] = item;
        _tail = (_tail + 1) % _capacidade;
        _tamanho++;
    } else {
        _buffer[_head] = item;
        _head = (_head + 1) % _capacidade;
        _tail = (_tail + 1) % _capacidade;
    }
    }
    T get(int index) {
        int pos = (_head + index) % _capacidade;
        return _buffer[pos];
    }

    T pop() {
        T item = _buffer[_head];
        _head = (_head + 1) % _capacidade;
        _tamanho--;
        return item;
    }

    void print() {
        for (int i = 0; i < _tamanho; i++) {
            std::cout << get(i) << "\n";
        }
    }

    T get_maior() {
        T maior = _buffer[_head];
        for (int i = 1; i < _tamanho; i++) {
            T atual = get(i);
            if (atual > maior) {
                maior = atual;
            }
        }
        return maior;
    }


    };
#endif