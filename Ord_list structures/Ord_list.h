//
// Created by Win10Pro on 23.05.2020.
//

#ifndef LAB_6_ORDERED_LIST__ORD_LIST_H
#define LAB_6_ORDERED_LIST__ORD_LIST_H

#include "Point.h"
//#include "Point.cpp"

template <typename T>
class Ord_list {

private:


    //Body of list

    class ListNode {
    public:

        T value;
        ListNode* prev;
        ListNode* next;

        explicit ListNode(const T& t){
            this->value = t;
            prev = nullptr;
            next = nullptr;
        }
    };

    ListNode*  head;
    ListNode*  tail;


public:
    int length;
    Ord_list(){

        head = nullptr;
        tail = nullptr;
        length = 0;

    }
    ~Ord_list()= default;

    void push(T& t){
        auto *node = new ListNode(t) ;
        if(length == 0){
            head = node;
            tail = node;
            length++;
            return;
        }
        ListNode* count = head;
        for(int i = 0; i < length; i++){
            if(node->value >= count->value){
                if(count == tail){
                    count->next = node;
                    node->prev = count;
                    tail = node;
                    break;
                }
                count = count->next;
            } else{
                if(count == head){
                    count->prev = node;
                    node->next = count;
                    head = node;
                    break;
                } else{
                    node->prev = count->prev;
                    node->next = count;
                    node->prev->next = node;
                    count->prev = node;
                    break;
                }
            }
        }
        length++;

    }
    void erase(int& index){
        if(index >= length){
            return;
        }
        if(length == 1){
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }
        if(index == 0){
            head = head->next;
            head->prev = nullptr;
            length--;
            return;
        }
        if(index == length - 1){
            tail = tail->prev;
            tail->next = nullptr;
            length--;
            return;
        }
        ListNode* count;
        count = head;
        for (int i = 0; i < index; i++) {
            count = count->next;
        }
        count->prev->next = count->next;
        count->next->prev = count->prev;
        length--;
    }
    std::vector <T> search(T& value){
        std::vector <T> res;
        ListNode* count = head;
        for(int i = 0; i < length; i++){
            if(count->value > value){
                break;
            }
            if(count->value == value){
                res.emplace_back(count->value);
            }
            count = count->next;
        }
        return res;
    }
    std::vector <T> search(T& lo, T& hi){
        std:: vector <T> res;
        ListNode* count = head;
        for(int i = 0; i < length; i++){
            if(count->value > hi){
                break;
            }
            if(count->value >= lo){
                res.emplace_back(count->value);
            }
            count = count->next;
        }
        return res;
    }
    void output(){
        if(length == 0){
            std::cout<<"List is empty - nothing to output\n";
        }
        ListNode* count = head;
        for(int i = 0; i < length; i++){
            std::cout<<i<<":\t"<<count->value<<"\n";
            count = count->next;
        }
    }
    void go_round(){
        ListNode* count = head;
        for(int i = 0; i < length; i++){
            count = count->next;
        }
    }

};


#endif //LAB_6_ORDERED_LIST__ORD_LIST_H
