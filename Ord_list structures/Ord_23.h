//
// Created by Win10Pro on 28.05.2020.
//

#ifndef LAB_6_ORDERED_LIST__ORD_23_H
#define LAB_6_ORDERED_LIST__ORD_23_H

#include "Point.h"
template  <typename T>
class Ord_23 {

private:

    class Node{
    public:
        T values[2];
        Node* left;
        Node* middle;
        Node* right;
        Node* father;
        int key;
        bool three_node;

        Node(T& value, int key){
            values[0] = value;
            left = middle = right = father = nullptr;
            three_node = false;
            this->key = key;
        }

    };

public:

    Node* root;

    Ord_23(){
        root = nullptr;
    }
    ~Ord_23() = default;

    void push(T& t){
        if(root == nullptr){
            root = new Node(t, 0);
        }
        else{
            root = push(t, root, 0);
        }
    }
    void two_insert(Node* node, T& t){
        node->values[1] = t;
        node->three_node = true;
    }
    void three_root_insert(Node* node, T& t){
        if(node->values[0] > t){
            node->left = new Node(t, 0);
            node->middle = new Node(node->values[1], 1);
            node->three_node = false;
            return;
        }
        if(node->values[0] <= t && node->values[1] > t){
            node->left = new Node(node->values[0], 0);
            node->middle = new Node(node->values[1], 1);
            node->three_node = false;
            node->values[0] = t;
            return;
        }
        if(node->values[1] <= t){
            node->left = new Node(node->values[0], 0);
            node->middle = new Node(t, 1);
            node->three_node = false;
            node->values[0] = node->values[1];
            return;
        }
    }
    void three_two_insert(Node* node, T& t){
        Node* father = node->father;
        if(node->key == 0){
            if(node->values[0] > t){
                father->right = father->middle;
                father->right->key = 2;
                father->middle = new Node(node->values[1], 1);
                father->values[1] = father->values[0];
                father->values[0] = node->values[0];
                father->three_node = true;
                node->values[0] = t;
                node->three_node = false;
                return;
            }
            if(node->values[0] <= t && node->values[1] > t){
                father->right = father->middle;
                father->right->key = 2;
                father->middle = new Node(node->values[1], 1);
                father->values[1] = father->values[0];
                father->values[0] = t;
                father->three_node = true;
//                node->values[0] = t;
                node->three_node = false;
                return;
            }
            if(node->values[1] <= t){
                father->right = father->middle;
                father->right->key = 2;
                father->middle = new Node(t, 1);
                father->values[1] = father->values[0];
                father->values[0] = node->values[1];
                father->three_node = true;
//                node->values[0] = t;
                node->three_node = false;
                return;
            }
        }
        if(node->key == 1){
            if(node->values[0] > t){
                father->right = father->middle;
                father->right->key = 2;
                father->middle = new Node(t, 1);
                father->values[1] = node->values[0];
//                father->values[0] = node->values[0];
                father->three_node = true;
                node->values[0] = node->values[1];
                node->three_node = false;
                return;
            }
            if(node->values[0] <= t && node->values[1] > t){
                father->right = father->middle;
                father->right->key = 2;
                father->middle = new Node(node->values[0], 1);
                father->values[1] = t;
//                father->values[0] = t;
                father->three_node = true;
//                node->values[0] = t;
                node->three_node = false;
                return;
            }
            if(node->values[1] <= t){
                father->right = father->middle;
                father->right->key = 2;
                father->middle = new Node(node->values[0], 1);
                father->values[1] = node->values[1];
//                father->values[0] = node->values[1];
                father->three_node = true;
//                node->values[0] = t;
                node->three_node = false;
                return;
            }
        }
    }
    void three_three_insert(Node* node, T& t){
        Node* father = node->father;
        if(node->key == 0){
            if(node->values[0] > t){
                node->left = new Node(t, 0);
                node->middle = new Node(node->values[1], 1);
                node->three_node = false;
                Node* temp = new Node(father->values[1], 1);
                temp->left = father->middle;
                temp->middle = father->right;
                father->right = nullptr;
                father->middle = temp;
                father->three_node = false;
                return;
            }
            if(node->values[0] <= t && node->values[1] > t){
                node->left = new Node(node->values[0], 0);
                node->middle = new Node(node->values[1], 1);
                node->values[0] = t;
                node->three_node = false;
                Node* temp = new Node(father->values[1], 1);
                temp->left = father->middle;
                temp->middle = father->right;
                father->right = nullptr;
                father->middle = temp;
                father->three_node = false;
                return;
            }
            if(node->values[1] <= t) {
                node->left = new Node(node->values[0], 0);
                node->middle = new Node(t, 1);
                node->values[0] = node->values[1];
                node->three_node = false;
                Node *temp = new Node(father->values[1], 1);
                temp->left = father->middle;
                temp->middle = father->right;
                father->right = nullptr;
                father->middle = temp;
                father->three_node = false;
                return;
            }
        }
        if(node->key == 1){
            if(node->values[0] > t){
                Node* l_temp = new Node(father->values[0], 0);
                l_temp->left = father->left;
                l_temp->middle = new Node(t, 1);
                Node* m_temp = new Node(father->values[1], 0);
                m_temp->left = new Node(node->values[1], 0);
                m_temp->middle = father->right;
                father->right = nullptr;
                father->values[0] = node->values[0];
                father->left = l_temp;
                father->middle = m_temp;
                return;
            }
            if(node->values[0] <= t && node->values[1] > t){
                Node* l_temp = new Node(father->values[0], 0);
                l_temp->left = father->left;
                l_temp->middle = new Node(node->values[0], 1);
                Node* m_temp = new Node(father->values[1], 0);
                m_temp->left = new Node(node->values[1], 0);
                m_temp->middle = father->right;
                father->right = nullptr;
                father->values[0] = t;
                father->left = l_temp;
                father->middle = m_temp;
                return;
            }
            if(node->values[1] <= t){
                Node* l_temp = new Node(father->values[0], 0);
                l_temp->left = father->left;
                l_temp->middle = new Node(node->values[0], 1);
                Node* m_temp = new Node(father->values[1], 0);
                m_temp->left = new Node(t, 0);
                m_temp->middle = father->right;
                father->right = nullptr;
                father->values[0] = node->values[1];
                father->left = l_temp;
                father->middle = m_temp;
                return;
            }
        }
        if(node->key == 2) {
            if (node->values[0] > t) {
                node->left = new Node(t, 0);
                node->middle = new Node(node->values[1], 1);
                node->three_node = false;
                Node *temp = new Node(father->values[0], 0);
                temp->left = father->left;
                temp->middle = father->middle;
                father->middle = node;
                father->left = temp;
                father->values[0] = father->values[1];
                father->three_node = false;
                return;
            }
            if (node->values[0] <= t && node->values[1] > t) {
                node->left = new Node(node->values[0], 0);
                node->middle = new Node(node->values[1], 1);
                node->values[0] = t;
                node->three_node = false;
                Node *temp = new Node(father->values[0], 0);
                temp->left = father->left;
                temp->middle = father->middle;
                father->middle = node;
                father->left = temp;
                father->values[0] = father->values[1];
                father->three_node = false;
                return;
            }
            if (node->values[1] <= t) {
                node->left = new Node(node->values[0], 0);
                node->middle = new Node(t, 1);
                node->values[0] = node->values[1];
                node->three_node = false;
                Node *temp = new Node(father->values[0], 0);
                temp->left = father->left;
                temp->middle = father->middle;
                father->middle = node;
                father->left = temp;
                father->values[0] = father->values[1];
                father->three_node = false;
                return;
            }
        }
    }
    Node* push(T& t, Node* node, int key){

        if(node->left == nullptr && !node->three_node){
            two_insert(node, t);
            return;
        }
        if(node->left == nullptr && node->three_node && node == root){
            three_root_insert(node, t);
            return;
        }
        if(node->left == nullptr && node->three_node && !node->father->three_node){
            three_two_insert(node, t);
            return;
        }
        if(node->left == nullptr && node->three_node && node->father->three_node){
            three_three_insert(node, t);
            return;
        }
        if(node->values[0] > t){
            node->left = push(t, node->left, 0);
            node->left->father = node;
        }
        if((node->values[0] <= t && !node->three_node) || (node->values[0] <= t && node->three_node && node->values[1] > t)){
            node->middle = push(t, node->middle, 1);
            node->middle->father = node;
        }
        if(node->three_node && node->values[1] <= t){
            node->right = push(t, node->right, 2);
            node->right->father = node;
        }
    }

    void erase(int& index){

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
        if(node->values[0] > value){
            return;
        }
        if(node->values[0] == value){
            res.emplace_back(node->values[0]);
        }
        search_node(node->middle, res, value);
        if(node->three_node){
            if(node->values[1] > value){
                return;
            }
            if(node->values[1] == value){
                res.emplace_back(node->values[1]);
            }
            search_node(node->right, res, value);
        }
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
        if(node->values[0] > hi){
            return;
        }
        if(node->values[0] >= lo){
            res.emplace_back(node->values[0]);
        }
        search_node(node->middle, res, lo, hi);
        if(node->three_node){
            if(node->values[1] > hi){
                return;
            }
            if(node->values[1] >= lo){
                res.emplace_back(node->values[1]);
            }
            search_node(node->right, res, lo, hi);
        }
    }
    void output(int& index, Node* node){
        if(node == nullptr)
            return;
        output(index, node->left);
            std::cout<<index<<":\t"<<node->values[0]<<"\t";
            if(node != this->root)
                std::cout<<"||\t"<<node->father->values[0];
            std::cout<<"\n";
            index++;
        output(index, node->middle);
        if(node->three_node){
            std::cout<<index<<":\t"<<node->values[1]<<"\t";
            if(node != this->root)
                std::cout<<"||\t"<<node->father->values[1];
            std::cout<<"\n";
            index++;
            output(index, node->right);
        }
    }


};


#endif //LAB_6_ORDERED_LIST__ORD_23_H
