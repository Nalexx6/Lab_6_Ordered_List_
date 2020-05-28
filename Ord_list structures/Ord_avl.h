//
// Created by Win10Pro on 26.05.2020.
//

#ifndef LAB_6_ORDERED_LIST__ORD_AVL_H
#define LAB_6_ORDERED_LIST__ORD_AVL_H

#include "Point.h"
#include <cmath>

template <typename T>
class Ord_avl {

private:

    class Node{

    public:
        T value;
        Node* left;
        Node* right;
        Node* father;
        int height;
        int count;

        Node(T value){
            this->value = value;
            this->right = nullptr;
            this->left = nullptr;
            height = 1;
            count = 1;
        }
    };

public:
    Node* root;

    int get_height(Node* node){
        if(node == nullptr)
            return 0;
        return node->height;
    }
    Node* left_rotation(Node* node){
        Node *y = node->right;
        Node *l_sub = y->left;

        // Perform rotation
        y->left = node;
        node->right = l_sub;

        // Update heights
        node->height = 1 + std::max(height(node->left),
                        height(node->right));
        y->height = 1 + std::max(height(y->left),
                        height(y->right));

        // Return new root
        return y;
    }
    Node* right_rotation(Node* node){

        Node *y = node->left;
        Node *r_sub = y->right;

        // Perform rotation
        y->right = node;
        node->left = r_sub;

        // Update heights
        node->height = 1 + std::max(get_height(node->left),
                        get_height(node->right));
        y->height = 1 + std::max(get_height(y->left),
                        get_height(y->right));

        // Return new root
        return y;
    }

    void push(T& t){
        root = push(root, t);
    }
    Node* push(Node* node, T& t){
        if(node == nullptr)
            return new Node(t);
        if(t < node->value){
            node->left = push(node->left, t);
            node->left->father = node;
        }
        if(t > node->value){
            node->right = push(node->right, t);
            node->right->father = node;
        }
        if(t == node->value){
            node->count++;
        }

        node->height = 1 + std::max(get_height(node->left), get_height(node->right));
        int balance = get_height(node->left) - get_height(node->right);

        if(balance > 1 && t < node->left->value){
            return right_rotation(node);
        }
        if(balance < -1 && t > node->right->value){
            return left_rotation(node);
        }
        if(balance > 1 && t > node->left->value){
            node->left = left_rotation(node->left);
            return right_rotation(node);
        }
        if(balance < -1 && t < node->right->value){
            node->right = right_rotation(node->right);
            return left_rotation(node);
        }
        return node;
    }

    std::vector <T> search(T& value){
        std::vector <T> res;
        search_node(root, res, value);
        return res;
    }
    void search_node(Node* node, std::vector <T>& res, T& value){
        if(node == nullptr){
            return;
        }
        search_node(node->left, res, value);
        if(node->value > value){
            return;
        }
        if(node->value == value){
            for(int i = 0; i < node->count; i++){
                res.emplace_back(node->value);
            }
            return;
        }
        search_node(node->right, res, value);
    }
    std::vector <T> search(T& lo, T hi){
        std::vector <T> res;
        search_node(root, res, lo, hi);
        return res;
    }
    void search_node(Node* node, std::vector <T>& res, T& lo, T& hi){
        if(node == nullptr){
            return;
        }
        search_node(node->left, res, lo, hi);
        if(node->value > hi){
            return;
        }
        if(node->value >= lo){
            for(int i = 0; i < node->count; i++){
                res.emplace_back(node->value);
            }
        }
        search_node(node->right, res, lo, hi);
    }
    void output(int& index, Node* node){
        if(node == nullptr)
            return;
        output(index, node->left);
        for(int i = 0; i < node->count; i++) {
            std::cout<<index<<":\t"<<node->value<<"\t"<<node->father->value<<"\n";
            index++;
        }
        output(index, node->right);
    }
//    void balancing();


};


#endif //LAB_6_ORDERED_LIST__ORD_AVL_H
