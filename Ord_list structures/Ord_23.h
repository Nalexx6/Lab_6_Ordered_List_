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
        bool hole;

        Node(T& value, int key){
            values[0] = value;
            left = middle = right = father = nullptr;
            three_node = false;
            this->key = key;
            hole = false;
        }

    };

public:

    Node* root;
    int size;
    Ord_23(){
        this->size = 0;
        root = nullptr;
    }
    ~Ord_23() = default;

    void push(T& t){
        if(root == nullptr){
            root = new Node(t, 0);
        }
        else{
            push(t, root, 0);
        }
        size++;
    }
    void two_insert(Node* node, T& t){
        if(node->values[0] > t){
            node->values[1] = node->values[0];
            node->values[0] = t;
        } else {
            node->values[1] = t;
        }
        node->three_node = true;
    }
    void three_root_insert(Node* node, T& t){
        if(node->values[0] > t){
            node->left = new Node(t, 0);
            node->left->father = node;

            node->middle = new Node(node->values[1], 1);
            node->middle->father = node;

            node->three_node = false;

            return;
        }
        if(node->values[0] <= t && node->values[1] > t){
            node->left = new Node(node->values[0], 0);
            node->left->father = node;

            node->middle = new Node(node->values[1], 1);
            node->middle->father = node;

            node->three_node = false;
            node->values[0] = t;

            return;
        }
        if(node->values[1] <= t){
            node->left = new Node(node->values[0], 0);
            node->left->father = node;

            node->middle = new Node(t, 1);
            node->middle->father = node;

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
                father->middle->father = father;

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
                father->middle->father = father;

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
                father->middle->father = father;

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
                father->middle->father = father;

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
                father->middle->father = father;

                father->values[1] = t;
//                father->values[0] = t;
                father->three_node = true;

//                node->values[0] = t;
                node->values[0] = node->values[1];
                node->three_node = false;

                return;
            }
            if(node->values[1] <= t){
                father->right = node;
                node->key = 2;

                father->middle = new Node(node->values[0], 1);
                father->middle->father = father;

                father->values[1] = node->values[1];
//                father->values[0] = node->values[1];
                father->three_node = true;

                node->values[0] = t;
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
                node->left->father = node;
                node->middle = new Node(node->values[1], 1);
                node->middle->father = node;
                node->three_node = false;

                Node* temp = new Node(father->values[1], 1);
                temp->left = father->middle;
                temp->left->father = temp;
                temp->middle = father->right;
                temp->middle->father = temp;

                father->right = nullptr;
                father->middle = temp;
                temp->father = father;
                father->three_node = false;

                return;
            }
            if(node->values[0] <= t && node->values[1] > t){
                node->left = new Node(node->values[0], 0);
                node->left->father = node;
                node->middle = new Node(node->values[1], 1);
                node->middle->father = node;
                node->values[0] = t;
                node->three_node = false;

                Node* temp = new Node(father->values[1], 1);
                temp->left = father->middle;
                temp->left->father = temp;
                temp->middle = father->right;
                temp->middle->father = temp;

                father->right = nullptr;
                father->middle = temp;
                temp->father = father;
                father->three_node = false;

                return;
            }
            if(node->values[1] <= t) {
                node->left = new Node(node->values[0], 0);
                node->left->father = node;
                node->middle = new Node(t, 1);
                node->middle->father = node;
                node->values[0] = node->values[1];
                node->three_node = false;

                Node *temp = new Node(father->values[1], 1);
                temp->left = father->middle;
                temp->left->father = temp;
                temp->middle = father->right;
                temp->middle->father = temp;
                father->right = nullptr;
                father->middle = temp;
                temp->father = father;
                father->three_node = false;
                return;
            }
        }
        if(node->key == 1){
            if(node->values[0] > t){
                Node* l_temp = new Node(father->values[0], 0);
                l_temp->left = father->left;
                l_temp->left->father = l_temp;
                l_temp->middle = new Node(t, 1);
                l_temp->middle->father = l_temp;

                Node* m_temp = new Node(father->values[1], 0);
                m_temp->left = new Node(node->values[1], 0);
                m_temp->left->father = m_temp;
                m_temp->middle = father->right;
                m_temp->middle->father = m_temp;

                father->right = nullptr;
                father->values[0] = node->values[0];

                father->left = l_temp;
                l_temp->father = father;
                father->middle = m_temp;
                m_temp->father = father;
                father->three_node = false;

                return;

            }
            if(node->values[0] <= t && node->values[1] > t){
                Node* l_temp = new Node(father->values[0], 0);
                l_temp->left = father->left;
                l_temp->left->father = l_temp;
                l_temp->middle = new Node(node->values[0], 1);
                l_temp->middle->father = l_temp;

                Node* m_temp = new Node(father->values[1], 0);
                m_temp->left = new Node(node->values[1], 0);
                m_temp->left->father = m_temp;
                m_temp->middle = father->right;
                m_temp->middle->father = m_temp;

                father->right = nullptr;
                father->values[0] = t;

                father->left = l_temp;
                l_temp->father = father;
                father->middle = m_temp;
                m_temp->father = father;
                father->three_node = false;

                return;
            }
            if(node->values[1] <= t){
                Node* l_temp = new Node(father->values[0], 0);
                l_temp->left = father->left;
                l_temp->left->father = l_temp;
                l_temp->middle = new Node(node->values[0], 1);
                l_temp->middle->father = l_temp;

                Node* m_temp = new Node(father->values[1], 0);
                m_temp->left = new Node(t, 0);
                m_temp->left->father = m_temp;
                m_temp->middle = father->right;
                m_temp->middle->father = m_temp;

                father->right = nullptr;
                father->values[0] = node->values[1];

                father->left = l_temp;
                l_temp->father = l_temp;
                father->middle = m_temp;
                m_temp->father = m_temp;
                father->three_node = false;

                return;
            }
        }
        if(node->key == 2) {
            if (node->values[0] > t) {
                node->left = new Node(t, 0);
                node->left->father = node;
                node->middle = new Node(node->values[1], 1);
                node->middle->father = node;
                node->three_node = false;

                Node *temp = new Node(father->values[0], 0);
                temp->left = father->left;
                temp->left->father = temp;
                temp->middle = father->middle;
                temp->middle->father = temp;

                father->middle = node;
                father->right = nullptr;
                father->left = temp;
                temp->father = father;
                father->values[0] = father->values[1];
                father->three_node = false;

                return;
            }
            if (node->values[0] <= t && node->values[1] > t) {
                node->left = new Node(node->values[0], 0);
                node->left->father = node;
                node->middle = new Node(node->values[1], 1);
                node->middle->father = node;
                node->values[0] = t;
                node->three_node = false;

                Node *temp = new Node(father->values[0], 0);
                temp->left = father->left;
                temp->left->father = temp;
                temp->middle = father->middle;
                temp->middle->father = temp;

                father->middle = node;
                father->right = nullptr;
                father->left = temp;
                temp->father = father;
                father->values[0] = father->values[1];
                father->three_node = false;

                return;
            }
            if (node->values[1] <= t) {
                node->left = new Node(node->values[0], 0);
                node->left->father = node;
                node->middle = new Node(t, 1);
                node->middle->father = node;
                node->values[0] = node->values[1];
                node->three_node = false;

                Node *temp = new Node(father->values[0], 0);
                temp->left = father->left;
                temp->left->father = temp;
                temp->middle = father->middle;
                temp->middle->father = temp;

                father->middle = node;
                father->right = node;
                father->left = temp;
                temp->father = father;
                father->values[0] = father->values[1];
                father->three_node = false;

                return;
            }
        }
    }
    void push(T& t, Node* node, int key){

        if(node->left == nullptr && !node->three_node){
            two_insert(node, t);
//            std::cout<<"1\n";
            return;
        }
        if(node->left == nullptr && node->three_node && node == root){
            three_root_insert(node, t);
//            std::cout<<"2\n";
            return;
        }
        if(node->left == nullptr && node->three_node && !node->father->three_node){
            three_two_insert(node, t);
//            std::cout<<"3\n";
            return;
        }
        if(node->left == nullptr && node->three_node && node->father->three_node){
            three_three_insert(node, t);
//            std::cout<<"4\n";
            return;
        }
        if(node->values[0] > t){
            push(t, node->left, 0);
//            node->left->father = node;
            return;
        }
        if((node->values[0] <= t && !node->three_node) || (node->values[0] <= t && node->three_node && node->values[1] > t)){
            push(t, node->middle, 1);
//            node->middle->father = node;
            return;
        }
        if(node->three_node && node->values[1] <= t){
            push(t, node->right, 2);
//            node->right->father = node;
            return;
        }
    }

    void erase(int& index){
        int count = 0;
        size--;
        erase(root, index, count);
    }
    void delete_hole(Node* node, int key){
        if(node == root){
            root = node->middle;
            root->father = nullptr;
            root->key = 0;
            return;
        }
        if (!node->father->three_node) {
            if (node->key == 0 && !node->father->middle->three_node) {
                node->father->hole = true;
                node->father->middle->values[1] = node->father->middle->values[0];
                node->father->middle->values[0] = node->father->values[0];
                node->father->middle->right = node->father->middle->middle;
                if(node->father->middle->right)
                    node->father->middle->right->key = 2;
                node->father->middle->middle = node->father->middle->left;
                if(node->father->middle->middle)
                    node->father->middle->middle->key = 1;
                node->father->middle->left = node->middle;
                if(node->father->middle->left)
                    node->father->middle->left->key = 0;
                if(node->father->middle->left)
                    node->father->middle->left->father = node->father->middle;
                node->father->left = nullptr;
                node->father->middle->three_node = true;
                delete_hole(node->father, key);
                return;
            }
            if (node->key == 0 && node->father->middle->three_node) {
                node->values[0] = node->father->values[0];
                node->father->values[0] = node->father->middle->values[0];
                node->father->middle->values[0] = node->father->middle->values[1];
                node->left = node->middle;
                if(node->left)
                    node->left->key = 0;
                node->middle = node->father->middle->left;
                if(node->middle)
                    node->middle->key = 1;
                if(node->middle)
                    node->middle->father = node;
                node->father->middle->left = node->father->middle->middle;
                if(node->father->middle->left)
                    node->father->middle->left->key = 0;
                node->father->middle->middle = node->father->middle->right;
                if(node->father->middle->middle)
                    node->father->middle->middle->key = 1;
                node->father->middle->three_node = false;
                node->hole = false;
                return;
            }
            if (node->key == 1 && !node->father->left->three_node) {
                node->father->hole = true;
                node->values[1] = node->father->values[0];
                node->values[0] = node->father->left->values[0];
                node->right = node->middle;
                if(node->right)
                    node->right->key = 2;
                node->middle = node->father->left->middle;
                if(node->middle)
                    node->middle->key = 1;
                if(node->middle)
                    node->middle->father = node;
                node->left = node->father->left->left;
                if(node->left)
                    node->left->key = 0;
                if(node->left)
                    node->left->father = node;
                node->father->left = nullptr;
                node->three_node = true;
                node->hole = false;
                delete_hole(node->father, key);
                return;
            }
            if (node->key == 1 && node->father->left->three_node) {
                node->values[0] = node->father->values[0];
                node->father->values[0] = node->father->left->values[1];
                node->left = node->father->left->right;
                if(node->left)
                    node->left->key = 0;
                if(node->left)
                    node->left->father = node;
                node->father->left->three_node = false;
                node->hole = false;
                return;
            }
        }
        if (node->father->three_node) {
            if (node->key == 0 && !node->father->middle->three_node) {
                node->values[0] = node->father->values[0];
                node->values[1] = node->father->middle->values[0];
                node->three_node = true;
                node->father->values[0] = node->father->values[1];
                node->left = node->middle;
                if(node->left)
                    node->left->key = 0;
                node->middle = node->father->middle->left;
                if(node->middle)
                    node->middle->key = 1;
                if(node->middle)
                    node->middle->father = node;
                node->right = node->father->middle->middle;
                if(node->right)
                    node->right->key = 2;
                if(node->right)
                    node->right->father = node;
                node->father->middle = node->father->right;
                if(node->father->middle)
                    node->father->middle->key = 1;
                node->father->three_node = false;
                node->hole = false;
                return;
            }
            if (node->key == 0 && node->father->middle->three_node) {
                node->values[0] = node->father->values[0];
                node->father->values[0] = node->father->middle->values[0];
                node->father->middle->values[0] = node->father->middle->values[1];
                node->left = node->middle;
                if(node->left)
                    node->left->key = 0;
                node->middle = node->father->middle->left;
                if(node->middle)
                    node->middle->key = 1;
                if(node->middle)
                    node->middle->father = node;
                node->father->middle->left = node->father->middle->middle;
                if(node->father->middle->left)
                    node->father->middle->left->key = 0;
                node->father->middle->middle = node->father->middle->right;
                if(node->father->middle->middle)
                    node->father->middle->middle->key = 1;
                node->father->middle->three_node = false;
                node->hole = false;
                return;
            }
            if (node->key == 1 && !node->father->left->three_node) {
                node->father->left->values[1] = node->father->values[0];
                node->father->left->three_node = true;
                node->father->values[0] = node->father->values[1];
                node->father->left->right = node->middle;
                if(node->father->left->right)
                    node->father->left->right->key = 2;
                if(node->middle)
                    node->middle->father = node->father->left;
                node->father->middle = node->father->right;
                if(node->father->middle)
                    node->father->middle->key = 1;
                node->father->three_node = false;
                node->hole = false;
                return;
            }
            if (node->key == 1 && node->father->left->three_node) {
                node->values[0] = node->father->values[0];
                node->father->values[0] = node->father->left->values[1];
                node->left = node->father->left->right;
                if(node->left)
                    node->left->key = 0;
                if(node->left)
                    node->left->father = node;
                node->father->left->three_node = false;
                node->hole = false;
                return;
            }
            if (node->key == 2 && !node->father->middle->three_node) {
                node->father->middle->values[1] = node->father->values[1];
                node->father->middle->three_node = true;
                node->father->middle->right = node->middle;
                if(node->middle) {
                    node->father->middle->right->key = 2;
                    node->middle->father = node->father->middle;
                }
                node->father->three_node = false;
                node->hole = false;
                return;
            }
            if (node->key == 2 && node->father->middle->three_node) {
                node->values[0] = node->father->values[1];
                node->father->values[1] = node->father->middle->values[1];
                node->left = node->father->middle->right;
                if(node->left)
                    node->left->key = 0;
                if(node->left)
                    node->left->father = node;
                node->father->middle->three_node = false;
                node->hole = false;
                return;
            }
        }
    }
    void delete_node(Node* node, int key) {
        if(node->left == nullptr && node->three_node) {
            if (key == 0) {
                node->values[0] = node->values[1];
                node->three_node = false;
            } else {
                node->three_node = false;
            }
            return;
        }
        if(node->left == nullptr && !node->three_node){
            if(node == root) {
                root = nullptr;
                return;
            }
            node->hole = true;
//            std::cout<<"fgfdgfd"<<std::endl;
            delete_hole(node, key);
            return;
        }
        if(node->left != nullptr && !node->three_node){
            Node* temp = node;
            temp = temp->left;
            while(true){
                if(!temp->three_node && temp->middle != nullptr) {
                    temp = temp->middle;
                } else if(temp->three_node && temp->right != nullptr){
                    temp = temp->right;
                } else
                    break;
            }
            if(!temp->three_node) {
                node->values[0] = temp->values[0];
                delete_node(temp, 0);
            } else {
                node->values[0] = temp->values[1];
                delete_node(temp, 1);
            }
            return;
        }
        if(node->left != nullptr && node->three_node){
            if(key == 0) {
                Node *temp = node;
                temp = temp->left;
                while (true) {
                    if (!temp->three_node && temp->middle != nullptr) {
                        temp = temp->middle;
                    } else if (temp->three_node && temp->right != nullptr) {
                        temp = temp->right;
                    } else
                        break;
                }
                if (!temp->three_node) {
                    node->values[0] = temp->values[0];
                    delete_node(temp, 0);
                } else {
                    node->values[0] = temp->values[1];
                    delete_node(temp, 1);
                }
                return;
            }
            if(key == 1){
                Node *temp = node;
                temp = temp->middle;
                while (true) {
                    if (!temp->three_node && temp->middle != nullptr) {
                        temp = temp->middle;
                    } else if (temp->three_node && temp->right != nullptr) {
                        temp = temp->right;
                    } else
                        break;
                }
                if (!temp->three_node) {
                    node->values[1] = temp->values[0];
                    delete_node(temp, 0);
                } else {
                    node->values[1] = temp->values[1];
                    delete_node(temp, 1);
                }
                return;
            }

        }
    }
    void erase(Node* node, int& index, int& count){
        if(node == nullptr){
            return;
        }
        erase(node->left, index, count);
        if(count > index){
            return;
        }
        if(count == index){
            delete_node(node, 0);
            count++;
            return;
        }
        count++;
        erase(node->middle, index, count);
        if(node->three_node){
            if(count > index){
                return;
            }
            if(count == index){
                delete_node(node, 1);
                count++;
                return;
            }
            count++;
            erase(node->right, index, count);
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
    void output(){
        int index = 0;
        output(index, root);
    }
    void output(int& index, Node* node){
        if(node == nullptr)
            return;
        output(index, node->left);
//        std::cout<<"ffdffd\n";
        std::cout<<index<<":\t"<<node->values[0]<<"\t";
        if(node != this->root)
            std::cout<<"||\t"<<node->father->values[0];
        std::cout<<"\n";
        index++;
        output(index, node->middle);
        if(node->three_node){
            std::cout<<index<<":\t"<<node->values[1]<<"\t";
            if(node != this->root)
                std::cout<<"||\t"<<node->father->values[0];
            std::cout<<"\n";
            index++;
            output(index, node->right);
        }
    }
    void go_round(){
        go_round(root);
    }
    void go_round(Node* node){
        if(node == nullptr)
            return;
        go_round(node->left);
//        std::cout<<"ffdffd\n";

        go_round(node->middle);
        if(node->three_node){
            go_round(node->right);
        }
    }


};


#endif //LAB_6_ORDERED_LIST__ORD_23_H
