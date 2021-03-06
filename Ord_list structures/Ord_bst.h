//
// Created by Win10Pro on 25.05.2020.
//

#ifndef LAB_6_ORDERED_LIST__ORD_BST_H
#define LAB_6_ORDERED_LIST__ORD_BST_H

#include "Point.h"

template <typename T>
class Ord_bst {
private:

    class Node{

    public:
        T value;
        Node* left;
        Node* right;
        Node* father;
        int count;
        int key;

        Node(T value, int key){
            this->value = value;
            this->right = nullptr;
            this->left = nullptr;
            this->key = key;
            count = 1;

        }
    };

public:
    Node* root;
    int size;
    Ord_bst(){
        this->size = 0;
        this->root = nullptr;
    }
    ~Ord_bst() = default;

    void push(T& t){
        size++;
        root = push(root, t, 0);
    }
    Node* push(Node* node, T& t, int key){
        if(node == nullptr)
            return new Node(t, key);
        if(t < node->value){
            node->left = push(node->left, t, 0);
            node->left->father = node;
        }
        if(t > node->value){
            node->right = push(node->right, t, 1);
            node->right->father = node;
        }
        if(t == node->value){
            node->count++;
        }
        return node;
    }
    void delete_node(Node* node){
        if(node->right == nullptr && node->left == nullptr){
            if(node == root){
                root = nullptr;
                delete node;
                return;
            }
            if(node->key == 1){
                node->father->right = nullptr;
                delete node;
            } else{
                node->father->left = nullptr;
                delete node;
            }
            return;
        }
        if(node->right == nullptr && node->left != nullptr){
            if(node == root){
                root = node->left;
                delete node;
                root->father = nullptr;
                return;
            }
            if(node->key == 1){
                node->father->right = node->left;
                node->left->father = node->father;
                node->left->key = 1;
                delete node;
            } else{
                node->father->left = node->left;
                node->left->father = node->father;
                delete node;
            }
            return;
        }
        if(node->right != nullptr && node->left == nullptr){
            if(node == root){
                root = node->right;
                delete node;
                root->father = nullptr;
                return;
            }
            if(node->key == 1){
                node->father->right = node->right;
                node->right->father = node->father;
                delete node;
            } else{
                node->father->left = node->right;
                node->right->father = node->father;
                node->right->key = 0;
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
    void erase(int& index){
        size--;
        int count = 0;
        erase(root, index, count);
    }
    void erase(Node* node, int& index, int& count){
        if(node == nullptr){
//            std::cout<<"dsfsdf\n";
            return;
        }
        erase(node->left, index, count);
        if(count > index){
            return;
        }
        for(int i = 0; i < node->count; i++){
            if(count == index){
//                std::cout<< node->value<<"\n";
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
    void output(){
        int index = 0;
        output(index, root);
    }
    void output(int& index, Node* node){
        if(node == nullptr)
            return;
        output(index, node->left);
        for(int i = 0; i < node->count; i++) {
            std::cout<<index<<":\t"<<node->value<<"\n";
            index++;
        }
        output(index, node->right);
    }
    void go_round(){
        go_round(root);
    }
    void go_round(Node* node){
        if(node == nullptr)
            return;
        go_round(node->left);
        go_round(node->right);
    }





};


#endif //LAB_6_ORDERED_LIST__ORD_BST_H
