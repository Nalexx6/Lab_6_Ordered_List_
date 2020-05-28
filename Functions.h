//
// Created by Win10Pro on 23.05.2020.
//

#ifndef LAB_6_ORDERED_LIST__FUNCTIONS_H
#define LAB_6_ORDERED_LIST__FUNCTIONS_H

#include "Ord_list structures/Ord_list.h"
#include "Ord_list structures/Ord_array.h"
#include "Ord_list structures/Ord_bst.h"
#include "Ord_list structures/Ord_avl.h"
#include "Random.h"

class Functions {

public:
    //Linked list
    static void list_push_N_random(int& N, Ord_list <Point>& ordList);
    static void ord_list_interactive();

    //Array list
    static void array_push_N_random(int& N, Ord_array <Point>& ordArray);
    static void ord_array_interactive();

    //Bst list
    static void bst_push_N_random(int& N, Ord_bst <Point>& ordBst);
    static void ord_bst_interactive();

    //AVL tree list
    static void avl_push_N_random(int& N, Ord_avl <Point>& ordAvl);
    static void ord_avl_interactive();

};


#endif //LAB_6_ORDERED_LIST__FUNCTIONS_H
