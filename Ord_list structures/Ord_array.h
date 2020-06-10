//
// Created by Win10Pro on 25.05.2020.
//

#ifndef LAB_6_ORDERED_LIST__ORD_ARRAY_H
#define LAB_6_ORDERED_LIST__ORD_ARRAY_H

#include "Point.h"

template <typename T>
class Ord_array {

private:

public:

    int size;
    static int power;
    T* array;

    Ord_array(){
        size = 0;
        array = new T[2 << power];
    }

    ~Ord_array() = default;

    int bin_search(T &t){
        if(size == 0){
            return 0;
        }
        if(array[size - 1] <= t){
            return size;
        }
        if(size == 1){
            if(array[0] > t)
                return 0;
            if(array[0] <= t)
                return 1;
        }
        int a = 0, b = size - 1;
        int middle = 0;
        while(a < b){
            middle = (a + b) / 2;
            if(array[middle] <= t) {
                a = middle + 1;
                middle = (a + b) / 2;
            } else{
                b = middle;
//                middle = (a + b) / 2;
            }

        }
        return middle;
    }
    void shift_push(){
        power++;
        T* copy = new T[2 << power];
        for(int i = 0; i < size; i++){
            copy[i] = array[i];
        }
        delete[] array;
        array = copy;
    }
    void shift_delete(){
        power--;
        T* copy = new T[2 << power];
        for(int i = 0; i < size; i++){
            copy[i] = array[i];
        }
        delete[] array;
        array = copy;
    }
    void push(T &t){
        if(size == 0){
            array[0] = t;
            size++;
            return;
        }
        int index = bin_search(t);
//        std::cout<<index<<"\n";
        if(size >= 2 << power){
            shift_push();
        }
        if(index == size){
            array[index] = t;
            size++;
            return;
        }
        T temp = array[size - 1];
        for(int i = size - 1; i > index; i--){
            array[i] = array[i - 1];
        }
        array[index] = t;
        array[size] = temp;
        size++;
    }
    void erase(int& index){
        for(int i = index; i < size - 1; i++){
            array[i] = array[i + 1];
        }
        size--;
        if(size <= (2 << power) / 4 && power > 1){
            shift_delete();
        }
    }
    std::vector <T> search(T& value){
        std::vector <T> res;
        for(int i = 0; i < size; i++){
            if(array[i] > value){
                break;
            }
            if(array[i] == value){
                res.emplace_back(array[i]);
            }
        }
        return res;
    }
    std::vector <T> search(T& lo, T& hi){
        std:: vector <T> res;
        for(int i = 0; i < size; i++){
            if(array[i] > hi){
                break;
            }
            if(array[i] >= lo) {
                res.emplace_back(array[i]);
            }
        }
        return res;
    }
    void output(){
        for(int i = 0; i < size; i++){
            std::cout<<i<<":\t"<<array[i]<<"\n";
        }
    }
    void go_round(){
        for(int i = 0; i < size; i++){
            array[i] = array[i];
        }
    }

};
template <typename T> int Ord_array <T>::power = 2;


#endif //LAB_6_ORDERED_LIST__ORD_ARRAY_H
