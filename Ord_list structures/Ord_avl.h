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

    Ord_avl(){
        root = nullptr;
    }
    ~Ord_avl() = default;

    int get_height(Node* node){
        if(node == nullptr)
            return 0;
        return node->height;
    }
    Node* left_rotation(Node* node){

        Node *x = node->right;
        Node *l_sub = x->left;

         x->left = node;
        node->right = l_sub;

        node->height = 1 + std::max(get_height(node->left),
                        get_height(node->right));
        x->height = 1 + std::max(get_height(x->left),
                        get_height(x->right));

        return x;
    }
    Node* right_rotation(Node* node){

        Node *x = node->left;
        Node *r_sub = x->right;

        x->right = node;
        node->left = r_sub;

        node->height = 1 + std::max(get_height(node->left),
                        get_height(node->right));
        x->height = 1 + std::max(get_height(x->left),
                        get_height(x->right));

        return x;
    }

    void push(T& t){
        root = push(root, t);
    }
    Node* push(Node* node, T& t){
        if(node == nullptr)
            return new Node(t);
//        std::cout<<node->value<<std::endl;
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
            node->left->father = node;
            return right_rotation(node);
        }
        if(balance < -1 && t < node->right->value){
            node->right = right_rotation(node->right);
            node->right->father = node;
            return left_rotation(node);
        }
        return node;
    }

    void delete_node(Node* node){
        if(node->right == nullptr && node->left == nullptr){
            if(node->father->right->value == node->value){
                node->father->right = nullptr;
                delete node;
            } else{
                node->father->left = nullptr;
                delete node;
            }
            return;
        }
        if(node->right == nullptr && node->left != nullptr){
            if(node->father->right->value == node->value){
                node->father->right = node->left;
                node->left->father = node->father;
                delete node;
            } else{
                node->father->left = node->left;
                node->left->father = node->father;
                delete node;
            }
            return;
        }
        if(node->right != nullptr && node->left == nullptr){
            if(node->father->right->value == node->value){
                node->father->right = node->right;
                node->right->father = node->father;
                delete node;
            } else{
                node->father->left = node->right;
                node->right->father = node->father;
                delete node;
            }
            return;
        }
        if(node->right != nullptr && node->left != nullptr){
            Node* temp = node;
            temp = temp->left;
            while(true){
                if(temp->right != nullptr) {
                    temp = temp->right;
                } else
                    break;
            }
            node->value = temp->value;
            node->count = temp->count;
            delete_node(temp);
            return;
        }
    }
    void erase(int& index) {
        int count = 0;
        erase(root, index, count);
        balancing(root);
    }
    void erase(Node* node, int& index, int& count){
        if(node == nullptr){
            return;
        }
        erase(node->left, index, count);
        if(count > index){
            return;
        }
        for(int i = 0; i < node->count; i++){
            if(count == index){
                if(node->count > 1){
                    node->count--;
                } else{

                    delete_node(node);
                }
                count++;
                return;
            }
            count++;
        }
        erase(node->right, index, count);

    }
    void balancing(Node* node){
        if(node == nullptr)
            return;
        balancing(node->left);
        balancing(node->right);
        node->height = 1 + std::max(get_height(node->left), get_height(node->right));
        int balance = get_height(node->left) - get_height(node->right);

        if(balance > 1){
            right_rotation(node);
        }
        if(balance < -1){
            left_rotation(node);
        }
        if(balance > 1){
            node->left = left_rotation(node->left);
            node->left->father = node;
        }
        if(balance < -1){
            node->right = right_rotation(node->right);
            node->right->father = node;
        }
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
            std::cout<<index<<":\t"<<node->value<<"\t";
            if(node != this->root)
                std::cout<<"||\t"<<node->father->value;
            std::cout<<"\n";
            index++;
        }
        output(index, node->right);
    }


};


#endif //LAB_6_ORDERED_LIST__ORD_AVL_H
